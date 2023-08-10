#include "shell.h"

/**
 * frees - frees the allocated memory.
 * @str1: String to free.
 *
 * return: (void).
 */

void free_buff(char **buff)
{
	int i = 0;

	while (buff[i] != NULL)
	{
		free(buff[i++]);
	}
	free(buff);
}

/**
 * main - super sipmple shell
 * @ac: counter.
 * @argv: pointer to array of arguments.
 *
 * Return: 0 (Success).
 */

 int main(void)
 {
	const char *prompt = "$ ";
	ssize_t ch_read;
	size_t in_size = 0;
	pid_t pid = 0;
	char *input = NULL;
	char **buff, *cmnd, *path;
	int fd_isatty = 0;

	/*while loop for the shell's prompt*/
	path = _getenv();
	while (1)
	{
		printf("%s", prompt);

		fd_isatty = isatty(STDIN_FILENO);
		
		ch_read = getline(&input, &in_size, stdin);
		if (ch_read == -1 || strcmp(input, "exit\n") == 0)/*check if (getline) filed or reached EOF*/
		{
			printf("\n");
			return (-1);
		}
		buff = create_buff(input);
		cmnd = strdup(buff[0]);
		if (status(buff) == 0)
			child_process(pid, cmnd, buff);
		else
		{
			buff[0] = _which(buff, path);
			if (buff[0] != NULL)
				child_process(pid, cmnd, buff);
			else
				printf("%s: not found\n", cmnd);
		}
		free(cmnd);
		if (fd_isatty)
			continue;
		else
			break;
	}
	free_buff(buff);
	return (0);
 }