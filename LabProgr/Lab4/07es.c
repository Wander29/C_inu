#include <stdio.h>

#define stampa_head(x) printf("%20s\t%20s\t%20s\n", "Prezzo_Init", "Percentuale", x)
#define stampa_val(y) printf("%20.2f\t%20.2f\t%20.2f\t\n", prezzo, perc, y)

typedef enum{	
				REPEAT,
				EXIT
			}state;

int main(){
	state stato = REPEAT;
	int scelta; //0 = prezzo scontato, 1 = ivato, <0 = esci dal programma
	float prezzo, perc;
	
	do 
	{
		while ( scanf("%d", &scelta) < 1  || (scelta > 1) ) 
		{
		 	printf("scelta non valida\n");
		 	while (getchar() != '\n');
		}

		if( scelta == 0 || scelta == 1)
		{
			while ( scanf("%f", &prezzo) < 1  || (prezzo < 1) ) 
			{
			 	printf("Prezzo non valido\n");
			 	while (getchar() != '\n');
			}

			while ( scanf("%f", &perc) < 1  || perc < 1 || perc > 100 ) 
			{
			 	printf("Percentuale non valida\n");
			 	while (getchar() != '\n');
			}

			switch(scelta)
			{
				case 0: //prezzo scontato
					stampa_head("Prezzo_scontato");
					stampa_val(prezzo * ((100-perc)/100));
					break;

				case 1: //prezzo ivato
					stampa_head("Prezzo_ivato");
					stampa_val(prezzo * ((perc+100)/100));
					break;
				default:
					break;
			}
		} else {
			return 0;
		}

	} while (stato == REPEAT);

	return 0;
}




