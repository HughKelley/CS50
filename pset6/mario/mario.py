import cs50

height = -1

while height < 0 or height > 23:
    print("please enter a height:")
    height = cs50.get_int()

spaces = height - 1
hashes = 1
b = 0

while b < height:
    print(' ' * spaces, end="")
    print('#' * hashes, end="")
    print("  ", end="")
    print('#' * hashes, end="")
    print()
    b = b + 1
    spaces = spaces - 1
    hashes = hashes + 1