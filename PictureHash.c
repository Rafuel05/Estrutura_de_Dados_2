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
    }
    fclose (hash);
    FILE * hash_2;
    hash_2 = fopen ("ListaDePalavrasPT.txt","r");
    HashStruct tabela_hash_2;
    initHash(&tabela_hash_2);
    if (hash_2){
        linha = (char*)malloc(sizeof(char) * 100);
      while (fscanf(hash_2,"%s \n",linha ) !=EOF  ){
      put_2 (&tabela_hash_2,linha,linha,comparador);
      linha = (char*)malloc(sizeof(char) * 100);
    }
    }
    createCollisionImage(&tabela_hash, "PictureTableHash_1.ppm");
    createCollisionImage(&tabela_hash_2, "PictureTableHash_2.ppm");
    fclose (hash_2);
}
void createCollisionImage(const HashStruct *hashStruct, const char *filename) {
    FILE *imageFile = fopen(filename, "w");
    if (imageFile) {
        int max_density = 0;

        // Encontra a densidade máxima na tabela
        for (int i = 0; i < MAX; i++) {
            int density = hashStruct->hashes[i].size;
            max_density = (density > max_density) ? density : max_density;
        }

        // Escreve o cabeçalho PPM no arquivo
        fprintf(imageFile, "P3\n");
        fprintf(imageFile, "32 32\n"); // Largura  x Altura 
        fprintf(imageFile, "255\n");   // Valor máximo de cor

        for (int i = 0; i < 32; i++) {
            for (int j = 0; j < 32; j++) {
                int density = hashStruct->hashes[i * 32 + j].size;

                // Calcule o valor de cor com base na densidade -> colisões
                int color = (int)((density / (double)max_density) * 255);

                // Escreve o valor de cor no arquivo PPM
                fprintf(imageFile, "%d 0 100 ", color);
            }
        }

        fclose(imageFile);
        printf("Imagem PPM gerada com sucesso: %s\n", filename);
    } else {
        printf("Erro ao criar o arquivo de imagem PPM.\n");
    }
}