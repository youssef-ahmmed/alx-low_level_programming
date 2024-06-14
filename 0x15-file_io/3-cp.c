#include "main.h"

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *              If file_from does not exist or cannot be read - exit code 98.
 *              If file_to cannot be created or written to - exit code 99.
 *              If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char **argv)
{
	int file_to, file_from, r = 0, w = 0;
	char *buffer;

	check_argument(argc);

	buffer = new_buffer(argv[2]);
	file_from = open(argv[1], O_RDONLY);
	r = read(file_from, buffer, BUFFER_SIZE);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	check_open_read_write(file_from, r, argv[1], file_to, w, argv[2], buffer);

	while (r > 0)
	{
		w = write(file_to, buffer, r);

		check_open_read_write(file_from, r, argv[1], file_to, w, argv[2], buffer);

		r = read(file_from, buffer, BUFFER_SIZE);
		file_to = open(argv[2], O_WRONLY | O_APPEND);
	}

	free(buffer);
	close_file(file_from);
	close_file(file_to);

	return (0);
}

/**
 * new_buffer - Allocates 1024 bytes for a buffer
 * @file: name of the file
 * Return: A pointer to the newly-allocated buffer
 */
char *new_buffer(char *file)
{
	char *buffer;

	buffer = malloc(1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors
 * @file_descriptor: One to be closed
 */
void close_file(int file_descriptor)
{
	int check;

	check = close(file_descriptor);

	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_descriptor);
		exit(100);
	}
}

/**
 * check_argument - checks the number of argument
 * @argc: argument count
 */
void check_argument(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * check_open_read_write - check if the files open correctly
 * @fd_from: file descriptor from
 * @r: number of reads
 * @file_from_name: name of the file
 * @fd_to: file descriptor to
 * @w: number of writes
 * @file_to_name: name of the file
 * @buffer: buffer
 */
void check_open_read_write(int fd_from, int r, char *file_from_name,
		int fd_to, int w, char *file_to_name, char *buffer)
{
	if (fd_from == -1 || r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from_name);
		free(buffer);
		exit(98);
	}

	if (fd_to == -1 || w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to_name);
		free(buffer);
		exit(99);
	}
}
