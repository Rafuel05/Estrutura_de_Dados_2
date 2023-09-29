#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initHash(HashStruct *hashStruct)
{
    for (int i = 0; i< MAX; i++)
    {
        init(&(hashStruct->hashes[i]));
    }
    hashStruct->size = 0;
}
bool isHashEmpty(HashStruct *hashStruct)
{
    if (hashStruct->size = 0) return 1;
    else return 0;
}
int hash(char *key) {
    int sum = 0;
    // percorremos todos os caracteres da string passada
    for (int i = 0; key[i]!=0;i++) {
    //acumulamos os códigos ascii de cada letra com um peso
        sum+=key[i]*(i+1);
    }
    return sum%MAX; //retorna o resto da divisão
}
int put(HashStruct *hashStruct, char *key, void *data, compare equal)
{
    int put(HashStruct *hashStruct, char *key, void *data, compare equal) {
    if (!containsKey(hashStruct, key, equal) {
        //adiciona na fila que está na posição devolvida pela função hash
        int res = enqueue(&hashStruct->hashes[hash(key)],data);
        //incrementa a qtde de elementos baseado na quantidade inserida por enqueue
        hashStruct->size+=res;
        return res;
    }
    return 0;
}
}
bool containsKey(HashStruct *hashStruct, char *key, compare equal)
{
    
}