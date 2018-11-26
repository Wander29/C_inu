#include <stdio.h>

#define DIM 10

int read_int();
int ver_cond(int *arr);

int main()
{
    int vet[DIM] = {0};
    for (size_t a = 0; a < DIM; a++)
    {
        vet[a] = read_int();
    }
    
    printf("%d\n", ver_cond(vet) );

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

int ver_cond(int *arr)
{
    for (size_t a = 1; a < DIM - 1; a++)
    {
        if (arr[a] == (arr[a+1] - arr[a-1]) )
            return a; 
    }
    return -1;
}