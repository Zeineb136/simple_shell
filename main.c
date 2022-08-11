#include "shell.h"

/**
 * main- check the code
 *
 * Return: Always 0.
 */


int main(int argc, char *argv[])
{
char *m;
bool is_end;
(void)argc;
while (true)
{
	printf("$");
	m = standard_input(stdin, 0, &is_end);
if (strcmp(m, "/bin/ls") == 0)
{
	_ls();
}
else
if (strcmp(m, "exit") == 0 || is_end)                                                                                                                                     

{                                                                                                                                                                         

	                free(m);                                                                                                                                                  

			                exit(EXIT_FAILURE);                                                                                                                                  
}    
else
{
printf("%s: No such file or directory\n", argv[0]);
}
free(m);
}

return (0);
}
