#include "shell.h"

/**
 * main - Prints the address of env and environ.
 * @ac: unused varieble.
 * @av: unused variable.
 * @env: enviroment variable.
 *
 * Return: 0 (Success).
 */

int main(int ac, char **av, char **env)
{
    printf("env address:     %p\n", env);
    printf("environ address: %p\n", environ);
    return (0);
}