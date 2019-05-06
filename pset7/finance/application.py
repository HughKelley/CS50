
import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.exceptions import default_exceptions
from werkzeug.security import check_password_hash, generate_password_hash
import datetime

from helpers import apology, login_required, lookup, usd

# Ensure environment variable is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Ensure responses aren't cached


@app.after_request
def after_request(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_FILE_DIR"] = mkdtemp()
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""

# get username
    current_id = session["user_id"]
    username = db.execute("SELECT username FROM users WHERE id = :id", id=current_id)
    username = username[0]['username']

# lookup user assets
    total_acc_val = 0
    cash_balance = db.execute("SELECT cash  FROM users WHERE id = :id", id=current_id)
    user_assets = db.execute("SELECT ticker, shares FROM assets WHERE username = :user", user=username)
    # print("user_assets", user_assets)
    counter = 0
    all_prices = []
    for line in user_assets:
        price = lookup(user_assets[counter]['ticker'])
        all_prices.append(price)
        user_assets[counter]['price'] = price['price']
        user_assets[counter]['total'] = usd(float(user_assets[counter]['shares']) * float(user_assets[counter]['price']))
        total_acc_val = total_acc_val + (float(user_assets[counter]['shares']) * float(user_assets[counter]['price']))
        user_assets[counter]['price'] = usd(user_assets[counter]['price'])
        counter = counter + 1

    total_acc_val = usd(total_acc_val + float(cash_balance[0]['cash']))

    return render_template("index.html", assets=user_assets, cash=usd(cash_balance[0]['cash']), total=total_acc_val), 200

    # return render_template("quote.html", name = pxsy['symbol'], price = pxsy['price'])

    # return render_template("index.html"), 200

    # html table with users portfolio
    # stocks owned
    # shares owned for each stock
    # current price for each stock
    # total value of each holding
    # users current cash balance
    # grand total of cash and stocks total value

    # use jinja for loop

    # {% for stock in stocks %}
    #     <p> {{stock.name}}</p>
    #     {%endfor%}


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""

    if request.method == "GET":
        return render_template("buy.html"), 200

    if request.method == "POST":

        # Ensure shares was submitted
        if not request.form.get("symbol"):
            return apology("must provide ticker", 400)
        else:
            ticker = request.form.get("symbol")

        if not request.form.get("shares"):
            return apology("must provide number of shares")
        else:
            number = request.form.get("shares")

        try:
            val = int(number)
            if val < 0:
                return apology("Sorry, input must be a positive integer, try again")

        except ValueError:
            return apology("That's not a valid number of shares!")

        # return render_template("quote.html", name = pxsy['symbol'], price = pxsy['price'])

        # look up cash balance

        current_id = session["user_id"]

        username = db.execute("SELECT username FROM users WHERE id = :id", id=current_id)
        username = username[0]['username']

        cash_balance = db.execute("SELECT cash  FROM users WHERE id = :id", id=current_id)
        balance = cash_balance[0]
        cash_balance = float(balance['cash'])

        lkp = lookup(ticker)

        if lkp == None:
            return apology("upon lookup, ticker does not exist")

        price = float(lkp['price'])
        total_cost = price * val

        if total_cost >= cash_balance:
            return apology("insufficient funds for purchase")

        # get date and time
        trans_date = datetime.date.today()
        trans_time = datetime.time()

        new_cash_balance = cash_balance - float(total_cost)
        update_cash = db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash=new_cash_balance, id=current_id)

        # check update

        cash_balance = db.execute("SELECT cash  FROM users WHERE id = :id", id=current_id)

        # add transaction to that table
        # idnum ticker shares price timestamp
        # INSERT INTO <table> (<columns>) VALUES (<values>)
        # e.g. INSERT INTO users (username, password, fullname) VALUES ('newman', 'USMAIL', 'Newman')
        # id number is primary key and can be configured to autoincrement

        transaction = db.execute("INSERT INTO transactions (username, buysell, ticker, shares, price, date, time) VALUES (:username, :buysell, :ticker, :shares, :price, :date, :time)",
                                 username=username, buysell="buy", ticker=ticker, shares=val, price=price, date=trans_date, time=trans_time)

        # e.g. SELECT * FROM moms WHERE username = 'jerry'

        assets = db.execute("SELECT * FROM assets WHERE username = :username AND ticker = :ticker",
                            username=username, ticker=ticker)

        ##############################################
        if not assets:
            assets = db.execute("INSERT INTO assets (username, ticker, shares) VALUES (:username, :ticker, :shares)",
                                username=username, ticker=ticker, shares=val)
        else:
            shares = int(number) + int(assets[0]['shares'])
            add_asset = db.execute("UPDATE assets SET shares = :shares WHERE idnum = :id AND ticker = :ticker",
                                   shares=shares, id=assets[0]['idnum'], ticker=ticker)

        ##################################################

        # INSERT OR IGNORE INTO my_table (name,age) VALUES('Karen',34)
        # UPDATE my_table SET age = 34 WHERE name='Karen'

        # shares name price

        return render_template("bought.html", shares=val, name=lkp["symbol"], price=usd(lkp['price']), cost=usd(total_cost), cash=usd(new_cash_balance))

# for more shares of a stock that is already owned: insert into

# new sql table
#     who bought what at what price and when?
#     use appropriate SQLite types
#     define unique indexs on any fields that should be unique
#     define (non-unique) indexes on any fields that you may search
#   update cash balance with UPDATE users SET cash - 50 WHERE id = 1


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""

    current_id = session["user_id"]
    username = db.execute("SELECT username FROM users WHERE id = :id", id=current_id)
    username = username[0]['username']

    transaction_history = db.execute(
        "SELECT ticker, buysell, shares, price, date, time FROM transactions WHERE username = :username", username=username)

    return render_template("history.html", transactions=transaction_history)

    # stock bought or sold
    # stock symbol
    # purchase or sale price
    # number of shares sold
    # date and time of transaction
    # total value of transaction


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in

        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/passchange", methods=["GET", "POST"])
@login_required
def passchange():

    if request.method == "GET":
        return render_template("passchange.html"), 200

    if request.method == "POST":
        # check all the forms are filled out

        if request.form.get("username") and request.form.get("password") and request.form.get("new_password") and request.form.get("confirm_password"):

            hash = generate_password_hash(request.form.get("password"))
            current_id = session["user_id"]

            actual_current = db.execute("SELECT hash FROM users WHERE id = :idnum", idnum=current_id)

            # Query database for username
            rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

            # Ensure username exists and password is correct
            if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
                return apology("invalid username and/or password", 400)
            else:

                new_password = request.form.get("new_password")
                confirm_password = request.form.get("confirm_password")

                new_hash = generate_password_hash(request.form.get("new_password"))

                if new_password == confirm_password:

                    updater = db.execute("UPDATE users SET hash = :hash WHERE id = :id", hash=new_hash, id=current_id)
                    return render_template("passchanged.html"), 200
                else:
                    return apology("passwords must match", 400)

        return apology("password change failed", 400)
        # update_cash = db.execute("UPDATE users SET cash = :cash WHERE id = :id",
        # check the passsword is correct

        # hash both passwords entered.

        # compare hashes

        # if they are the same update sql database with new password hash.

        # return render_template of password changed.


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Ensure password was submitted
        elif not request.form.get("confirmation"):
            return apology("must confirm password", 400)

        passone = request.form.get("password")
        passtwo = request.form.get("confirmation")

        if not passone == passtwo:
            return apology("passwords must match", 400)

        # check if username already exists

        exists = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        if not exists == []:
            return apology("username already exists", 400)

        # Hash password

        hash = generate_password_hash(request.form.get("password"))

        input = db.execute("INSERT INTO users (username, hash) VALUES (:username, :hash)",
                           username=request.form.get("username"), hash=hash)
        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = :username", username=request.form.get("username"))

        # check if username already exists

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in

        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/"), 200

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("register.html"), 200


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():

    # maybe if get return blank page if post return page filled out.

    if request.method == "GET":

        """Show quote for a stock"""
        return render_template("quote.html")
    else:

        if not request.form.get("symbol"):
            return apology("must provide symbol", 400)

        else:
            ticker = request.form.get("symbol")

        pxsy = lookup(ticker)

        if pxsy == None:
            return apology("symbol not recognized", 400)
        else:
            return render_template("quote.html", name=pxsy['symbol'], price=usd(pxsy['price']))

        # INSERT INTO <table> (<columns>) VALUES (<values>)
        # e.g. INSERT INTO users (username, password, fullname) VALUES ('newman', 'USMAIL', 'Newman')
        # id number is primary key and can be configured to autoincrement

        # SELECT <columns> FROM <table> WHERE <condition> ORDER BY <column>
        # WHERE and ORDER BY are optional
        # e.g. SELECT idnum, fullname FROM users
        # e.g. SELECT * FROM moms WHERE username = 'jerry'

        # SELECT (JOIN)
        # SELECT <columns> FROM <table1> JOIN <table2> on <predicate>

        # UPDATE
        # UPDATE <table> SET <column> = <value> WHERE <predicate>
        # e.g. UPDATE users SET password = 'yadayada' WHERE idnum = 10

        # DELETE FROM <table> WHERE <predicate>
        # e.g. DELETE FROM users WHERE username = 'newman'


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""

    current_id = session["user_id"]
    username = db.execute("SELECT username FROM users WHERE id = :id", id=current_id)
    username = username[0]['username']

    if request.method == "GET":
        current_holdings = db.execute("SELECT ticker FROM assets WHERE username = :username", username=username)
        return render_template("sell.html", holdings=current_holdings), 200

    if request.method == "POST":

        if not request.form.get("symbol"):
            return apology("must provide ticker", 400)
        else:
            ticker = request.form.get("symbol")

        if not request.form.get("shares"):
            return apology("must provide number of shares", 400)
        else:
            number = request.form.get("shares")

        try:
            val = int(number)
            if val < 0:
                return apology("Sorry, input must be a positive integer, try again", 400)

        except ValueError:
            return apology("That's not a valid number of shares!", 400)

        cash_balance = db.execute("SELECT cash  FROM users WHERE id = :id", id=current_id)
        balance = cash_balance[0]
        cash_balance = float(balance['cash'])

        lkp = lookup(ticker)

        if lkp == None:
            return apology("upon lookup, ticker does not exist", 400)

        price = float(lkp['price'])
        total_cost = price * val

        shares_owned = db.execute("SELECT shares FROM assets WHERE username = :username AND ticker = :ticker",
                                  username=username, ticker=ticker)

        if not shares_owned:
            return apology("you do not appear to own any shares of this security", 400)

        if float(shares_owned[0]['shares']) < val:
            return apology("you do not own that many shares of this security", 400)

        lkp = lookup(ticker)

        if lkp == None:
            return apology("upon lookup, ticker does not exist", 400)

        price = float(lkp['price'])
        total_cost = price * val

        new_share_count = float(shares_owned[0]['shares']) - val

        # get date and time
        trans_date = datetime.date.today()
        trans_time = datetime.datetime.now().time()

        new_cash_balance = cash_balance + float(total_cost)
        update_cash = db.execute("UPDATE users SET cash = :cash WHERE id = :id", cash=new_cash_balance, id=current_id)

        cash_balance = db.execute("SELECT cash  FROM users WHERE id = :id", id=current_id)

        transaction = db.execute("INSERT INTO transactions (username, buysell, ticker, shares, price, date, time) VALUES (:username, :buysell, :ticker, :shares, :price, :date, :time)",
                                 username=username, buysell="sell", ticker=ticker, shares=val, price=price, date=trans_date, time=trans_time)

        add_asset = db.execute("UPDATE assets SET shares = :shares WHERE username = :username AND ticker = :ticker",
                               shares=int(new_share_count), username=username, ticker=ticker)

        return render_template("sold.html", shares=val, name=ticker, price=usd(price), cost=usd(total_cost), cash=usd(new_cash_balance)), 200


def errorhandler(e):
    """Handle error"""
    return apology(e.name, e.code)


# listen for errors
for code in default_exceptions:
    app.errorhandler(code)(errorhandler)