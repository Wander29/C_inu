#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SCELTE 2

struct nodo {
	int dato;
	struct nodo *prossimoPtr;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

void insert_r(NodoPtr *lPtr, int val);
void stampa_lista_r(NodoPtr cPtr);

int main(void) {
// inizialmente la lista è vuota
	Nodo n1 = {3, NULL};
	Nodo* lPtr = &n1;
	NodoPtr l2 = &n1;

	if (lPtr == l2)
		printf("Ye\n");
	printf("%p - %p\n", lPtr, l2);

	insert_r();

	stampa_lista_r();
}

void insert_r(NodoPtr *lPtr, int val) {
	if (*lPtr == NULL) {
		NodoPtr nuovoPtr = malloc(sizeof(Nodo));
		if (nuovoPtr != NULL) { // c'è spazio
		// inizializzo nodo
			nuovoPtr->dato = val;
			nuovoPtr->prossimoPtr = NULL;
			*lPtr = nuovoPtr;
		}
		else {
			puts("Memoria esaurita");
		}
	}
	else if ((*lPtr)->dato >= val) {
		NodoPtr nuovoPtr = malloc(sizeof(Nodo));

		if (nuovoPtr != NULL) { // c'è spazio
		// inizializzo nodo
			nuovoPtr->dato = val;
			nuovoPtr->prossimoPtr = *lPtr;
			*lPtr = nuovoPtr;
		}
		else {
			puts("Memoria esaurita");
		}
	}
	else {
		insert_r(&((*lPtr)->prossimoPtr), val);
	}
}

void stampa_lista_r(NodoPtr lPtr) {
	if (lPtr == NULL) {
		puts("--> NULL");
	}
	else {
		printf("--> %d ", lPtr->dato);
		stampa_lista_r(lPtr->prossimoPtr);
	}
}


 
