#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"

void initHash(HashStruct *hashStruct) {
    log_trace("Entrando em initHash");
    for (int i=0;i<MAX;i++) {
        //chamando init de DoublyLinkedList para inicializar cada lista do vetor
        log_debug("Inicializando Lista do Hash %d", i);
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
    log_trace("Saindo de initHash");
}

bool isHashEmpty(HashStruct *hashStruct) {
    return hashStruct->size==0;
}

int hash(char *key) {
    log_trace("Entrando em hash");
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    log_debug("key: %s", key);
    log_debug("sum: %d", sum);
    int hashvalue = sum%MAX;
    log_debug("Hash: %d", hashvalue);
    log_trace("Saindo de hash");
    return hashvalue; //retorna o resto da divisão
}

int put(HashStruct *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }

    log_trace("Saindo de put");
    return 0;
}

bool containsKey(HashStruct *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey");
    //calcula a posição
    int hashValue = hash(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_debug("Posição na lista %d: %d", hashValue, pos);
    log_trace("Saindo de containsKey");
    return (pos!=-1)?true:false;
}

void* get(HashStruct *hashStruct, char *key, compare equal) {
    log_trace("Entrando em get");
    // descobre em qual fila/lista está o dado
    int hashValue = hash(key);
    //first é nó sentinela, começamos do segundo nó
    Node *aux = hashStruct->hashes[hashValue].first->next;
    // procuramos o dado na lista
    while(aux!=hashStruct->hashes[hashValue].first && !equal(key, aux->data))
        aux=aux->next;

    log_debug("Nó foi localizado?: %d", aux!=hashStruct->hashes[hashValue].first);
    log_trace("Saindo de get");

    return aux->data;
}

void* removeKey(HashStruct *hashStruct, char *key, compare equal) {
    log_trace("Entrando em removeKey");
    int hashValue = hash(key);
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal);
    void* result = removePos(&hashStruct->hashes[hashValue], pos);
    if (result!=NULL) hashStruct->size--;
    log_trace("Saindo de removeKey");
    return result;
}

void showHashStruct(HashStruct *hashStruct, printNode print) {
    log_trace("Entrando em showHashStruct");
    printf("There are %d elements in the Hash\n\n",hashStruct->size);
    for (int i=0; i < MAX; i++) {
        printf("Hash %d has %d elements: ",i,hashStruct->hashes[i].size);
        show(&hashStruct->hashes[i],print);
        printf("\n");
    }
    log_trace("Saindo showHashStruct");
}
int put_2(HashStruct *hashStruct, char *key, void *data, compare equal)  {
    log_trace("Entrando em put_2");
    log_info("Adicionando novo elemento no Hash");
    if (!containsKey_2(hashStruct, key, equal)) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash_2(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }

    log_trace("Saindo de put");
    return 0;
}
bool containsKey_2(HashStruct *hashStruct, char *key, compare equal) {
    log_trace("Entrando em containsKey_2");
    //calcula a posição
    int hashValue = hash_2(key);
    //busca na fila a posição da chave
    int pos = indexOf(&hashStruct->hashes[hashValue], key, equal); 
    log_debug("Posição na lista %d: %d", hashValue, pos);
    log_trace("Saindo de containsKey_2");
    return (pos!=-1)?true:false;
}
int hash_2(char *key) {
    log_trace("Entrando em hash_2");
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
         //acumulamos os códigos ascii de cada letra com um peso
        sum += (key[i]) * (i + 3);
    }
    log_debug("key: %s", key);
    log_debug("sum: %d", sum);
    int hashvalue = sum%MAX;
    log_debug("Hash: %d", hashvalue);
    log_trace("Saindo de hash_2");
    return hashvalue; //retorna o resto da divisão
}



void createCollisionImage(const HashStruct *hashStruct, const char *filename) {
    FILE *imageFile = fopen(filename, "w");

    if (imageFile) {
        int max_density = 0;

        // Encontre a densidade máxima na tabela
        for (int i = 0; i < MAX; i++) {
            int density = hashStruct->hashes[i].size;
            max_density = (density > max_density) ? density : max_density;
        }

        // Escreva o cabeçalho PPM no arquivo
        fprintf(imageFile, "P3\n");
        fprintf(imageFile, "32 32\n"); // Largura (32) x Altura (32)
        fprintf(imageFile, "255\n");   // Valor máximo de cor

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                int density = hashStruct->hashes[i * 32 + j].size;

                // Calcule o valor de cor com base na densidade de colisões
                int color = (int)((density / (double)max_density) * 255);

                // Escreva o valor de cor no arquivo PPM
                fprintf(imageFile, "%d 0 0 ", color);
            }
        }

        fclose(imageFile);
        printf("Imagem PPM gerada com sucesso: %s\n", filename);
    } else {
        printf("Erro ao criar o arquivo de imagem PPM.\n");
    }
}








