#include <stdio.h>
#include <limits.h>

#define DIM 10

int read_int();
void min_azzera(int *arr);

int main()
{
    int vet[DIM] = {0};
    for (size_t a = 0; a < DIM; a++)
    {
        vet[a] = read_int();
    }
    min_azzera(vet);
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

void min_azzera(int *arr)
{
    int min = INT_MAX;
    for (size_t a = 0; a < DIM ; a++)
    {
        if (arr[a] < min)
            min = arr[a];
        if (a % 2 != 0)
            arr[a] = 0;
        printf("%d\n", arr[a]);
    }
    printf("%d\n", min);
    
    return;
}
