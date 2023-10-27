#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "log.h"

bool comparador (void* data_1,void* data_2)
{
    if(strcmp (data_1,data_2)==0) return true;
    else return false;
}
void printar (void* data)
{
  char* string_data = (char*)data;
  if (string_data) printf("%s ",string_data);
}
void main ()
{
   log_set_level(5);
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
    }
    showHashStruct(&tabela_hash,printar);
    fclose (hash);
    printf ("\ngit stat===========\nSegunda tabela Hash\n============\n");
    FILE * hash_2;
    hash_2 = fopen ("teste.txt","r");
    HashStruct tabela_hash_2;
    initHash(&tabela_hash_2);
    if (hash_2){
        linha = (char*)malloc(sizeof(char) * 100);
      while (fscanf(hash_2,"%s \n",linha ) !=EOF  ){
  
    
      put_2 (&tabela_hash_2,linha,linha,comparador);
      linha = (char*)malloc(sizeof(char) * 100);
    }
    }
    showHashStruct(&tabela_hash_2,printar);
    fclose (hash_2);
  

}
