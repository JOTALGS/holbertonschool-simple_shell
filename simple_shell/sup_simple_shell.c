#include "shell.h"

/**
 * frees - frees the allocated memory.
 * @str1: String to free.
 * @str2: String to free.
 * @str3: String to free.
 *
 * return: (void).
 */


void frees(char *str1, char *str2, char *str3)
{
	free(str1);
	free(str2);
	free(str3);
}

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
	char **buff, *cmnd;

	/*while loop for the shell's prompt*/
	while (1)
	{
		printf("%s", prompt);

		ch_read = getline(&input, &in_size, stdin);
		if (ch_read == -1)/*check if (getline) filed or reached EOF*/
		{
			printf("\n");
			return (-1);
		}
		buff = create_buff(input);
		cmnd = malloc(sizeof(char) * strlen(buff[0]));
		if (cmnd == NULL)
		{
			free_buff(buff);
			perror("Memory allocation error\n");
			return (-1);
		}
		cmnd = strdup(buff[0]);

		if (status(buff) == 0)
			child_process(pid, cmnd, buff);
		else
		{
			if ((*buff = _which(buff)) != NULL)
				child_process(pid, cmnd, buff);
			else
				printf("%s: not found\n", cmnd);
			free_buff(buff);
		}
	}
	free(cmnd);
	return (0);
 }
