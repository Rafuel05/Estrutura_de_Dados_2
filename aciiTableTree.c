#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#define ASCII_SIZE 128 // Tamanho da tabela ASCII
char nome_arquivo[] = "arquivo.txt"; // Nome do arquivo a ser lido

typedef struct Vetor {
    int contador;
    char caracter; 
    struct Vetor* esquerda;
    struct Vetor* direita;
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
            if (vetor[i].caracter != '\n') //printf("Caractere: space | Repetiçoes: %d\n",vetor[i].contador);
           // else
            printf("Caractere: %c | Repetiçoes: %d\n", vetor[i].caracter, vetor[i].contador);
        }
    }

    LinkedList lista,auxList;
    init(&lista);
    init(&auxList);

    
    for (int i = 0; i < ASCII_SIZE; i++) {
         if (vetor[i].contador > 0 && vetor[i].caracter!='\n') {
            Vetor *ch= malloc(sizeof(Vetor));
            *ch = vetor[i];
            enqueue(&lista,ch);
         }
        }
    int cnt = 0;
    while ( lista.size != 1) {
        cnt++;
        Vetor *ch_1= malloc(sizeof(Vetor));
        Vetor *ch_2 = malloc(sizeof(Vetor));
        ch_1=dequeue(&lista);
        ch_2= dequeue(&lista);
        struct Vetor* novoNo = (struct Vetor*)malloc(sizeof(struct Vetor));
       // char str1[2]; 
       // char str2[2];
       // str1[0] = ch_1->caracter;
       // str1[1] = '\0';
       // str1[0] = ch_2->caracter;
       // str1[1] = '\0';
        novoNo->contador = ch_1->contador + ch_2->contador;
       // strcat(str1, str2);
       // novoNo->caracter = str1[0];
       // printf( "%c - ", novoNo->caracter);
        printf ("interaçao:N. %d -> %d   \n",cnt,novoNo->contador);
        novoNo->esquerda = ch_1;
        novoNo->direita = ch_1;
        enqueue(&lista,novoNo);
    }

        /*
        Vetor *ch_1= malloc(sizeof(Vetor));
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