#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>

char *standard_input(FILE* fp, size_t size)
{
//The size is extended by the with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(*str)*size);//size is start size
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
	//While the next entry is not readable we will print directory files
	while ((d = readdir(dh)) != NULL)
	{
		//If hidden files are found we continue
		if (d->d_name[0] == '.')
			continue;
		printf("%s  ", d->d_name);
	}
	printf("\n");
}

int main(void){
    char *m;
    while(true){
        printf("$");
        m = standard_input(stdin, 0);
        if (strcmp(m, "/bin/ls") == 0)
        {
          _ls();
        }
        else /* default: */
        {
            printf("./shell: No such file or directory\n");
        }

        free(m);
    }

    return 0;
}
