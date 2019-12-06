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

void close_file(FILE *fp) {
    if (fclose(fp)) {
        printf("Ошибка при закрытии файла.\n");
        exit(1);
    }
}

FILE * open_file(char *name, char *mode) {
    FILE *fp;
    if ((fp = fopen(name, mode)) == NULL) {
        printf("Не удается открыть файл %s.\n", name);
        exit(1);
    }
    return fp;
}

int main(int argc, char **argv)
{
    char buffer[DL];
    char buff[DL];
    FILE *fp = 0;
		fp = open_file(argv[1], "r");
		//int ch = 0;
		//int count = 0;
		//scanf("%d", &count);
		//while((ch=fgetc(fp)) != EOF){
		while (feof(fp) == 0){
			fscanf(fp, "%s", buffer);
			strcpy(buff, buffer);
			//qsort(buff,DL,sizeof(char),f_sort);
			printf("%s\n",buff);
		}
	//}
		close_file(fp);
	
return 0;

}
