#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

bool comparador (void* data1,void* data2)
{
    if(strcmp (data1,data2)==0) return true;
    else return false;
}
void printar (void* data)
{
  printf("%s",*((char*)data));
}
void main ()
{
    FILE * hash;
    char *linha;
    hash = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct tabela_hash;
    initHash(&tabela_hash);
    if (hash){
        linha = (char*)malloc(sizeof(char) * 100);
      while (fscanf(hash,"%s \n",linha ) !=EOF  ){
       //printf ("%s \n",linha);
    
      put (&tabela_hash,linha,linha,comparador);
      linha = (char*)malloc(sizeof(char) * 100);
    }
    showHashStruct(&tabela_hash,printar);
    fclose (hash);
}
}
