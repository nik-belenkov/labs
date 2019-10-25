#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <mcheck.h>
#define DL 1024

int string_sort(void const* a, void const* b); //для сортировки

char **func(int z) {
	char mas[DL];
	char **p_mas;
	p_mas = (char **)malloc(sizeof(char *)*z);
	for (int i = 0; i < z; i++){
		scanf("%s", mas);
		p_mas[i] = (char *)malloc(sizeof(char)*strlen(mas));
		}
	//printf("%c\n", mas[0]);
	qsort(p_mas, z, sizeof(char*), string_sort);
	for (int k = 0; k<z; k++)
	{
		printf("%s\n", p_mas[k]);
	}
	
	return p_mas;
}

void freemas(char **p_mas, int z){
	for (int i = 0; i < z; i++){
		free(p_mas[i]);	
	}
	free(p_mas);
}

int main (int argc, char *argv[]){
	int z;
	char **p_mas = NULL;
	scanf("%d\n", &z);
	//mtrace();
	p_mas = func(z);
	freemas(p_mas, z);
	return 0;
}

int string_sort(void const* a, void const* b)
{	
	char** x = (char**)a;
	char** y = (char**)b;
	return strcmp(*x, *y);
}
