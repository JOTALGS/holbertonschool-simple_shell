#include "shell.h"

/**
 * status - check if found a file.
 * @argv: token.
 *
 * Return: 0 if file found, -1 otherwise.
 */

int status(char *argv)
{
    struct stat st;

    if (stat(argv, &st) == 0)
        return (0);
    else
    {
        printf("%s: not found\n", argv);
        return (-1);
    }
}