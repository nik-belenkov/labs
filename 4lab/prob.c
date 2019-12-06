#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DL 1024

/*static int f_sort(void const* a, void const* b)
{	
	char** x = (char**)a;
	char** y = (char**)b;
	return strcmp(*x, *y);
}*/

FILE * open_file(char *name, char *mode) {
    FILE *fp;
    if ((fp = fopen(name, mode)) == NULL) {
        printf("Не удается открыть файл %s.\n", name);
        exit(1);
    }
    return fp;
}

void close_file(FILE *fp) {
    if (fclose(fp)) {
        printf("Ошибка при закрытии файла.\n");
        exit(1);
    }
}

void read_f(FILE *fp){
	char ch = 0;
	while((ch=fgetc(fp)) != EOF) {
			printf("%c\n", ch);
		}
}

void copytext_f(FILE *f_in, FILE *f_out){
	int ch;
	while ((ch = getc(f_in)) != EOF)
		putc(ch, f_out);
}

int main(int argc, char **argv)
{
    FILE *fp = 0;
    FILE *fp2 = 0;
    if (argc < 2) {
        fprintf(stderr,	"Мало аргументов. Используйте для чтения <имя файла>\n");
        fprintf (stderr, "Используйте для записи <имя файла> <Количество обрабатываемых строк> \n");
        exit(1);
    } else if(argc == 2){
		fp = open_file(argv[1], "r");
		read_f(fp);
		close_file(fp);
	} else if(argc < 3 ) {
        fprintf (stderr, "Мало аргументов. Используйте <имя файла> <Количество обрабатываемых строк>\n");
        exit (1);
    } else if (argc == 3) {
		fp = open_file(argv[1], "r");
		fp2 = open_file(argv[2], "w");
		copytext_f(fp,fp2);
		close_file(fp);
		close_file(fp2);
	}
return 0;
}
