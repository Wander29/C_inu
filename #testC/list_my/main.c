#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int a;
    struct nodo* next;
} Nodo;

//typedef Nodo* NodoPtr;

void insert(Nodo** currentNodoPtr, int val);
void stampa_list(Nodo* currentNodoPtr);

int main() {
    Nodo* start = NULL;
    insert(&start, 1);

    insert(&start, 2);

    insert(&start, 3);

    stampa_list(start);
    return 0;
}

void insert(Nodo** currentNodoPtr, int val)
{
    if (currentNodoPtr == NULL) {
        *currentNodoPtr = calloc(1, sizeof(Nodo));
        (*currentNodoPtr)->a = val;
        (*currentNodoPtr)->next = NULL;
    } else  {
        if((*currentNodoPtr)->a > val) {
            Nodo newNodo = **currentNodoPtr;
            (*currentNodoPtr)->a = val;
            (*currentNodoPtr)->next = &newNodo;
        } else {
            if((*currentNodoPtr)->next != NULL){
                insert(&(*currentNodoPtr)->next, val);
            } else {
                Nodo newNodo = {val, NULL};
                (*currentNodoPtr)->next = &newNodo;
            }
        }
    }
}

void stampa_list(Nodo* currentNodoPtr)
{
    printf("NUMERO: %d\n", currentNodoPtr->a);
    if(currentNodoPtr->next != NULL)
        stampa_list(currentNodoPtr->next);
}