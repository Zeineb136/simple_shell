#include "shell.h"

/*
 * shell_loop- function that read the command from standard input
 * separate the command string into a program and arguments and then 
 * execute the command
 *
 * Return: nothing
 */

void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do
	{
		printf("> ");
		line = read_standard_input();
		args = split_line(line);
		status = execute_shell(args);

		free(line);
		free(args);
	} while (status);
}
