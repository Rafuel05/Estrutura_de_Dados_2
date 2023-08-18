#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "log.h"

bool compara(void *data1, void *data2) {
    int *d1 = (int*)data1;
    int *d2 = (int*)data2;
    
    return (*d1==*d2)?true:false;
}

int main() {
	FILE *file = fopen("program.log","w");
	
	log_set_level(LOG_INFO);
	log_add_fp(file, LOG_TRACE);
	
	LinkedList lista;
	init(&lista);

	int *numero = malloc(sizeof(int));
	*numero = 10;
	enqueue(&lista, numero);
	numero = malloc(sizeof(int));
	*numero = 20;
	enqueue(&lista, numero);
	numero = malloc(sizeof(int));
	*numero = 30;
	enqueue(&lista, numero);	

    //printf("indexOf(30): %d\n",indexOf(&lista,numero,compara));

	numero = (int*)dequeue(&lista);
	printf("%d removido\n", *numero);
	numero = (int*)dequeue(&lista);
	printf("%d removido\n", *numero);	
	dequeue(&lista);

	return EXIT_SUCCESS;
}