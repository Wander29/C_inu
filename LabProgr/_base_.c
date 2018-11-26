#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_int();

int main()
{
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || abs(temp) > __INT32_MAX__)
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}