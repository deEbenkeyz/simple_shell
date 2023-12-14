#include "main.h"

/**
 * tokenize - tokenize the arguments
 * @ecmd: the arguments to tokenize
 * Return: the tokenized arguments
 */
char **tokenize(char *ecmd)
{
	char *delim = " \"\t\r", *token, **args = NULL;
	int count = 0;

	/* allocate memory for the args array to hold the arguments */
	args = malloc(sizeof(char *) * (MAX_ARGS + 1));
	if (args == NULL)
	{
		perror("Error");
		exit(errno);
	}

	/* tokenize the arguments */
	token = strtok(ecmd, delim);

	if (token == NULL)
	{
		free(args);
		return (NULL);
	}

	while (token != NULL)
	{
		/* add the token to the args array */
		args[count++] = _strdup(token);
		/* Use _strdup to duplicate the token */
		token = strtok(NULL, delim);
	}

	/* add a NULL terminator to the args array */
	args[count] = NULL;

	return (args);
}
