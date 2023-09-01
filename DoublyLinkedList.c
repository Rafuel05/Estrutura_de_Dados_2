#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

bool isEmpty(DoublyLinkedList *list) 
{
    log_trace("isEmpty->");
    return (list->size==0);
    log_trace("<-isEmpty");
}

void init(DoublyLinkedList *list) {
    log_trace("init->");
    log_info("Iniciando lista duplamente ligada");
    Node *trashNode = (Node*)malloc(sizeof(Node));
    trashNode->data=NULL;
    trashNode->previous=trashNode;
    trashNode->next=trashNode;
    list->first=trashNode;
    list->size=0;
    log_info("Lista inciada com sucesso");
    log_trace("<-init");
}
int enqueue(DoublyLinkedList *list, void *data)
{
    log_trace("enqueue->");
    Node *newNode = (Node*) malloc (size(Node));
    if (newNode = NULL);
    {
        log_warn("sem memoria para alocamento");
        log_trace("<-enqueue");
        return -1;
    }
    newNode->data = data;
    newNode->next = list->first;
    newNode->previous = list->first->previous;
    list->first->previous->next = newNode;
    list->fisrt->previous= newNode;
    list->size++;
    log_trace("<-enqueue");
    return 1;
}
void* dequeue(DoublyLinkedList *list)
{
    log_trace("dequeue->");
    log_info("removendo elemento da lista");
    if(isEmpty(list)) return -1;
    Node *trash = list -> first;
    Node *first = list -> first -> next;
    first -> next -> previous = trash;
    trash -> next = first -> next;
    void *data = first -> data;
    free(first);
    list->size--;
    log_info ("elemento %p removido da lista",data);
    log_trace("<-dequeue");
    return data;
}