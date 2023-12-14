/**
 * builtInFunc - a call to all built-in commands for the shell
 * @arg: arguments passed to the shell
 * @argv: argument vector from main function
 * Return: 1 when found and -1 when not a builtin
 */
int builtInFunc(char **arg, char **argv)
{
    (void)argv;
    if (_strcmp(arg[0], "exit") == 0)
        exit(0);
    else if (_strcmp(arg[0], "cd") == 0)
    {
        if (arg[1] == NULL)
            chdir(_getEnviron("HOME"));
        else
            chdir(arg[1]);
        return 1;
    }
    else if (_strcmp(arg[0], "env") == 0)
    {
        int i = 0;
        char **envp = environ;

        if (envp == NULL)
        {
            _print_data("Path Empty.\n");
            return -1;
        }

        for (i = 0; envp[i] != NULL; i++)
        {
            _print_data(envp[i]);
            _print_data("\n");
        }

        return 1;
    }
    else
        return -1;
}

/**
 * pathExist - check if the path exists
 * @ecmd: the command to check if it exists
 * Return: the path if the command exists in the path or NULL
 */
char *pathExist(char *ecmd)
{
    char *path_env = _getEnviron("PATH=");
    char *evnp_dup = _strdup(path_env);
    char *tok = NULL, *fullPath = NULL;

    if (evnp_dup == NULL)
    {
        _print_data("Memory Allocation Failed\n");
        return NULL;
    }

    tok = strtok(evnp_dup, ":");
    while (tok != NULL)
    {
        if (ecmd[0] != '/')
        {
            fullPath = malloc(_strlen(tok) + _strlen(ecmd) + 3);
            if (fullPath == NULL)
            {
                _print_data("Memory Allocation Failed\n");
                free(evnp_dup);
                return NULL;
            }

            _strcpy(fullPath, tok);
            _strcat(fullPath, "/");
            _strcat(fullPath, ecmd);

            if (access(fullPath, X_OK) == 0)
            {
                free(evnp_dup);
                return fullPath;
            }
            free(fullPath);
        }
        else
        {
            if (access(ecmd, X_OK) == 0)
            {
                free(evnp_dup);
                return ecmd;
            }
        }

        tok = strtok(NULL, ":");
    }

    free(evnp_dup);
    return NULL;
}
