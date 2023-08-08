#include "shell.h"

/**
 * main - find a file in the PATH.
 * @argv: Files.
 *
 * Return: 0 (Success).
 */

 int main(int argc, char **argv)
 {
    (void) argc;
    struct stat st;
    unsigned int i = 0, ac = 0;

    for (i = 1; argv[i] != NULL; i++)
        ;

    if (i < 2)
    {
        printf("Usage: %s path_to_file ...\n", argv[0]);
        return (-1);
    }

    i = 1;
    while (argv[i])
    {
        printf("%s:", argv[i]);
        if (stat(argv[i], &st) == 0)
        {
            printf(" FOUND\n");
        }
        else
        {
            printf(" NOT FOUND\n");
        }
        i++;
    }
    return (0);
 }