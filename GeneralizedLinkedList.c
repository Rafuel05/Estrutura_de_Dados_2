#include <stdlib.h>
#include <stdio.h>
#include "GenetalizedLinkedList.h"
#include "log.h"
int addAtom(Node **list, int atom)
{
    log_trace("addAtom->");
    Node *newNode = (Node*)malloc(sizeof(Node));
    node->type=0;
    newNode -> atomList.atom = atom;
    newNode ->next = NULL;

    if (*list = NULL)
    {
        *list = newNode;
    }
    else 
    {
        Node * auxNode = *list;
        while (aux->next!=NULL) auxNode = auxNode->next;
        auxNode->next = newNode;
    }
    log_trace("<-addAtom");
}
int addList(Node **list, Node **subList);
Node* head(Node *list);
Node* tail(Node *list);
void show(Node *list)
{
 printf("( ");
    Node *aux = NULL;
    for (aux = list; aux!=NULL; aux=aux->next) {
        if (aux->type==0) {
            printf("%d ",aux->atomList.atom);
        } else {
            showGeneralizedList(aux->atomList.list);
        }
    }
    printf(")");
}
boolean search(Node *list, int atom);
int depth(Node *list);