#include <stdio.h>
#include <stdlib.h>
struct igri{
    char name[50];
    char game[50];
    int points;
    int sumpriz;
};
typedef struct igri games;
 
void readGame(games *gm){
    //printf("Название команды:");
    scanf("%s", gm->name);
    //printf("Название игры:");
    scanf("%s", gm->game);
    //printf("Введите очки:");
    scanf("%d", &gm->points);
    //printf("Введите сумму призового фонда:");
    scanf("%d", &gm->sumpriz);
}

static int game_sort(const void *p1, const void *p2){
    games * gm1 = *(games**)p1;
    games * gm2 = *(games**)p2;
    return gm2->sumpriz - gm1->sumpriz;
}

int main(int argc, char **argv){
    int count = 0;
    //printf("Введите количество команд:");
    scanf("%d", &count);
    games** gm = (games**)malloc(sizeof(games*)*count);
    for (int i = 0; i < count ; i++){
        gm[i] = (games*) malloc (sizeof(games));
        readGame(gm[i]);
    } 
    qsort(gm, count, sizeof(games*), game_sort);
    for (int l = 0; l < count; l++) 
    {
    printf("Название команды:%s\n", gm[l]->name);
    printf("Название игры:%s\n", gm[l]->game);
    printf("Очки:%d\n", gm[l]->points);
    printf("Сумма призового фонда:%d\n", gm[l]->sumpriz);
    printf("\n");
	}
    for (int i = 0; i < count; i++)
    {
        free(gm[i]);
    }
    free(gm);
    return 0;
}
