#include <stdio.h>
#include <stdlib.h>
#define TAMANHO 2
int i;
int **matriz;
int main ()
{
    int number = 10;
    int *numberP = &number;
    int **numberPP = &numberP;
    printf("number = %d\n*numberP = %d\n**numberPP = %d\n",number,*numberP,**numberPP);
    printf("-----------------\n");
    matriz = (int **) malloc(sizeof(int *) * TAMANHO);
    if (matriz == NULL) {
        printf("Erro ao alocar memória");

    free(matriz);
    }

    for (i = 0; i < TAMANHO; i++) {
        *(matriz+i) = (int *) malloc(TAMANHO * sizeof(int));
        if (*(matriz+i) == NULL) {
            printf("Erro ao alocar memória");
            free(matriz);
        }
    }

    *(*(matriz+0)+0) = 1; // = matriz[0][0] = 1;
    *(*(matriz+0)+1) = 2; // = matriz[0][1] = 2;
    *(*(matriz+1)+0) = 3; // = matriz[1][0] = 3;
    *(*(matriz+1)+1) = 4; // = matriz[1][1] = 4;

    printf("%d %d\n", matriz[0][0], matriz[0][1]);
    printf("%d %d\n", matriz[1][0], matriz[1][1]);
    *matriz = 0;
    free(matriz);
    matriz = NULL;
}