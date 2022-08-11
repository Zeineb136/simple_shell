#include "shell.h"

/**
 * main- check the code
 *
 * Return: Always 0.
 */


int main(void)
{
char *m;

while (true)
{
	printf("$");
	m = standard_input(stdin, 16);
	printf("%s\n", m);

if (strcmp(m, "exit") == 0)
{
	exit(EXIT_FAILURE);
}
if (strcmp(m, "/bin/ls") == 0)
{
	_ls();
}
else
{
printf("./shell: No such file or directory\n");
}
free(m);
}

return (0);
}
