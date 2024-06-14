# Project: 0x18. C - Dynamic libraries

## Resources

#### Read or watch:

* [What is difference between Dynamic and Static library (Static and Dynamic linking)](https://www.youtube.com/watch?v=eW5he5uFBNM)
* [Creating a dynamic library in C](https://cylab.be/blog/234/creating-a-dynamic-library-in-c)
* [Chapter 17. Creating libraries with GCC](https://access.redhat.com/documentation/en-us/red_hat_enterprise_linux/7/html/developer_guide/creating-libraries-gcc)
* [create dynamic libraries on Linux](https://www.google.com/search?q=linux+create+dynamic+library&safe=active)
## Learning Objectives

### General

* What is a dynamic library, how does it work, how to create one, and how to use it
* What is the environment variable <code>$LD_LIBRARY_PATH</code> and how to use it
* What are the differences between static and shared libraries
* Basic usage <code>nm</code>, <code>ldd</code>, <code>ldconfig</code>
## Tasks

* **0. A library is not a luxury but one of the necessities of life**
    * [libdynamic.so](./libdynamic.so): C dynamic library containing all the functions
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

    * [main.h](./main.h): Header file containing the prototypes of all functions
      included in `libholberton.so`.

    * **1. Without libraries what have we? We have no past and no future**
    * [1-create_dynamic_lib.sh](./1-create_dynamic_lib.sh): Bash script that creates a
      dynamic library called `liball.so` from all the `.c` files in the current directory.

    * **2. Let's call C functions from Python**
    * [100-operations.so](./100-operations.so): C dynamic library containing basic C
      mathematical operation functions that can be called from Python.
    * Includes:
        * `int add(int a, int b);`
        * `int sub(int a, int b);`
        * `int mul(int a, int b);`
        * `int div(int a, int b);`
        * `int mod(int a, int b);`

* **3. Code injection: Win the Giga Millions!**
  [101-make_me_win.sh](./101-make_me_win.sh) facilitate winning the Giga Millions lottery without modifying the Giga Millions program itself.
  You can download it [here](https://github.com/alx-tools/0x18.c)
- You can’t modify the program `gm` itself as Master Sysadmin Sylvain (MSS) always checks its [MD5](https://github.com/alx-tools/0x18.c/blob/master/101-md5_gm) before running it
- The system is an `Linux Ubuntu 16.04`
- The server has internet access
- Our mole will be only able to run two commands from a shell script, without being detected by MSS
- Your shell script should be maximum 3 lines long. You are not allowed to use `;`, `&&`, `||`, `|`, ` (it would be detected by MSS), and have a maximum of two commands
- Our mole has only the authorization to upload one file on the server. It will be your shell script
- Our mole will run your shell script this way:  `mss@gm_server$ . ./101-make_me_win.sh`
- Our mole will run your shell script from the same directory containing the program `gm`, exactly 98 seconds before MSS runs `gm` with my numbers: `./gm 9 8 10 24 75 9`
- MSS will use the same terminal and session than our mole
- Before running the `gm` program, MSS always check the content of the directory
- MSS always exit after running the program `gm`
- TL;DR; This is what is going to happen
