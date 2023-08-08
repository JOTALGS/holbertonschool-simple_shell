#include "shell.h"

/**
 * main - prints the enviroment.
 * @ac: unused variable.
 * @av: unused variable.
 * @env: environ global variable.
 *
 * Return: 0 (Success).
 */

int main(int ac, char **av, char **environ)
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
        printf("%s\n", environ[i++]);
    return (0);
}