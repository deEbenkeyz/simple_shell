#include "main.h"

/**
 * execmd - execute a command
 * @pathcmd: the command to execute
 * @args: the arguments for the command
 * Return: 0 on success, -1 on failure
 */
int execmd(char *pathcmd, char **args)
{
    int ShellEx = 0;
    char **pathEnv = environ;
    pid_t childId;

    /* start a child process */
    childId = fork();

    if (childId < 0)
    {
        perror("Error");
        free(pathcmd);
        free(args);
        exit(errno);
    }
    else if (childId == 0)
    {
        /* execute the command */
        ShellEx = execve(pathcmd, args, pathEnv);
        /* if the command is not found */
        if (ShellEx == -1)
        {
            perror("Error");
            free(args);
            free(pathcmd);
            _print_data("not found!\n");
            exit(errno);
        }
    }
    else
    {
        wait(NULL);
    }

    return 0;
}
