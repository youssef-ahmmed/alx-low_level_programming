# Project: 0x0E. C - Structures, typedef

## Resources

#### Read or watch:

* [0x0d. Structures.pdf](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/6eb80c79c99f6125450a0dc11b300d46238d1a5a.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240412%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240412T211021Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=00676b49b3559f7d3a5127a5d310a8b384dbeccb8f49f6dd9b6337eeea888a7c)
* [struct (C programming language)](https://en.wikipedia.org/wiki/Struct_(C_programming_language))
* [Documentation: structures](https://github.com/alx-tools/Betty/wiki/Documentation:-Data-structures)
* [0x0d. Typedef and structures.pdf](https://s3.amazonaws.com/alx-intranet.hbtn.io/uploads/misc/2021/1/c8ff3e6f7202be7fa489a584e41d005504a07c23.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOUSBVO6H7D%2F20240412%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20240412T211108Z&X-Amz-Expires=86400&X-Amz-SignedHeaders=host&X-Amz-Signature=8e42ebe947086ead5605667bf2c4a6437be8fc2a83ff4c06b2ddd1199cecac02)
* [typedef](https://publications.gbdirect.co.uk//c_book/chapter8/typedef.html)
* **Programming in C** by Stephen Kochan - Chapter 8, Working with Structures p163-189
## Learning Objectives

### General

* What are structures, when, why and how to use them
* How to use <code>typedef</code>

## Header File :file_folder:

* [dog.h](./dog.h): Header file containing definitions and prototypes for all types
  and functions written in the project.

| Type/File       | Defintion/Prototype                                                      |
|-----------------|--------------------------------------------------------------------------|
| `struct dog`    | <ul><li>`char *name`</li><li>`float age`</li><li>`char *owner`</li></ul> |
| `typedef dog_t` | `struct dog`                                                             |
| `1-init_dog.c`  | `void init_dog(struct dog *d, char *name, float age, char *owner);`      |
| `2-print_dog.c` | `void print_dog(struct dog *d);`                                         |
| `4-new_dog.c`   | `dog_t *new_dog(char *name, float age, char *owner);`                    |
| `5-free_dog.c`  | `void free_dog(dog_t *d);`                                               |

## Tasks

* **0. Django**
    * [dog.h](./dog.h): Header file that defines a new type `struct dog` with the
      following elements:
        * `char *name`
        * `float age`
        * `char *owner`

* **1. A dog is the only thing on earth that loves you more than you love yourself**
    * [1-init_dog.c](./1-init_dog.c): C function that initializes a variable of type `struct dog`.

* **2. A dog will teach you unconditional love. If you can have that in your life, things won't be too bad**
    * [2-print_dog.c](./2-print_dog.c): C function that prints a `struct dog`.
        * If an element of `d` is `NULL`, the function prints `(nil)` instead of the element.
        * If `d` is `NULL`, the function prints nothing.

* **3. Outside of a dog, a book is a man's best friend. Inside of a dog it's too dark to read**
    * [dog.h](./dog.h): Header file that defines a new type `dog_t` as a new name for the
      type `struct dog`.

* **4. A door is what a dog is perpetually on the wrong side of**
    * [4-new_dog.c](./4-new_dog.c): C function that creates a dog.
        * Returns `NULL` if the function fails.

* **5. How many legs does a dog have if you call his tail a leg? Four. Saying that a tail is a leg doesn't make it a leg**
    * [5-free_dog.c](./5-free_dog.c): C function that frees dogs.
