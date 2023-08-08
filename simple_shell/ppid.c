#include "shell.h"

/**
 * main - Id of the parent process.
 *
 * Return: Nothing.
 */

void main(void)
{
    pid_t my_ppid = getppid();

    printf("%u\n", my_ppid);
}