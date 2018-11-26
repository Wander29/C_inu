#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define popolazione 10000
/*   CONST_MU
    dipende da valori non controllobili, fattori 'ipotetici', ovvero:
        # tipologia di malattia (ogni malattia ha il suo range di contagio)
        # valore dell'incremento temporale (si assume tempo «discreto», distaccato dal tempo fisico ma avente solo funzione di intervallo)
    è comunque un valore percentuale (1%, 5% quindi 0.01, 0.05), 1 = max
*/
#define const_malaria 0.0002
#define const_scabbia 0.04
#define const_light 0.06

int read_int();
int epidemia(int k);
void enjoy();

static int infetti;
static float mu;

int main()
{
    atexit(enjoy);

    printf("TIPO DI MALATTIA: <1> Malaria\t<2> Scabbia\t<3> Light-themed IDEs\n");
    int scelta = read_int();

    switch(scelta)
    {
        case 1:
            mu = const_malaria;
            break;
        case 2:
            mu = const_scabbia;
            break;
        case 3:
            mu = const_light;
            break;
        default:
            mu = 0;
            break;
    }

    printf("ISTANTI: ");
    int k = read_int(); //quanti istanti
    printf("\n");

    printf("Persone infettate dopo %d istanti: %d", k, epidemia(k));
}

int epidemia(int k)
{
    if (k == 0)
        return 1;
    infetti = epidemia(k-1);
    if (infetti > popolazione)
    {
        printf("Everyone is dead.");
        exit(EXIT_SUCCESS);
    }
        
    return ( infetti + ( round(mu*(popolazione - infetti)*infetti) ) );
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp <= 0 )
    {
        printf("Inserisci un intero.\n");
        while(getchar() != '\n');
    }
    return temp;
}

void enjoy()
{
    printf("\n\nNow you have some more space on earth. Yeah?\n");
}