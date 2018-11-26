#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int dato;
    struct nodo* next;
} Nodo;

typedef Nodo* NodoPtr;

void insert( NodoPtr* currentNodoPtr, int val );
void print_list(NodoPtr currentNodoPtr);

int main() {

    NodoPtr start = NULL;
    insert(&start, 3);
    insert(&start, 1);
    insert(&start, 43);
    insert(&start, 0);
    insert(&start, 11);

    print_list(start);

    return 0;
}

void insert( NodoPtr* currentNodoPtr, int val )
{
    if ( (*currentNodoPtr) == NULL )
    {
        *currentNodoPtr = calloc(1, sizeof(Nodo));
        (*currentNodoPtr)->dato = val;
        (*currentNodoPtr)->next = NULL;
    } else if( (*currentNodoPtr)->dato > val )
    {
        NodoPtr newPtr = calloc(1, sizeof(Nodo));
        if (newPtr != NULL)
        {
            newPtr->dato = val;
            newPtr->next = *currentNodoPtr;
            *currentNodoPtr = newPtr;
        }
        /*NodoPtr new = (*currentNodoPtr);
        //new->dato = (*currentNodoPtr)->dato;
        //new->next = (*currentNodoPtr)->next;
        (*currentNodoPtr) = calloc(1, sizeof(Nodo));
        (*currentNodoPtr)->dato = val;
        (*currentNodoPtr)->next = new;*/
    } else
    {
        insert(&(*currentNodoPtr)->next, val);
    }
}

void print_list(NodoPtr currentNodoPtr)
{
    if (currentNodoPtr != NULL)
        printf("VALORE: %d\n", currentNodoPtr->dato);
    if (currentNodoPtr->next != NULL)
        print_list(currentNodoPtr->next);
}