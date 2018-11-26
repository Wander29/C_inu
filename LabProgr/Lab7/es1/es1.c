#include <stdio.h>

#define DIM 10

int read_int();

int main()
{
    int vet[DIM] = {0};
    for (size_t a = 0; a < DIM; a++)
    {
        vet[a] = read_int();
    }
    //printf("%d\n", vet[DIM-1]);
    
    for (short b = DIM - 1; b >= 0; b--)
    {
        printf("%d\n", vet[b] % 2 == 0 ? vet[b]/2 : vet[b] );
    }
    return 0;
}

int read_int()
{
    int temp = 0;
    while (scanf("%d", &temp) != 1)
    {
        while(getchar() != '\n');
    }
    return temp;
}