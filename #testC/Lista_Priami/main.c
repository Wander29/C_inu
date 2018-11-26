#include <stdio.h>
#include <stdlib.h>
#define SCELTE 2
struct nodo {
    int dato;
    struct nodo *prossimoPtr;
};

typedef struct nodo Nodo;
typedef Nodo *NodoPtr;

void menu(short *scelta);
void insert(NodoPtr *lPtr, int val);
void delete(NodoPtr *lPtr, int val);
int is_empty(NodoPtr lPtr);
void stampa_lista(NodoPtr cPtr);

int main(void) {
// inizialmente la lista è vuota
    Nodo *lPtr = NULL;
    int val;
    short scelta;
    menu(&scelta);
    while (scelta >= 0 && scelta <= SCELTE - 1) {
        printf("Valore da inserire o cancellare: ");
        while (scanf("%d", &val) != 1) {
            printf("Valore da inserire o cancellare: ");
            while (getchar() != '\n');
        }
        void (*f[SCELTE])(NodoPtr *, int) = {insert, delete};
        (*f[scelta])(&lPtr,val);
        menu(&scelta);
    }
    stampa_lista(lPtr);
}
void menu(short *scelta) {
    printf("0. Inserisci un nodo\n"
           "1. Cancella un nodo\n"
           "qualsiasi altro numero per uscire\n"
           "? ");
    while (scanf("%hd", scelta) != 1) {
        printf("Scelta? ");
        while (getchar() != '\n');
    }
}

void insert(NodoPtr *lPtr, int val) {
// alloco nuovo nodo
    NodoPtr nuovoPtr = malloc(sizeof(Nodo));
    if (nuovoPtr != NULL) { // c'è spazio
// inizializzo nodo
        nuovoPtr->dato = val;
        nuovoPtr->prossimoPtr = NULL;
        NodoPtr precedentePtr = NULL;
        NodoPtr correntePtr = *lPtr;
        while (correntePtr != NULL && val > correntePtr->dato) {
            precedentePtr = correntePtr;
            correntePtr = correntePtr->prossimoPtr;
        }
        if (precedentePtr == NULL) {
            // inserimento all'inizio della lista
            nuovoPtr->prossimoPtr = *lPtr;
            *lPtr = nuovoPtr;
        }
        else { // inserimento tra due nodi
            precedentePtr->prossimoPtr = nuovoPtr;
            nuovoPtr->prossimoPtr = correntePtr;
        }
    }
    else {
        puts("Memoria esaurita");
    }
}

void delete(NodoPtr *lPtr, int val) {
    if (val == (*lPtr)->dato) {
        NodoPtr tempPtr = *lPtr;
        *lPtr = (*lPtr)->prossimoPtr;
        free(tempPtr);
    }
    else {
        NodoPtr precedentePtr = *lPtr;
        NodoPtr correntePtr = (*lPtr)->prossimoPtr;
        while (correntePtr != NULL && correntePtr->dato != val) {
            precedentePtr = correntePtr;
            correntePtr = correntePtr->prossimoPtr;
        }
        if (correntePtr != NULL) {
            NodoPtr tempPtr = correntePtr;
            precedentePtr->prossimoPtr = correntePtr->prossimoPtr;
            free(tempPtr);
        }
    }
}

