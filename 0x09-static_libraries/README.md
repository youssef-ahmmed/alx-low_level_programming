# Project: 0x09. C - Static libraries

## Resources

#### Read or watch:

* [What Is A "C" Library? What Is It Good For?](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [Creating A Static "C" Library Using "ar" and "ranlib"](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [Using A "C" Library In A Program](https://docencia.ac.upc.edu/FIB/USO/Bibliografia/unix-c-libraries.html)
* [What is difference between Dynamic and Static library(Static and Dynamic linking)](https://www.youtube.com/watch?v=eW5he5uFBNM)
## Learning Objectives

### General

* What is a static library, how does it work, how to create one, and how to use it
* Basic usage of <code>ar</code>, <code>ranlib</code>, <code>nm</code>

## Tasks

* **0. A library is not a luxury but one of the necessities of life**
    * [libmy.a](./libmy.a): C Static library containing all the functions
      listed below:

  | File                         | Prototype                                               |
    |------------------------------|---------------------------------------------------------|
  | [_putchar.c](./_putchar.c)   | `int _putchar(char c);`                                 |
  | [0-isupper.c](./0-isupper.c) | `int _isupper(int c);`                                  |
  | [0-memset.c](./0-memset.c)   | `char *_memset(char *s, char b, unsigned int n);`       |
  | [0-strcat.c](./0-strcat.c)   | `char *_strcat(char *dest, char *src);`                 |
  | [1-isdigit.c](./1-isdigit.c) | `int _isdigit(int c);`                                  |
  | [1-memcpy.c](./1-memcpy.c)   | `char *_memcpy(char *dest, char *src, unsigned int n);` |
  | [1-strncat.c](./1-strncat.c) | `char *_strncat(char *dest, char *src, int n);`         |
  | [2-strchr.c](./2-strchr.c)   | `char *_strchr(char *s, char c);`                       |
  | [2-strlen.c](./2-strlen.c)   | `int _strlen(char *s);`                                 |
  | [2-strncpy.c](./2-strncpy.c) | `char *_strncpy(char *dest, char *src, int n);`         |
  | [3-islower.c](./3-islower.c) | `int _islower(int c);`                                  |
  | [3-puts.c](./3-puts.c)       | `void _puts(char *s);`                                  |
  | [3-strcmp.c](./3-strcmp.c)   | `int _strcmp(char *s1, char *s2);`                      |
  | [3-strspn.c](./3-strspn.c)   | `unsigned int _strspn(char *s, char *accept);`          |
  | [4-isalpha.c](./4-isalpha.c) | `int _isalpha(int c);`                                  |
  | [4-strpbrk.c](./4-strpbrk.c) | `char *_strpbrk(char *s, char *accept);`                |
  | [5-strstr.c](./5-strstr.c)   | `char *_strstr(char *haystack, char *needle);`          |
  | [6-abs.c](./6-abs.c)         | `int _abs(int n);`                                      |
  | [9-strcpy.c](./9-strcpy.c)   | `char *_strcpy(char *dest, char *src);`                 |
  | [100-atoi.c](./100-atoi.c)   | `int _atoi(char *s);`                                   |

    * [main.h](./main.h): Header file containing the prototypes of all functions included in `libmy.a`.

* **1. Without libraries what have we? We have no past and no future**
    * [create_static_lib.sh](./create_static_lib.sh): Bash script that creates a static
      library called `liball.a` from all the `.c` files in the current directory.
