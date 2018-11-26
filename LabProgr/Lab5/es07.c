#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define stampa_err printf("Data inserita errata, inserire una data nel formato gg/mm/aaaa.\n")

bool data_valida(int g, int m, int a);
void leggi_data();

static int g, m, a;

int main()
{
    int min_g = 0, min_m = 0, min_a = 0;
    do {
        leggi_data();
        
        if (min_g == 0)
        {
            min_g = g; min_m = m; min_a = a;
        } else 
        {
            if (min_a > a && a != 0)
            {
                min_g = g; min_m = m; min_a = a;
            } else {
                if (min_a == a)
                {
                    if (min_m > m)
                    {
                        min_g = g; min_m = m; min_a = a;
                    } else {
                        if (min_m == m)
                        {
                            if (min_g > g)
                            {
                                min_g = g; min_m = m; min_a = a;
                            }
                        }
                    }
                }
            }
        }
        
    } while (g != 0 && m != 0 && a != 0);
    printf("Data meno recente: %02d/%02d/%04d\n", min_g, min_m, min_a); //add zeros for padding and complete the field dimension
}


bool data_valida(int g, int m, int a)
{
    if ( !(g == 0 && m == 0 && a == 0) && (g < 1 || g > 31 || m < 1 || m > 12 || a < 0 || a > 9999) )
    {
        stampa_err;
        return false;
    }
    return true;
}

void leggi_data()
{
    while ( scanf("%2d%*[/]%2d%*[/]%4d", &g, &m, &a) < 3 )
    {
        while (getchar() != '\n');
        stampa_err;
    }
    if ( data_valida(g, m, a) )
        return;
    else
        leggi_data();
}




