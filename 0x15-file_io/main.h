#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
char *new_buffer(char *file);
void close_file(int file_descriptor);
void check_argument(int argc);
void check_open_read_write(int fd_from, int r, char *file_from_name,
		int fd_to, int w, char *file_to_name, char *buffer);

#endif /* MAIN_H */
