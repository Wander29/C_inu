#include <stdio.h>
#include <stdlib.h>

void main()
{
    int dim;

    scanf("%d", &dim);

    int *vetPtr = NULL;

    vetPtr = (int *)malloc(dim * sizeof(int));

    if (!vetPtr) 
        return;
    
    for (size_t a = 0; a < dim; a++)
    {
        vetPtr[a] = a*8;
        printf("Pos %lu: %d\n", a, vetPtr[a]);
    }
}
