#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
    list->first=NULL; //aponta o inicio de lista 
    list->size=0;     //tamanho da lista = 0
}

int enqueue(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node));  //aloca memoria para o novo nó
    if (newNode==NULL) return -1; //caso de erro e nao tenha memoria necessaria para alocar um novo nó
    newNode ->data = data; //coloca o conteudo passado dentro do no
    newNode ->next = NULL; // aponta o ponteiro next (ou prox elemento), vai ser null 

    if (isEmpty (list)) list -> first = newNode; //caso a fila estiver vazia, o novo nó é o primeiro 
    else {
    Node *aux = list -> first; //auxiliar recebe o primeiro elemento atual 
    while (aux->next != NULL){ //enquanto não for o último nó
        aux = aux ->next;      //aux avança para o nó seguinte 
        }
        aux ->next = newNode;  //ultimo nó aponta para o novo nó
    }

    list->size++;              //tamanho da lista atualizada 
    return 1;                  //deu certo
}
bool isEmpty(LinkedList *list) {
    return (list->size==0);
}

void* dequeue(LinkedList *list)
{
    if (isEmpty(list)) return NULL; //se a lista estiver vazia    
    Node *trash = list -> first; // trash (elemento lixeira) recebe o primeiro elemento 
    list ->first = list ->first ->next;  // o primeiro elemento se torna o next (2)
    void *data = trash -> data; //joga o elemento do nó no lixo
    list ->size--; //att o tamanho da lista
    free (trash); // limpa o lixo
    return data;  
}

void* first(LinkedList *list) //descobre o primeiro elemento 
{
  if (isEmpty(list)) return NULL; 
  else return list ->first->data; //devolve o elemento guardado no primeiro nó
}

void* last(LinkedList *list)
{
    if (!isEmpty(list)) //se a lista n estiver vazia 
    {
        Node *auxNode = list ->first; //nó auxiliar recebe o ponteiro do primeiro nó
        while (auxNode->next != NULL)
        {
            auxNode = auxNode -> next; //ponteiro auxiliar recebe o prox elemento 
            data = auxNode -> data;    // troca o elemento atual pelo prox 
        }
        return data; 
    }
}
int push(LinkedList *list, void *data)
{
    
}