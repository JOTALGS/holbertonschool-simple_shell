#include "shell.h"

/**
 * free_buff - frees the allocated memory.
 * @buff: buffer to be frees.
 *
 * return: Nothing.
 */

void free_buff(char **buff)
{
	int i = 0;

	while (buff[i] != NULL)
	{
		free(buff[i]);
		i++;
	}
	free(buff[i]);
	free(buff);
}

/**
 * exit_program - kill the process.
 * @input: user input.
 * @path: path.
 *
 * Return: Nothing.
 */

void exit_program(char *input, char *path)
{
	free(input);
	free(path);
	exit(0);
}

/**
 * _getline - getline function.
 * @path: the path.
 *
 * Return: input.
 */

char *_getline(char *path)
{
	ssize_t ch_read;
	size_t in_size;
	char *input = NULL;

	ch_read = getline(&input, &in_size, stdin);
	/*check if (getline) filed, reached EOF or exit*/
	if (ch_read == -1)
	{
		printf("\n");
		exit_program(input, path);
	}
	else if (strcmp(input, "exit\n") == 0)
		exit_program(input, path);
	return (input);
}

/**
 * main - Sipmple shell main.
 *
 * Return: 0 (Success).
 */

int main(int argc, char *argv[])
{
	const char *prompt = "$ ";
	char *input = NULL, **buff = NULL, *cmnd = NULL, *path = NULL;
	int fd_isatty = 0;

	path = _getenv();
	while (1)/*infinite while loop for the shell*/
	{
		fd_isatty = isatty(STDIN_FILENO);
		if (fd_isatty)
			printf("%s", prompt);
		input = _getline(path);
		buff = create_buff(input, path);
		if (buff != NULL)
		{
			cmnd = strdup(buff[0]);
			if (status(buff) == 0)
				child_process(buff, path);
			else
			{
				buff[0] = _which(buff, path);
				if (buff[0] != NULL)
					child_process(buff, path);
				else
					printf("%s: %d: %s: not found\n", argv[0], argc, cmnd);
			}
			free(cmnd);
			free_buff(buff);
		}
		if (!fd_isatty)
			break;
		free(input);
	}
	free(path);
	exit(0);
}
