#include <stdio.h>
#include <math.h>

int read_int();
int Pot2(int n);

int main()
{
    int x = read_int();
    printf("%d\n", Pot2(x));
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 0 )
    {
        printf("Errore.  Inserisci un numero intero positivo\n");
        while(getchar() != '\n');
    }
    return temp;
}

int Pot2(int n)
{
    return pow(2, n);
}