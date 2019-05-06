# Questions

## What's `stdint.h`?

this library allows the code to specify exactly the size of an integer in bytes, which can vary across machines, causing problems when interpreting a file.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

this specifies, during compiling, how many bytes an integer should be allocated.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

A BYTE is 1 byte or 8 bits

A DWORD is a 32 bit or 4 byte unsigned integer

A LONG is a 32 bit signed integer

A WORD is a 16 bit unsigned integer

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

They must be 0.

## What's the difference between `bfSize` and `biSize`?

bfSize if the size of the file.

biSize is the size of the header structure

## What does it mean if `biHeight` is negative?

It means the file originates in the upper left corner and is not compressible.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If it can't return a file pointer. this would probably indicate an issue with the file being sent to copy or the file the copy is trying to send out.

## Why is the third argument to `fread` always `1` in our code?

hte size is always 1 byte

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

padding would be assigned the value 1

## What does `fseek` do?

fseek allows the user to change where a file pointer points to

## What is `SEEK_CUR`?

This means the change in the pointer location will be in relation to the current value for the pointer, rather than the end of the file.
