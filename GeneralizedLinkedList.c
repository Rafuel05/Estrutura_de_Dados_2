#include <stdlib.h>
#include <stdio.h>
#include "GenetalizedLinkedList.h"
#include "log.h"
int addAtom(Node **list, int atom)
{
    log_trace("addAtom->");
    Node *newNode = (Node*)malloc(sizeof(Node));
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
    log_trace ("addList->");
    printf("(");
    Node *auxNode = list;
    while (auxNode!=NULL){
         printf(" %d",auxNode->atomList.atom);
        auxNode = auxNode -> next;
    }
    printf(")");
    log_trace ("<-addList");
}
boolean search(Node *list, int atom);
int depth(Node *list);