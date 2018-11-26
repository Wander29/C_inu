#include <stdio.h>
#include <math.h>

int read_int();

void stampa_cifre_inverso(int n);
void stampa_cifre(int n);

int main()
{
    int x = read_int();
    stampa_cifre_inverso(x);
    stampa_cifre(x);
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 0 )
    {
        printf("Errore. Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

void stampa_cifre_inverso(int n) //ricorsione in coda
{
    if (n < 10)
        printf("%d\n", n);
    else
    {
        printf("%d\n", n % 10);
        stampa_cifre_inverso(n / 10);
    }
}

void stampa_cifre(int n)// ricorsione del cazoz
{
    if (n < 10)
        printf("%d\n", n);
    else
    {
        stampa_cifre(n / 10);
        printf("%d\n", n % 10);
    }
}