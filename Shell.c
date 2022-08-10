#include "shell.h"
/**
 *standard_input - read command line
 *@fp: input string
 *@size: size of input
 *
 *Return: nothing
 */
char *standard_input(FILE *fp, size_t size)
{
	char *str;
	int ch;
	size_t len = 0;

	str = realloc(NULL, sizeof(*str) * size);
	if (!str)
		return (str);
	while (EOF != (ch = fgetc(fp)) && ch != '\n')
	{
		str[len++] = ch;
	if (len == size)
	{
		str = realloc(str, sizeof(*str) * (size += 16));
		if (!str)
			return (str);
	}
	}
	str[len++] = '\0';
	return (realloc(str, sizeof(*str) * len));
}
/**
 *_ls()- function that give the list files or directories
 *
 *Return: nothing
 */
void _ls(void)
{
	char cwd[PATH_MAX];
	char *dir = getcwd(cwd, sizeof(cwd));

	struct dirent *d;
	DIR *dh = opendir(dir);

	while ((d = readdir(dh)) != NULL)
	{
		if (d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
	}
	printf("\n");
}
