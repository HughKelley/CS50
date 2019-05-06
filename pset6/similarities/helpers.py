import time


def lines(a, b):

    print()
    alist = a.splitlines()
    blist = b.splitlines()
    doubles = []

    for item in alist:
        for member in blist:
            if item == member:
                if not item in doubles:
                    doubles.append(item)
                    # print(item)

    # print(doubles)

    return doubles


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO

    from nltk.tokenize import sent_tokenize

    ablocks = sent_tokenize(a)
    print("ablocks", ablocks)
    bblocks = sent_tokenize(b)
    print("bblocks", bblocks)

    doubles = []

    for item in ablocks:
        for member in bblocks:
            if item == member:
                if not item in doubles:
                    doubles.append(item)
                    # print(item)

    print("doubles", doubles)

    # print("sentences function")
    # print("ablocks")
    # print(ablocks)
    # print("bblocks")
    # print(bblocks)

    # Implement sentences in such a way that, given two strings, a and b, it returns a list of the unique English sentences that
    # are, identically, present in both a and b. The list should not contain any duplicates. Use sent_tokenize from the Natural
    # Language Toolkit to "tokenize" (i.e., separate) each string into a list of sentences. It can be imported with:

    # from nltk.tokenize import sent_tokenize
    # Per its documentation, sent_tokenize, given a str as input, returns a list of English sentences therein. It assumes that its
    # input is indeed English text (and not, e.g., code, which might coincidentally have periods too).

    return doubles


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    doubles = []

    if n > len(a) or n > len(b):
        return doubles
    else:

        # slice notation
        substring_length = n
        alength = len(a)
        blength = len(b)
        alist = []
        blist = []
        start = 0
        end = substring_length

        # chop up a text
        for chunk in range(alength - substring_length + 1):
            end = start + substring_length
            holder = a[start:end]
            alist.append(holder)
            start += 1

        # chop up b text
        start = 0
        for chunk in range(blength - substring_length + 1):
            end = start + substring_length
            holder = b[start:end]
            blist.append(holder)
            start += 1

        # make a list
        for item in alist:
            for member in blist:
                if item == member:
                    if not item in doubles:
                        doubles.append(item)

        # print(doubles)
        # print(alist)
        # print(blist)
        # print(a)
        # print(b)

    return doubles

    # For Testing
    # ./compare --lines texts/hey.c texts/hello.c
    # ./compare --sentences texts/text1.txt texts/text2.txt
    # ./compare --substrings 2 texts/text1.txt texts/text2.txt
