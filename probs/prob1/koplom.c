#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h> /* для mtrace */
#include <string.h>
#define MAX_LEN 1024 /* максимальная длина строки */

int string_sort(void const* a, void const* b);
int kolprob(char *mas);
int kp;

char** readMas(int count) {
    char buffer[MAX_LEN];
    char **mas;  //указатель на массив указателей на строки
    mas = (char **)malloc(sizeof(char *)*count);// выделяем память для массива указателей
    for (int i = 0; i < count ; i++) {
        fgets(buffer, MAX_LEN, stdin);
        //scanf("%s", buffer); // читаем строку в буфер
        mas[i] = (char *)malloc(sizeof(char)*strlen(buffer)); //выделяем память для строки
        strcpy(mas[i], buffer); //копируем строку из буфера в массив указателей
    }
    return mas;
}

/*void printMas(char **mas, int count){
    for (int i = 0; i < count ; i++){
        printf("%s\n", mas[i]);
    }
}*/

void freeMas(char **mas, int count) {
    for (int i = 0; i < count; i++) {
        free(mas[i]); // освобождаем память для отдельной строки
    }
    free(mas); // освобождаем памать для массива указателей на строки
}

int main(int argc, char **argv) {

    char **mas = NULL; //указатель на массив указателей на строки
    int z;
    scanf("%d\n", &z);
    int count = z;
    //mtrace();
    mas = readMas(count);
    qsort(mas, z, sizeof(char*), string_sort);
    for (int k = 0; k < z; k++)
    {
        printf("%s", mas[k]);
    }
    printf("%c\n", *(mas[z-1]));
    printf("%d\n", kp);
    //printMas(mas, count);
    freeMas(mas, count);
    return 0;
}

int string_sort(void const* a, void const* b)
{
    //char** x = (char**)a;
    //char** y = (char**)b;
    int d1 = kolprob (*(char**)a);
    int d2 = kolprob (*(char**)b);
    if (d1 != d2)
    kp++;
    return d1 - d2;

}

int kolprob(char *mas)
{
    int count = 0;
    int word = 0;
    for (int q = 0; q < strlen(mas); q++)
    {
        if(isspace(mas[q])==0) {
            if(word == 0) {
                count++;
            }
            word = 1;
        } else {
            word = 0;

        }
    }
    return count;
}
