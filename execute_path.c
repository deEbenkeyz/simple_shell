int execute_path(char *ecmd, char **argv);

/**
 * execute_path - execute a command
 * @ecmd: the command to execute
 * @argv: argument vector from the main function
 * Return: 0
 */
int execute_path(char *ecmd, char **argv)
{
	char *pathcmd, **args = NULL;
	int count = 1;

	/* tokenize the arguments and assign to args */
	args = tokenize(ecmd);

	if (args == NULL)
	{
		free(ecmd);
		/* Moved from the original position */
		return (0);
	}

	/* NOTE: Calling pathExist function */
	/* check if the path exists and assign path with the argument to pathcmd */
	pathcmd = path_exist(args[0]);

	/* call built_in_func or execmd */
	if (pathcmd == NULL && built_in_func(args, argv) == 1)
	{
		free(args);
		return (0);
		/* Calling built-in functions if path is NULL */
	}
	else if (pathcmd != NULL)
	{
		/* implemented a new function instead of calling execve directly */
		/* also, moved the call of the child process to execmd */
		execmd(pathcmd, args);

		/* If execmd is successful, it won't reach here, */
		/* so we can free immediately */
		free(args);
		free(pathcmd);
	}
	else
	{
		/* This can also be removed if you prefer, but this is just to */
		/* cover up the called commands if not found */

		wait(NULL);
		_print_d_notfound(count, args, argv);
	}

	return (0);
}
