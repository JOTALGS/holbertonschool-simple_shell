#include "shell.h"

/**
 *
 *
 *
 */

char **create_buff(char *input)
{
	const char *delim = " \"\n";
	char *input_cpy = NULL, *token = NULL, **buff = NULL;
	int num_tok = 0, i = 0;

	
	input_cpy = strdup(input);
	/*calculates the total numbers of tokens*/
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
		perror("Memory allocation error\n");
		exit(-1);
	}
	/*store each token in each cell of the matrix*/
	token = strtok(input_cpy, delim);
	
	for (i = 0; token != NULL; i++)
	{
		/*allocate memory for each token*/
		buff[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (buff[i] == NULL)
		{
			free(input_cpy);
			free_buff(buff);
			perror("Memory allocation error\n");
			exit (-1);
		}
		buff[i] = strdup(token);
		token = strtok(NULL, delim);
	}
	buff[i] = NULL;
	free(input_cpy);
	return (buff);
}
/**
 *
 *
 *
 */

int child_process(pid_t pid, char *s1, char **buff)
{
	if (status(buff) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			free(s1);
			free_buff(buff);
			perror("Fork failed\n");
			return (-1);
		}
		else if (pid == 0)
		{
			exec(buff);
			perror("Execve failed");
			return (-1);
		}
		else
			wait(NULL);
	}
	return (0);
}