#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: 1 (Error)
 */
int main(void)
{
    char *msg = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    int len = 0;

    while (msg[len])
        len++;

    write(STDERR_FILENO, msg, len);

    return (1);
}
