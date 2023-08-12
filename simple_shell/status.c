#include "shell.h"

/**
 * status - check if found a file.
 * @argv: token.
 *
 * Return: 0 if file found, -1 otherwise.
 */

int status(char **buff)
{
	struct stat st;

	if (stat(buff[0], &st) == 0)
		return (0);
	else
	{
		return (-1);
	}
}
