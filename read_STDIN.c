#include "shell.h"

/**
 * read_standard_input- read line
 *
 * Return: pointer to string or error.
 */
char *read_standard_input(void)
{
	char *line = NULL;
	size_t buffer_size = 0;

	line = malloc(sizeof(char) * buffer_size);
	if (line ==  NULL)
	{
		perror("lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	write(1, "$> ", 3);
	while (getline(&line, &buffer_size, stdin) > 0)
	{
		printf("cmd = %s\n", line);
		write(1, "$> ", 3);
	}
	return (line);
}
