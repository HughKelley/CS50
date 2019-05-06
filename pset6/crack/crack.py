import cs50
import crypt
import sys
import string
import itertools

if len(sys.argv) < 2 or len(sys.argv) >2:
    print("Usage: ./crack hash")
    sys.exit()

alphabet = string.ascii_letters
betalph = list(alphabet)

hashinput = list(sys.argv[1])
input = ''.join(hashinput)

salt = [input[0],input[1]]
pepper = ''.join(salt)

# 1 character
for perm in itertools.product(betalph):

    password = ''.join(perm)
    # password = 'LOL'
    # print(password)
    output = crypt.crypt(password, pepper)

    if output == input:
        print(password)
        sys.exit()

# 1 character
for perm in itertools.product(betalph):

    password = ''.join(perm)
    # password = 'LOL'
    # print(password)
    output = crypt.crypt(password, pepper)

    if output == input:
        print(password)
        sys.exit()

# 2 character
for perm in itertools.product(betalph, betalph):

    password = ''.join(perm)
    # password = 'LOL'
    # print(password)
    output = crypt.crypt(password, pepper)

    if output == input:
        print(password)
        sys.exit()

# 3 character
for perm in itertools.product(betalph, betalph, betalph):

    password = ''.join(perm)
    # password = 'LOL'
    # print(password)
    output = crypt.crypt(password, pepper)

    if output == input:
        print(password)
        sys.exit()

# 4 character
for perm in itertools.product(betalph, betalph, betalph, betalph):

    password = ''.join(perm)
    # password = 'LOL'
    # print(password)
    output = crypt.crypt(password, pepper)

    if output == input:
        print(password)
        sys.exit()

# 5 character
for perm in itertools.product(betalph, betalph, betalph, betalph, betalph):

    password = ''.join(perm)
    # password = 'LOL'
    # print(password)
    output = crypt.crypt(password, pepper)

    if output == input:
        print(password)
        sys.exit()

print("password not found")