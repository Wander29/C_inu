#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONE_MAX 10
const size_t DIM = DIMENSIONE_MAX;

void merge_sort(
                int a[], 
                size_t dim, 
                char order
            );

void sort(
            int a[], 
            size_t inizio, 
            size_t fine, 
            char order
        );

void merge( 
            int a[], 
            size_t start_sx, 
            size_t centro1, 
            size_t centro2, 
            size_t end_dx,
            char order
        );

void stampa_vet(int vet[]);

int main()
{
    int a[DIM];
    for (size_t i = 0; i < DIM; i++)
        a[i] = rand() % (DIM * 10);
    
    printf("Ordine Crescente <c>  o Decrescente? <d>\t  ");
    char ordine;
    scanf("%1c", &ordine);

    stampa_vet(a);
    merge_sort(a, DIM, ordine);

    stampa_vet(a);
}

void stampa_vet(int vet[])
{
    for (size_t a = 0; a < DIM; a++ )
        printf("%d ", vet[a]);
}

void merge_sort(
                int a[], 
                size_t dim, 
                char order
            )
{
    sort(a, 0, dim-1, order);
}

void sort(
            int a[], 
            size_t inizio, 
            size_t fine, 
            char order
        )
{
    if(fine - inizio >= 1)
    {
    //Non è il caso base
        size_t centro1 = (inizio + fine) / 2;
        size_t centro2 = centro1 + 1;
    //Divide l´array e ordina i due sotto array ricorsivamente
        sort(a, inizio, centro1, order);
        sort(a, centro2, fine, order);
    //Unisco i 2 sotto array già ordinata (partendo dal più piccolo)
        merge(a, inizio, centro1, centro2, fine, order);
    }
    //Caso Base: non ne ho bisogno poichè array di dim 1 sono già ordinati
}

void merge( 
            int a[], 
            size_t start_sx, 
            size_t centro1, 
            size_t centro2, 
            size_t end_dx,
            char order
        )
{
//Variabili funzione
    size_t cnt_start_sx = start_sx;
    size_t cnt_end_dx = centro2;

    size_t cnt_array = start_sx;
    size_t dim_temp_a = end_dx - start_sx + 1;
    int temp_a[cnt_end_dx - cnt_start_sx]; // array temporaneo che conterrà l'array fuso (corrente)

    while (cnt_start_sx <= centro1 && cnt_end_dx <= end_dx)
    {
        switch(order)
        {
            case 'c': //Crescente
                if (a[cnt_start_sx] <= a[cnt_end_dx])
                    temp_a[cnt_array++] = a[cnt_start_sx++];
                else    
                    temp_a[cnt_array++] = a[cnt_end_dx++];
                break;

            case 'd': //Decrescente
                if (a[cnt_start_sx] <= a[cnt_end_dx])
                    temp_a[cnt_array++] = a[cnt_end_dx++];
                else    
                    temp_a[cnt_array++] = a[cnt_start_sx++];
                break;

            default:
                break;
        }
        //se il sotto-array sx termina prima del dx
        if (cnt_start_sx == centro2)
        {
            while (cnt_end_dx <= end_dx)
                temp_a[cnt_array++] = a[cnt_end_dx++];
        }
        else{
            while (cnt_start_sx <= end_dx)
                temp_a[cnt_array++] = a[cnt_start_sx++];
        }
    }
//Copia dell'array temp in quello originale utilizzando gli inidici che già ho
    for(size_t i = start_sx; i < end_dx; i++)
        a[i] = temp_a[i];
}