#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#define ASCII_SIZE 128 // Tamanho da tabela ASCII
char nome_arquivo[] = "arquivo.txt"; // Nome do arquivo a ser lido

typedef struct Vetor {
    int contador;
    char caracter; 
}Vetor;

void ordenarVetorDecrescente(Vetor vetor[], int tamanho) {
    int i, j;
    Vetor temp;

    for (i = 1; i < tamanho; i++) {
        temp = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j].contador > temp.contador) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = temp;
    }
}

int main() {
    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "r");

    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    Vetor vetor[ASCII_SIZE] = {0}; // Inicializa o vetor de contadores

    int c;
    while ((c = fgetc(arquivo)) != EOF) {
        vetor[c].contador++; // Incrementa o contador do caractere lido
        vetor[c].caracter = (char)c; // Armazena o caractere
    }

    fclose(arquivo);

     ordenarVetorDecrescente(vetor, ASCII_SIZE);

for (int i = 0; i < ASCII_SIZE; i++) {
        if (vetor[i].contador > 0) {
            if (vetor[i].caracter == '\n') printf("Caractere: space | Repetiçoes: %d\n",vetor[i].contador);
            else
            printf("Caractere: %c | Repetiçoes: %d\n", vetor[i].caracter, vetor[i].contador);
        }
    }

    LinkedList lista;
    init(&lista);
    
    for (int i = 0; i < ASCII_SIZE; i++) {
         if (vetor[i].contador > 0) {
            Vetor *ch= malloc(sizeof(Vetor));
            *ch = vetor[i];
            enqueue(&lista,ch);
         }
        }
        
       /* Vetor *ch_1= malloc(sizeof(Vetor));
        Vetor *ch_2 = malloc(sizeof(Vetor));
        Vetor *ch_3 = malloc(sizeof(Vetor));
        ch_1=dequeue(&lista);
        printf("%c removido\n", ch_1->caracter);
        ch_2= dequeue(&lista);
        printf("%c removido\n", ch_2->caracter);
        ch_3=dequeue(&lista);
        printf("%c removido\n", ch_3->caracter);
        */
    

    return EXIT_SUCCESS;
}