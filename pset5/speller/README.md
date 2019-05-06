# Questions

## What is pneumonoultramicroscopicsilicovolcanoconiosis?

 It is a word invented by the president of the National Puzzlers' League as a synonym for the disease known as silicosis.
    "Pneumonoultramicroscopicsilicovolcanoconiosis". Oxford Dictionaries. Oxford University Press. Retrieved 2017-10-10.

## According to its man page, what does `getrusage` do?

It provides resource usage measures for the target which can be the calling process, the children of the calling process or the calling thread.

## Per that same man page, how many members are in a variable of type `struct rusage`?

16

## Why do you think we pass `before` and `after` by reference (instead of by value) to `calculate`, even though we're not changing their contents?

Passing this values by reference may be faster.

## Explain as precisely as possible, in a paragraph or more, how `main` goes about reading words from a file. In other words, convince us that you indeed understand how that function's `for` loop works.

The key way that main reads the words is by individual character using "fgetc" from the stdio.h library. The for loop uses fgets on
the pointer, fp, to the text being spell checked, to determine the value for "c" the for loops limiting variable. The loop continues
as long as C is not EOF, end of file.

If the current value of c is alphabetical, it is added to the "word" array at the position indicated by "index".

If the length of the current word is more than LENGTH, 45, the script recognizes that as jibberish and skips ahead to the next
none alphabetical character to start a new word.

If the current character is a number the same code is used to skip to the next word

If c is not alphabetical and not a number then the program assumes that a new word is starting

## Why do you think we used `fgetc` to read each word's characters one at a time rather than use `fscanf` with a format string like `"%s"` to read whole words at a time? Put another way, what problems might arise by relying on `fscanf` alone?

By using fgetc we can check characters indiviudally for whether they are alphabetical or not and the length of the current word as
the characters are loaded instead of afterward which would be slower. Additionally, this shows the student
how to get the characters individually, which I'm pretty sure is essential for implementing load with a Trie.

## Why do you think we declared the parameters for `check` and `load` as `const` (which means "constant")?

That ensures that if there is a bug in either of those functions the original text or dictionary will not be altered.
