#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_int();
void approx_pi(int prec);

static float res;

int main()
{
    //Serie Gregory-Leibniz
    int x = read_int();
    approx_pi(x);
    printf("%.6f\n", res);
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 1 )
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

void approx_pi(int prec)
{
    if (prec == 1)
    {
        res = 4;
        return;
    }

    approx_pi(prec - 1); // ricorsione

    switch (prec % 2)
    {
        case 1://Dispari, allora aggiungo
            res += ( 4.0/(prec * 2 - 1) );
            break;

        default: //Pari, allora sottraggo
            res -= ( 4.0/(prec * 2 - 1));
            break;
    }
}