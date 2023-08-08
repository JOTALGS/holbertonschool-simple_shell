#include "shell.h"

/**
 * exec - execve example
 *
 * Return: Nothing.
 */

void exec(char **argv)
{
    char *path = NULL;

    if (argv != NULL)
        path = argv[0];

    if (execve(path, argv, NULL) == -1)
        perror("Error");
}