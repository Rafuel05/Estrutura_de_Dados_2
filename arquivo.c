#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int number = 10;
    int *numberP = &number;
    printf ("Valor da variavel number : %d \n", number);
    printf ("Endereço da variavel number: %p \n", &number);
    printf ("Valor da variavel numberP: %p\n",numberP);
    printf ("Valor apontado por numberP: %d\n\n", *numberP);
    

    return EXIT_SUCCESS; 
}