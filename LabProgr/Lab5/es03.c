#include <stdio.h>
#include <math.h>

//Var glob
static float base = 0;
int read_positive_int();
float read_positive_float();
float sum_pow(int exp);

int main()
{
    int x = read_positive_int(); //esponente
    base = read_positive_float(); //base potenza
    printf("%.2f", sum_pow(x));
}

int read_positive_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 0 )
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

float read_positive_float()
{
    float temp;
    while( scanf("%f",&temp) < 1 || temp < 0 )
    {
        printf(" Inserisci un numero reale positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

float sum_pow(int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    return ( pow(base, exp) + sum_pow( (exp-1)) );
}