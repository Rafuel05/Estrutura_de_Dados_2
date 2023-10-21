#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

bool comparador (void* data_1,void* data_2)
{
    if(strcmp (data_1,data_2)==0) return true;
    else return false;
}
void printar (void* data)
{
  char* string_data = (char*)data;
  if (string_data) printf("%s",string_data);
}
void main ()
{
    FILE * hash;
    char *linha;
    hash = fopen ("teste.txt","r");
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
