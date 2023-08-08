#include "shell.h"

/**
 * _getenv - Get an enviroment variable.
 *
 *
 * Return: String with the value of the requested environment variable.
 */

int main(const char *name, char **env)
{
    int i = 0;
    char *var_env = NULL, *token = NULL, *delim = "=\n";

    token = strtok(env[0], delim);
    while ( token != NULL)
    {
        
        i++;
        token = strtok(env[i], delim)
    }
    var_env = env[i];
    printf("%s\n", var_env);
    return (0);
}