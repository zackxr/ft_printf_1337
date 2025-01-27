# ft_printf

<p align="center">
  <img src="https://github.com/mcombeau/mcombeau/blob/main/42_badges/ft_printfe.png" alt="ft_printf 42 project badge"/>
</p>

## Overview

The `ft_printf` project is part of the 42 school curriculum, where the objective is to recreate the standard C library function `printf`. This project provides an in-depth understanding of variadic arguments and the use of structures, particularly when implementing additional formatting flags.

> **Note:** This project has been archived in the state it was in at the time of evaluation.

### Supported Features

- **Conversions:** `%`, `c`, `s`, `p`, `i`, `d`, `u`, `x`, `X`
- **Flags:** `#`, `+`, ` ` (space)
- **Options:** `-`, `0`, `.`, `*`, width

## Project Status

- **Completion Date:** November 18, 2024
- **Grade Achieved:** 100/100

## Usage

### Compilation

To compile the `ft_printf` library, use the following commands:

```bash
make
```

### Basic Example

Create a `main.c` file with the following content:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Testing ft_printf!");
    return (0);
}
```

Compile and run the program:

```bash
gcc main.c libftprintf.a && ./a.out
```

**Expected Output:**

```
Testing ft_printf!
```

### Advanced Usage: Format Specifiers

The `ft_printf` function supports a variety of format specifiers, which can be combined as follows:

```
%[flags][width][.precision]specifier
```

#### Supported Format Specifiers

<table>
    <thead>
        <tr>
            <th colspan=3><h4>Flags</h4></th>
        </tr>
        <tr>
            <th>Flag</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center">-</td>
            <td>Left-justify the result within the field. By default, the result is right-justified.</td>
        </tr>
        <tr>
            <td align="center">+</td>
            <td>Forces the result to be preceded by a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded by a sign.</td>
        </tr>
        <tr>
            <td align="center">(space)</td>
            <td>If no sign is present, a space is attached to the beginning of the result.</td>
        </tr>
        <tr>
            <td align="center">#</td>
            <td>When used with `x` or `X` specifiers, the value is preceded by `0x` or `0X` respectively for non-zero values.</td>
        </tr>
        <tr>
            <td align="center">0</td>
            <td>Leading zeros are used to pad the numbers instead of spaces.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Width</h4></th>
        </tr>
        <tr>
            <th>Value</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center">(number)</td>
            <td>Minimum number of characters to be printed. If the value is shorter than this number, the result is padded with spaces. The value is not truncated even if the result is larger.</td>
        </tr>
        <tr>
            <td align="center">*</td>
            <td>The width is specified as an additional integer value argument preceding the argument to be formatted.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Precision</h4></th>
        </tr>
        <tr>
            <th>Value</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center">.(number)</td>
            <td>For integer specifiers (`d`, `i`, `u`, `x`, `X`), precision specifies the minimum number of digits to be written. If the value is shorter, it is padded with leading zeros. For `s`, it specifies the maximum number of characters to be printed. For `c`, it has no effect. If no precision is specified, the default is 1. If the period is specified without a value, 0 is assumed.</td>
        </tr>
        <tr>
            <td align="center">.(*)</td>
            <td>The precision is specified as an additional integer value argument preceding the argument to be formatted.</td>
        </tr>
    </tbody>
    <thead>
        <tr>
            <th colspan=3><h4>Specifiers</h4></th>
        </tr>
        <tr>
            <th>Format Specifier</th>
            <th>Description</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td align="center">%</td>
            <td>Prints a literal `%` character.</td>
        </tr>
        <tr>
            <td align="center">c</td>
            <td>Prints a single character.</td>
        </tr>
        <tr>
            <td align="center">s</td>
            <td>Prints a string of characters.</td>
        </tr>
        <tr>
            <td align="center">p</td>
            <td>Prints a pointer address in an implementation-defined format.</td>
        </tr>
        <tr>
            <td align="center">d or i</td>
            <td>Prints a signed integer in decimal format.</td>
        </tr>
        <tr>
            <td align="center">u</td>
            <td>Prints an unsigned integer in decimal format.</td>
        </tr>
        <tr>
            <td align="center">x or X</td>
            <td>Prints an unsigned integer in hexadecimal format.</td>
        </tr>
    </tbody>
</table>
---

**Author:** smaksiss  
**Contact:**  smaksiss@student.1337.ma  
**LinkedIn:** [soufian maksiss](https://www.linkedin.com/in/soufian-maksiss-b4a020305/)  
