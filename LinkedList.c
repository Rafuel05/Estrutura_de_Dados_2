#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

void init(LinkedList *list) {
    log_trace("init->");
    log_info("inciando a lista");
    list->first=NULL; //aponta o inicio de lista 
    list->size=0;     //tamanho da lista = 0
    log_debug("list->first = %p", list->first);
    log_debug("list->size = %d",list->size);
    log_trace("<-init");
}

int enqueue(LinkedList *list, void *data) {
    log_trace("enqueue->");
    log_info("enfileirando");
    Node *newNode = (Node*)malloc(sizeof(Node)); //aloca memoria para o novo nó
    if (newNode==NULL) {
    log_debug("newNode: %p", newNode);    
    log_warn("não foi possivel alocar memoria");
    log_trace("<-enqueue");
    return -1;
    } 
    newNode ->data = data; //coloca o conteudo passado dentro do no
    newNode ->next = NULL; // aponta o ponteiro next (ou prox elemento), vai ser null 
    log_debug("newNode->data = %p",newNode->data);
    log_debug("newNode->next = %p", newNode->next);

    if (isEmpty (list))
    {
         list -> first = newNode; //caso a fila estiver vazia, o novo nó é o primeiro
         log_debug("list->first = %p",list->first); 
    }
    else {
    Node *aux = list -> first; //auxiliar recebe o primeiro elemento atual
    log_debug("aux = list ->first = %p",aux); 
    while (aux->next != NULL){ //enquanto não for o último nó
        aux = aux ->next;      //aux avança para o nó seguinte
        log_debug("aux = aux->next = %p", aux); 
        }
        aux ->next = newNode;  //ultimo nó aponta para o novo nó
    }

    list->size++;              //tamanho da lista atualizada 
    return 1;                  //deu certo
    log_info("enfileiramento executado com sucesso");
    log_trace("<-enqueue");
}
bool isEmpty(LinkedList *list) {
    log_trace("isEmpty->");
    return (list->size==0);
    log_trace("<-isEmpty");
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
        }
        return auxNode->data; 
    }
}
