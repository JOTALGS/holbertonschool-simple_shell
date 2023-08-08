#include "shell.h"

/**
 * main - Id of the current process.
 *
 * Return: Nothing.
 */

void main(void)
{
    pid_t my_pid = getpid();

    printf("%u\n", my_pid);
}