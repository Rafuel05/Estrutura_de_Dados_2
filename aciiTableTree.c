#include <stdio.h>
#include <stdlib.h>
#define ASCII_SIZE 128 // Tamanho da tabela ASCII

typedef struct Vetor {
    int contador;
    char caracter; 
}Vetor;

typedef struct Node {
    int contador;
    char caracter;
    struct Node *esquerda;
    struct Node *direita;
} Node;

Node *novoNo(int contador, char caracter) {
    Node *novo = (Node *)malloc(sizeof(Node));
    novo->contador = contador;
    novo->caracter = caracter;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void ordenarVetorDecrescente(Vetor vetor[], int tamanho) {
    int i, j;
    Vetor temp;

    for (i = 1; i < tamanho; i++) {
        temp = vetor[i];
        j = i - 1;

        while (j >= 0 && vetor[j].contador < temp.contador) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = temp;
    }
}
Node *construirArvoreHuffman(Vetor vetor[]) {
    int tamanho = ASCII_SIZE;
    ordenarVetorDecrescente(vetor, tamanho);

    Node *raiz = NULL;
    Node *esquerda, *direita, *novo;

    while (tamanho > 1) {
        esquerda = novoNo(vetor[tamanho - 1].contador, vetor[tamanho - 1].caracter);
        direita = novoNo(vetor[tamanho - 2].contador, vetor[tamanho - 2].caracter);

        novo = novoNo(esquerda->contador + direita->contador, '\0');
        novo->esquerda = esquerda;
        novo->direita = direita;

        tamanho--;

        vetor[tamanho - 1].contador = novo->contador;
        vetor[tamanho - 1].caracter = novo->caracter;

        ordenarVetorDecrescente(vetor, tamanho);
    }

    raiz = novoNo(vetor[0].contador, vetor[0].caracter);
    return raiz;
}

void imprimirArvore(Node *raiz) {
    if (raiz != NULL) {
        printf("Caracter: %c | Contador: %d\n", raiz->caracter, raiz->contador);
        imprimirArvore(raiz->esquerda);
        imprimirArvore(raiz->direita);
    }
}

int main() {
    FILE *arquivo;
    char nome_arquivo[] = "arquivo.txt"; // Nome do arquivo a ser lido
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
            printf("Caractere: %c | Repetiçoes: %d\n", vetor[i].caracter, vetor[i].contador);
        }
    }
     Node *raiz = construirArvoreHuffman(vetor);

    printf("Árvore de Huffman:\n");
    imprimirArvore(raiz);
    // Exibindo o resultado
    

    return EXIT_SUCCESS;
}