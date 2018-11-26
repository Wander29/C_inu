#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_int();
bool read_seq(int first);

int main()
{
    printf( read_seq(read_int() ) ? "Sequenza in ordine strettamente crescente\n" : "Sequenza non in ordine strettamente crescente\n" );
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1)
    {
        printf("Errore.  Inserire un numero intero positivo oppure un numero intero negativo per terminare\n");
        while(getchar() != '\n');
    }
    return temp;
}

bool read_seq(int first)
{
    int x = read_int();

    if (x < 0)
        return true;
    
    if (x > first)
        return read_seq( x );
    else    
        return false;
}
