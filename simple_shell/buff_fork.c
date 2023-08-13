#include "shell.h"

/**
 * create_buff - Creates a buffer from the @input;
 * @input: Input of the user.
 * @path: the path.
 *
 * Return: Buffer, NULL if the user inputs only (spaces, new line or tabs).
 */

char **create_buff(char *input, char *path)
{
	const char *delim = " \"\t\n";
	char *input_cpy = NULL, *token = NULL, **buff = NULL;
	int num_tok = 0, i = 0;

	input_cpy = strdup(input);
	/*calculates the numbers of tokens*/
	token = strtok(input, delim);
	while (token != NULL)
	{
		num_tok++;
		token = strtok(NULL, delim);
	}
	num_tok++;

	if (num_tok == 1)
		return (NULL);
	/*allocate memory to hold array of strings*/
	buff = malloc(sizeof(char *) * num_tok);
	if (buff == NULL)
	{
		free(input_cpy);
		free(path);
		perror("Memory allocation error\n");
		exit(-1);
	}
	/*store each token in each cell of the buffer*/
	token = strtok(input_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
		/*allocate memory for each token*/
		buff[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (buff[i] == NULL)
		{
			free(path);
			free(input_cpy);
			free_buff(buff);
			perror("Memory allocation error\n");
			exit (-1);
		}
		strcpy(buff[i], token);
		token = strtok(NULL, delim);
	}
	buff[i] = NULL;
	free(input_cpy);
	return (buff);
}
/**
 * child_process - creates a child process on success.
 * @str: string to be released in case of error.
 * @buff: path of the executable to run.
 * @path: the path:
 *
 * Return: 0 (Success).
 */

int child_process(char **buff, char *path)
{
	pid_t pid = getpid();

	/*check if the path (buff) created exist*/
	if (status(buff) == 0)
	{
		/*create a child process to execute the path (buff)*/
		pid = fork();
		if (pid == -1)
		{
			free(path);
			free_buff(buff);
			perror("Fork failed\n");
			return (-1);
		}
		else if (pid == 0)
		{
			if (strcmp(buff[0], "/usr/bin/env") == 0)
			{
				print_env();
				kill(getpid(), SIGKILL);
			}
			else
			{
				exec(buff);
				free(path);
				free_buff(buff);
				perror("Execve failed");
			}
			return (-1);
		}
		else
			wait(NULL);
	}
	return (0);
}