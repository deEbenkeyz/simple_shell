#include "main.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char **argv)
{
	char *cmd = NULL;
	size_t cmd_size = 0;
	ssize_t read_lines;
	int is_terminal = isatty(0);

	signal(SIGINT, signal_handler);

	while (1)
	{
		if (is_terminal)
			_print_data("$ ");
		read_lines = getline(&cmd, &cmd_size, stdin);

		if (read_lines == -1)
		{
			free(cmd);
			exit(0);
		}

		if (cmd[read_lines - 1] == '\n')
			cmd[read_lines - 1] = '\0';

		if (cmd == NULL)
		{
			perror("Error");
			return (1);
		}

		/* Skip empty commands */
		if (_strcmp(cmd, "") == 0)
			continue;

		/* Calling execute_path function */
			execute_path(cmd, argv);
		}

		return (errno);
}
