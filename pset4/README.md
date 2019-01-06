# Questions

## What's `stdint.h`?

A header file that declares a set of integer types with specific widths and corresponding set of macros.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

It makes it clear you intend to use data a specific way and ensures you use up a specific amount for bytes for an integer value (good where byte allocation matters) - uint8_t for example is an integer that uses 1 byte.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

BYTE = 1

DWORD = 4

LONG = 4

WORD = 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

0x4d42

## What's the difference between `bfSize` and `biSize`?

biSize is the size in bytes of the BITMAPINFOHEADER, bfSize is the size in bytes of the bitmap file (includes pixels, padding and headers).

## What does it mean if `biHeight` is negative?

If biHeight is negative, the bitmap is a top-down device independent bitmap with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If there is not enough memory, if file is corrupt and unreadable, if file could not be found.

## Why is the third argument to `fread` always `1` in our code?

Because there's only one file header element and info header sizeof() returns the number of bytes necessary to store the entire structure.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Sets the position indicator associated with the stream to a new position - sets the current pointer in a file to another location in the file -e.g. end of file.

## What is `SEEK_CUR`?

Current position of file pointer.

## Whodunit?

TODO
