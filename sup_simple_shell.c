#include "shell.h"

/**
 * frees - frees the allocated memory.
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
 * exit_process - kill the process.
 * @input: user input.
 * @path: path.
 * 
 * Return: Nothing.
*/

int exit_process(char *input, char *path)
{
	free(input);
	free(path);
	kill(getpid(), SIGTERM);
	return (0);
}

/**
 * main - Sipmple shell main.
 *
 * Return: 0 (Success).
 */

 int main(void)
 {
	const char *prompt = "$ ";
	ssize_t ch_read = 0;
	size_t in_size = 0;
	char *input = NULL, **buff = NULL, *cmnd = NULL, *path = NULL;
	int fd_isatty = 0;

	path = _getenv();
	while (1)/*infinite while loop for the shell*/
	{
		fd_isatty = isatty(STDIN_FILENO);
		if (fd_isatty)
			printf("%s", prompt);
		ch_read = getline(&input, &in_size, stdin);
		/*check if (getline) filed, reached EOF or exit*/
		if (ch_read == -1)
		{
			free(input);
			free(path);
			printf("\n");
			return (-1);
		}
		else if(strcmp(input, "exit\n") == 0)
			return (exit_process(input, path));
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
					printf("%s: not found\n", cmnd);
			}
			free(cmnd);
			free_buff(buff);
		}
		if (!fd_isatty)
			break;
	}
	free(path);
	return (0);
 }