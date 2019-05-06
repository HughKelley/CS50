import cs50

# prompt for user input
input = 0

while input < 1:
    print("please enter a card number:")
    input = cs50.get_int()    # why does walkthrough use get_float? no size problems with ints in python, get_float creates length issues since there are decimals potentially

    if input > 0:
        break

number = str(input)

length = len(str(number))

# multiply every other digit by 2

sum = 0
switch = 1
holder = length - 1
digit = 0

for i in range(0, length):

    if switch < 0:
        digit = int(number[holder]) * 2

    else:
        digit = int(number[holder])

    if digit > 9:
        sum = sum + 1
        digit = digit - 10
        sum = sum + digit
    else:
        sum = sum + digit

    holder = holder - 1
    switch = switch * -1

if sum % 10 > 0:
    print("INVALID")
else:
    if length == 13:
        print("VISA")

    elif length == 15:
        print("AMEX")

    elif length == 16:

        save = str(input)
        c = save[0]

        if c == '4':
            print("VISA")
        elif c == '5':
            d = save[1]

            if d == '1' or d == '2' or d == '3' or d == '4' or d == '5':
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")
    else:
        print("INVALID")

# Amex 15 digits starts with 34 or 37
# Mastercard 16 digits starts with 51, 52 53, 54, 55
# # Visa  13 or 16 digits starts with 4

# Card Type	Number
# American Express	378282246310005
# American Express	371449635398431
# MasterCard	5555555555554444
# MasterCard	5105105105105100
# Visa	4111111111111111
# Visa	4012888888881881
# Visa	4222222222222