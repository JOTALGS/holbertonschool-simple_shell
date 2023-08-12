#include "shell.h"

/**
 * exec - execve example
 * @buff: command path.
 *
 * Return: Nothing.
 */

void exec(char **buff)
{
	char *path = NULL;

	if (buff != NULL)
		path = buff[0];

	if (execve(path, buff, environ) == -1)
		perror("Error");
}