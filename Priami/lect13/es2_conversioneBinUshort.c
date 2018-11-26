#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define digits 16
bool vet[digits] = {0};

int read_int();
unsigned short converti_bin_ushort(unsigned short n, unsigned short res);

int main()
{
    /*for (int i = digits - 1; i >= 0; i--)
    {
        printf("%d: ", i);
        vet[i] = read_int();
    }*/
    int temp;
    printf("Inserisci 16 cifre binarie (0 - 1)\n1234567890123456#####\n");
    for (int i = digits - 1; i >= 0; i--)
    {
        scanf("%1d", &temp);
        vet[i] = temp;
    }

    printf("CONVERTITO in SHORT: %hu\n", converti_bin_ushort(digits - 1, 0) );
}

unsigned short converti_bin_ushort(unsigned short n, unsigned short res)
{
    if (n == 0)
        return res + vet[0];
    else    
        return converti_bin_ushort(  n - 1, vet[n] == 0? res : res + pow(2, n) );
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || (temp != 0  && temp != 1))
    {
        printf(" Inserisci una cifra binaria.\n");
        while(getchar() != '\n');
    }
    return temp;
}