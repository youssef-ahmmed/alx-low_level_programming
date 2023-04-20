#include "variadic_functions.h"
/**
 * _strlen - compute the length of a string
 * @s: string
 * Return: length of string
*/
int _strlen(const char *s)
{
	int len = 0;

	while (s[len])
	{
		s++;
	}

	return (len);
}

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * @...: list of arguments
 * Return: void
*/
void print_all(const char * const format, ...)
{
	int i = 0;
	char *str, *sep = "";

	va_list args;

	va_start(args, format);

	while (format[i] && format)
	{
		switch (format[i])
		{
			case 'c':
				printf("%s%c", sep, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", sep, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", sep, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					str = "(nil)";
				printf("%s%s", sep, str);
				break;
			default:
				i++;
				continue;
		}
		i++;
		sep = ", ";
	}


	printf("\n");
	va_end(args);
}
