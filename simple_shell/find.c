#include "shell.h"

extern char **environ;

/**
 * _getenv - Get an enviroment variable. 
 *
 * Return: String with the value of the requested environment variable.
 */

char *_getenv(void)
{
    const char *path = "PATH", *delim = "=\n";
    char *token = NULL;
    int i = 0;

    token = strtok(environ[i], delim);
    while ( token != NULL)
    {
        if (strcmp(token, path) == 0)
        {
            break;
        }
        i++;
        token = strtok(environ[i], delim);
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

char *_which(char **buff)
{
	const char *delim = ":\n";
	struct stat st;
	char *path, *token = NULL, *test = NULL;

	path = _getenv();
	token = strtok(path, delim);
	while (token != NULL)
	{
		test = malloc(sizeof(char) * (strlen(token) + strlen(*buff) + strlen("/") + strlen("/") + 1));
		if (test == NULL)
		{
			perror("Allocate memory error 2\n");
			exit(-1);
		}
		strcpy(test, token);
		strcat(test, "/");
		strcat(test, *buff);
		printf("\n-->> test: %s\n", test);
		if (stat(test, &st) == 0)
		{
			printf("\n-->> in if\n");
			break;
		}
		token = strtok(NULL, delim);
	}

	return (test);
}