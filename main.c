#include "shell.h"

/**
 * main- check the code
 *
 * Return: Always 0.
 */


int main(void)
{
char *m;
bool is_end;
while (true)
{
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
printf("./shell: No such file or directory\n");
}
printf("$");
free(m);
}

return (0);
}
