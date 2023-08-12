#include "shell.h"

/**
 * _getenv - Get an enviroment variable. 
 *
 * Return: String with the value of the requested environment variable.
 */

char *_getenv(void)
{
    const char *path = "PATH", *delim = "=\n";
    char *token = NULL, *env_cpy;
    int i = 0;
    
    env_cpy = strdup(environ[i]);
    token = strtok(env_cpy, delim);
    while (token != NULL)
    {
	env_cpy = strdup(environ[i]);
        if (strcmp(token, path) == 0)
        {
            break;
        }
        i++;
        token = strtok(env_cpy, delim);
    }
    token = strtok(NULL, delim); 
    return (token);
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
	char *path_cpy = NULL, *token = NULL, *test = NULL;

	path_cpy = strdup(path);
	token = strtok(path_cpy, delim);
	while (token != NULL)
	{
		test = malloc(sizeof(char) * (strlen(token) + strlen(buff[0]) + 2));
		if (test == NULL)
		{
			perror("Allocate memory error\n");
			exit(-1);
		}
		strcpy(test, token);
		strcat(test, "/");
		strcat(test, buff[0]);
		if (stat(test, &st) == 0)
		{
			buff[0] = strdup(test);
			free(test);
			free(path_cpy);
			return (buff[0]);
		}
		token = strtok(NULL, delim);
	}
	if (strcmp(buff[0], "\n") == 0)
	{
		buff[0] = strdup(test);
		free(test);
		free(path_cpy);
		return (buff[0]);
	}
	else
	{
		free(test);
		free(path_cpy);
		free(buff[0]);
		return (NULL);
	}
}
