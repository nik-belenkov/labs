#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define N 1024

void rename_file(char src[], char dest[], char *needle, char *text){
	int c = strcspn(src, needle);
    strncpy(dest, src, c);
    strcat(dest, text);
}

int check_str(char *str){
	for (int i = 0; i < strlen(str); i++){
		if (isdigit(str[i]) != 0) {
				return 1;
		}
	}
	return 0;
}

int main (int argc, char **argv)
{
    char str2[N];
    
    if (argc < 2) {
        printf("Неверное кол-во параметров\n");
        exit(1);
    }

    FILE *fp, *fp2;
    if ((fp = fopen (argv[1], "r")) == NULL)
    {
        printf ("Невозможно открыть файл.\n");
        exit (1);
    }
	rename_file(argv[1], str2, ".", ".out");
    if ((fp2 = fopen (str2, "w")) == NULL)
    {
        printf ("Невозможно открыть файл.\n");
        exit (1);
    }

    char buffer[N];
    int maxlen = atoi (argv[2]);
	int i = 0;
    while(!feof(fp)) {
        memset(buffer, '\0',N);
        if(fgets(buffer, N, fp))
        {
            if (check_str(buffer) == 0)
            {
				if (i++>=maxlen) break;
                fputs(buffer, fp2);
                printf("%s", buffer);
            }
        }
    }
    fclose (fp2);
    fclose (fp);
    return 0;
}
