#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    size_t dim = pow(10, 6);
    const unsigned int max_random = pow(10, 9) + 1;
    unsigned long long int sum = 0;
    unsigned int max = 0, min = max_random;

    unsigned int vet[dim];

    srand(time(NULL));
    
    for (size_t a = 0; a < dim; a++)
    {
        vet[a] = rand() % max_random;
        sum += vet[a];

        if (vet[a] > max)
            max = vet[a];
        if (vet[a] < min)
            min = vet[a];
    }

    printf("MAX: %d\tMIN: %d\tMEDIA: %Lf\n", max, min, (long double) sum / dim);
}