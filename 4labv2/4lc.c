#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

int check_sym(const char *sym){
	char isym = '.';
	for (int i = 0; i < strlen(sym); i++){
		if (strchr(sym[i], isym) != 0){
			return 1;
		}
	}
	return 0;
}

int main (int argc, char **argv)
{
    if (argc < 2){
        printf("Неверное кол-во параметров\n");
        exit(1);
    }
 
    FILE *fp, *fp2;
    char ch;
 
    if ((fp = fopen (argv[1], "r")) == NULL)
    {
        printf ("Невозможно открыть файл.\n");
        exit (1);
    }
 
   if ((fp2 = fopen (argv[2], "w")) == NULL)
    {
        printf ("Невозможно открыть файл.\n");
        exit (1);
    }

    char buffer[N];
    int len = 0;
    int maxlen = atoi (argv[3]);
 
    while ((ch = fgetc (fp)) != EOF)
    {
		
        if (ch == '\n')
        {
            if (len < maxlen)
            {
                for (int j = 0; j < len; j++)
                {
                    fputc(buffer[j], fp2);
                }
            }
            len = 0;
        }
        buffer[len] = ch;
        printf ("%c", ch);
        len++;
    
	}
    fclose (fp2);
    fclose (fp);
    return 0;
}
