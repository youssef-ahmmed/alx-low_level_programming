#include "main.h"

/**
 * read_textfile - reads a text file
 * and prints it to the POSIX standard output
 * @filename: name of the file
 * @letters: number of letters it should read and print
 * Return: actual number of letters it could read and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t start, in, out;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
		return (0);

	start = open(filename, O_RDONLY);
	in = read(start, buffer, letters);
	out = write(STDOUT_FILENO, buffer, in);

	if (start == -1 || in == -1 || out == -1 || out != in)
	{
		free(buffer);
		close(start);
		return (0);
	}

	free(buffer);
	close(start);

	return (in);
}
