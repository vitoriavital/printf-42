# Printf Project

<p align="center">
  <img src="https://game.42sp.org.br/static/assets/achievements/ft_printfm.png" alt="Printf Achievement" width="200" height="200">
  <img src="https://res.cloudinary.com/dfjub9qt4/image/upload/v1707314965/ft_printf_42.png" alt="Printf Square" width="200" height="200">
</p>

## Introduction

The printf project is a custom implementation of the printf function in C programming language. It aims to provide similar functionality to the standard printf function with support for specific format specifiers and flags.

## Description

```bash
int    ft_printf(const char *format, ...);
```
The ft_printf function receives two parameters. First, a pointer to a null-terminated string (a format string) that specifies how subsequent arguments are converted for output. The format string can contain ordinary characters (which are simply copied to the output) and conversion specifications, each beginning with a % character, followed by optional modifiers and conversion specifiers.

The second parameters refers to the "variadic arguments" feature. It indicates that the function can accept a variable number of arguments after the format parameter. These additional arguments are the values to be formatted and printed according to the conversion specifiers in the format string.

## Features

- Support for the following format specifiers:
  - `%c` - Character
  - `%s` - String
  - `%p` - Pointer
  - `%d` - Signed decimal integer
  - `%i` - Signed decimal integer
  - `%u` - Unsigned decimal integer
  - `%x` - Unsigned hexadecimal integer (lowercase)
  - `%X` - Unsigned hexadecimal integer (uppercase)
  - `%%` - Percent sign
- Support for the following flags:
  - `-` (Minus) - Left-align the output within the given field width
  - `+` (Plus) - Precede positive numbers with a plus sign
  - ` ` (Space) - Precede positive numbers with a space
  - `0` (Zero) - Pad numbers with leading zeros
  - `.` (Dot) - Specify precision for floating-point numbers
  - `#` (Hashtag) - Use alternative form for octal and hexadecimal output
 
## Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/vitoriavital/printf_42.git
```

## Usage

1. Include the ft_printf.h header file in your C program:
```bash
#include "ft_printf.h"
```

3. Compile your program with the get_next_line.c file:
```bash
gcc -Wall -Wextra -Werror -D your_source_files.c -o your_output_binary
```

3. Run your compiled program:
```bash
./your_output_binary
```


## Limitations
- This custom implementation may not support all the features and edge cases of the standard printf function.
- Floating-point support is limited and may not be as precise as the standard library implementation.
