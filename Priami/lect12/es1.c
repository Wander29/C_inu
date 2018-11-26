#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool overflow(int a, int b);
int read_int();

int main()
{
    int x = 0, y = 0;
    printf("<start number> \n<intervallo da sommare>  \n");
    x = read_int();
    y = read_int();
    printf("x: %d || y: %d", x, y);
    printf("\n%s\n", overflow(x, y)? "sei incappato in un overflow" : "Nessun overflow" );
    return 0;
}

bool overflow(int a, int b)
{
    int res = a + b;
    printf("\n%d", res);
    if (a > 0 && b > 0)
    {
        if (res < a || res < b)
            return true;
        else
            return false;
    } else {
        if (a < 0 && b < 0)
        {
            if (res > a || res > b)
                return true;
            else
                return false;
        } else 
            return false;
    }
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