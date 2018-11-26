#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//Prototipi
int read_int();
float leggi_prezzo();
float leggi_percentuale();

float calcola_prezzo_ivato(float prz, float iva);
float calcola_prezzo_scontato(float prz, float sconto);

#define stampa_head(x) printf("%20s\t%20s\t%20s\n", "Prezzo_Init", "Percentuale", x)
#define stampa_val(y) printf("%20.2f\t%20.2f\t%20.2f\t\n", prezzo, perc, y)

typedef enum{	
				REPEAT,
				EXIT
			}state;

int main()
{
	state stato = REPEAT;
	int scelta; //0 = prezzo scontato, 1 = ivato, <0 = esci dal programma
	
	do 
	{
		while ( scanf("%d", &scelta) < 1  || (scelta > 1) ) 
		{
		 	printf("scelta non valida\n");
		 	while (getchar() != '\n');
		}

		if( scelta == 0 || scelta == 1)
		{
            float prezzo, perc;
            prezzo = leggi_prezzo();
            perc = leggi_percentuale();

			switch(scelta)
			{
				case 0: //prezzo scontato
					stampa_head("Prezzo_scontato");
					stampa_val( calcola_prezzo_scontato(prezzo, perc) );
					break;

				case 1: //prezzo ivato
					stampa_head("Prezzo_ivato");
                    stampa_val(calcola_prezzo_ivato(prezzo, perc) );
					break;
				default:
					break;
			}
		} else {
			return EXIT_SUCCESS;
		}

	} while (stato == REPEAT);

	return 0;
}

float leggi_prezzo()
{
    float temp;
    while ( scanf("%f", &temp) < 1  || (temp < 1) ) 
    {
        printf("Prezzo non valido\n");
        while (getchar() != '\n');
    }
    return temp;
}

float leggi_percentuale()
{
    float temp;
    while ( scanf("%f", &temp) < 1  || (temp < 0) || (temp > 100) ) 
    {
        printf("Percentuale non valida\n");
        while (getchar() != '\n');
    }
    return temp;
}

float calcola_prezzo_ivato(float prz, float iva)
{
    return ( prz * ((iva+100)/100) );
}

float calcola_prezzo_scontato(float prz, float sconto)
{
    return ( prz * ((100-sconto)/100) );
}