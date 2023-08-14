#include "shell.h"

/**
 * print_env - prints the enviroment variavles.
 *
 * Return: 0 (Success).
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i++]);
	}
}

/**
 * exec - execve example
 * @buff: command path.
 *
 * Return: Nothing.
 */

void exec(char **buff)
{
	if (execve(buff[0], buff, environ) == -1)
		perror("Error");
}