#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int number = 10;
    int *numberP = &number;
    printf ("Valor da variavel number : %d \n", number);
    printf ("Endereço da variavel number: %p \n", &number);
    printf ("Valor da variavel numberP: %p\n",numberP);
    printf ("Valor apontado por numberP: %d\n", *numberP);
    numberP++;
    printf ("Valor da variavel numberP att: %p\n",numberP);
    printf ("Valor apontado por numberP att: %d\n", *numberP);
    printf("-------------------\n");
    float *pi = (float *) malloc(sizeof(float));
    printf ("Valor da variavel pi: %p \n",pi);
    *pi = 1234.2;
    printf ("Valor no endereço apontado: %.2f \n", *pi);
    *pi=0;
    free(pi);
    pi = NULL;
    printf ("Valor da variavel pi: %p \n",pi);
    printf("-------------------\n");
    int *numbers = (int*) malloc (sizeof(int) * 3);
    *(numbers+0) = 0; // = numbers[0] = 0;
    *(numbers+1) = 1; // = numbers[1] = 1;
    *(numbers+2) = 2; // = numbers[2] = 2;
    for (int i =0; i<3; i++)
    printf ("numbers[%d] = %d\n",i,numbers[i]);
    for (int i=0; i<3; i++)
    printf ("*(numbers + %d ) = %d\n",i,*(numbers+i));
    int *aux = numbers;
    for (int i = 0; i<3; i++)
    {
        printf ("*aux = %d \n",*aux);
        aux++;
    }
    

    return EXIT_SUCCESS; 
}