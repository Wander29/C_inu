#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_int();

int mcd(int a, int b);
int mcd_iterativo(int a, int b);

int div_temp = 0; 

int main()
{
    int x, y;
    x = read_int();
    y = read_int();
    div_temp = x > y ? y : x;
    printf("\nMCD: %d\n", x > y ? mcd(x, y) : mcd(y, x) );
    printf("MCD_iterativo: %d\n", x > y ? mcd_iterativo(x, y) : mcd_iterativo(y, x) );
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || abs(temp) > __INT32_MAX__)
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

int mcd(int a, int b)
{
    // b = numero piu piccolo
    if (a % div_temp == 0 && b % div_temp == 0)
        return div_temp;
    else
    {
        div_temp--;
        mcd(a, b);
    }
}

//Iterativo
int mcd_iterativo(int a, int b)
{
    while (a % div_temp != 0 && b % div_temp != 0)
    {
        div_temp--;
        mcd_iterativo(a, b);
    }
    return div_temp;
}