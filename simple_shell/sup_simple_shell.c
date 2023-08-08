#include "shell.h"

/**
 * frees - frees the allocated memory.
 * @str1: String to free.
 * @str2: String to free.
 *
 * return: (void).
 */

void frees(char *str1, char *str2)
{
	free(str1);
	free(str2);
}

/**
 * main - super sipmple shell
 * @ac: counter.
 * @argv: pointer to array of arguments.
 *
 * Return: 0 (Success).
 */

 int main(int ac, char **argv)
 {
	const char *prompt = "$ ", *delim = " \n";
	ssize_t ch_read;
	size_t in_size = 0;
	pid_t pid;
	char *input = NULL, *input_cpy = NULL, *token = NULL;
	int num_tok = 0, i = 0;
	(void) ac;

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
		input_cpy = malloc(sizeof(char) * ch_read);/*allocate memory for a copy of @input*/
		if (input_cpy == NULL)
		{
			perror("Memory allocation error\n");
			return (-1);
		}
		strcpy(input_cpy, input);/*copy @input to @input_cpy*/

		/*calculates the total numbers of tokens*/
		token = strtok(input, delim);
		while (token != NULL)
		{
			num_tok++;
			token = strtok(NULL, delim);
		}
		num_tok++;

		argv = malloc(sizeof(char *) * num_tok);/*allocate memory to hold array of strings*/

		/*store each token in each cell of the matrix*/
		token = strtok(input_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));/*allocate memory for each token*/
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;

		if (status(argv[0]) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				frees(input, input_cpy);
				perror("Fork failed\n");
				return (-1);
			}
			else if (pid == 0)
			{
				exec(argv);
				perror("Execve failed");
				return (-1);
			}
			else
				wait(NULL);
		}
	}
	frees(input, input_cpy);
	return (0);
 }