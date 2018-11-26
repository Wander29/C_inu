#include <stdio.h>

int read_int();
unsigned long long int conta_pos(int n);

int main()
{
    printf("%llu\n", conta_pos( read_int() ) );
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 1)
    {
        printf("Errore.  Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

unsigned long long int conta_pos(int n)
{
    if (n == 1)
        return 2;
    if (n == 2)
        return 7;
    return (2*(conta_pos(n - 1)) + 3 * conta_pos(n - 2) );
}