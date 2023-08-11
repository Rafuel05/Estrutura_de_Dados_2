#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void init(LinkedList *list) {
    list->first=NULL;
    list->size=0;
}

int enqueue(LinkedList *list, void *data) {
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    if (newMode==NULL) return -1;
    newNode ->data = data;
    newNode ->next = NULL;

    if (isEmpty (list)) list -> first = NewNode; //caso a fila estiver vazia, o novo nó é o primeiro 
    else {
    Node *aux = list -> first; //auxiliar recebe o primeiro elemento atual 
    while (aux->next != NULL){ //enquanto não for o último nó
        aux = aux ->next;      //aux avança para o nó seguinte 
        }
        aux ->next = newNode;  //ultimo nó aponta para o novo nó
    }


}
bool isEmpty(LinkedList *list) {
    return (list->size==0);
}

