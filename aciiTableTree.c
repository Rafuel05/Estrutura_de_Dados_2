#include <stdio.h>
#include <stdlib.h>
#define ASCII_SIZE 128 // Tamanho da tabela ASCII

typedef struct Vetor {
    int contador;
    char caracter; 
}Vetor;

int main() {
    FILE *arquivo;
    char nome_arquivo[] = "teste.txt"; // Nome do arquivo a ser lido
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

    // Exibindo o resultado
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (vetor[i].contador > 0) {
            printf("Caractere: %c | Contador: %d\n", vetor[i].caracter, vetor[i].contador);
        }
    }

    return EXIT_SUCCESS;
}
