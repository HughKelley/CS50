import cs50

input = 0

while input < 1:
    print("please enter a card number:")
    input = cs50.get_int()     #why does walkthrough use get_float? no size problems with ints in python, get_float creates length issues since there are decimals potentially

    if input > 0:
        break

tester = input % 1000

print("tester: %i" % tester)