#include "shell.h"

char *standard_input(FILE* fp, size_t size)
{
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);
    if(!str)return str;
    while(EOF!=(ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(*str)*(size+=16));
            if(!str)return str;
        }
    }
    str[len++]='\0';

    return realloc(str, sizeof(*str)*len);
}

void _ls()
{
    char cwd[PATH_MAX];
	char* dir =getcwd(cwd, sizeof(cwd));

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
