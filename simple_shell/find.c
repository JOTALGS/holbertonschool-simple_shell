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
		return (-1);
}

/**
 * _getenv - Get an enviroment variable. 
 *
 * Return: String with the value of the requested environment variable.
 */

char *_getenv(void)
{
    const char *path = "PATH", *delim = "=\n";
    char *token = NULL, *env_cpy = NULL, *fin_token = NULL;
    int i = 0;

	env_cpy = strdup(environ[i]);
    token = strtok(env_cpy, delim);
    while (token != NULL)
    {
        if (strcmp(token, path) == 0)
        {
            break;
        }
        i++;
		if (environ[i] == NULL)
			return (NULL);
		env_cpy = strdup(environ[i]);
        token = strtok(env_cpy, delim);
    }
    token = strtok(NULL, delim);
	fin_token = strdup(token);
	free(env_cpy);
    return (fin_token);
}

/**
 * main - find a file in the PATH.
 * @buff: Files.
 *
 * Return: 0 (Success).
 */

char *_which(char **buff, char *path)
{
	const char *delim = ":\n";
	struct stat st;
	char *path_cpy, *token = NULL, *test = NULL;

	if (path == NULL)
			return (NULL);

	path_cpy = strdup(path);
	token = strtok(path_cpy, delim);

	while (token != NULL)
	{
		test = malloc(sizeof(char) * (strlen(token) + strlen(buff[0]) + 2));
		if (test == NULL)
		{
			free(path);
			perror("Allocate memory error\n");
			exit(-1);
		}
		strcpy(test, token);
		strcat(test, "/");
		strcat(test, buff[0]);
		if (stat(test, &st) == 0)
		{
			buff[0] = malloc(sizeof(char) * strlen(test) + 1);
			buff[0] = strdup(test);
			free(path_cpy);
			free(test);
			return (buff[0]);
		}
		free(test);
		token = strtok(NULL, delim);
	}
	free(path_cpy);
	return (NULL);
}