#include <stdio.h>
#include <math.h>

#define EUR 1
#define USD 1.15132
#define JPY 130.190
#define GBP 0.874162

typedef enum{	
				REPEAT,
				EXIT
			}state;

void converti(float imp_in, float start_val, int end_val);

int main(){
	state stato = REPEAT;
	int scelta, val_end;
	float prezzo;
	
	do 
	{
		printf("### Convertitore Valute ###\nSceglia la valuta di partenza:\n1)€ (Euro)\n2)$ (Dollari)\n3)₤ (Sterlina)\n4)¥ (JPY)\n -> ");
		while ( scanf("%d", &scelta) < 1  || (scelta < 0) || (scelta > 4) ) 
		{
		 	printf("ERROR: scelta non valida (capra)\n");
		 	while (getchar() != '\n');
		}

		printf("\nImporto: ");
		while ( scanf("%f", &prezzo) < 1  || prezzo < 0 ) 
		{
		 	printf("ERROR: scelta non valida (capra)\n");
		 	while (getchar() != '\n');
		}

		printf("\nValuta in cui convertire l'importo?\n1)€ (Euro)\n2)$ (Dollari)\n3)₤ (Sterlina)\n4)¥ (JPY)\n -> ");
		while ( scanf("%d", &val_end) < 1  || (val_end < 0) || (val_end > 4) ) 
		{
		 	printf("ERROR: scelta non valida (capra)\n");
		 	while (getchar() != '\n');
		}

		printf("%20s %20s", "Importo Iniziale", "Importo convertito\n");
		switch(scelta)
		{
			case 1: //Euro
				converti(prezzo, EUR, val_end);
				break;
			case 2: //Dollari
				converti(prezzo, USD, val_end);
				break;
			case 3: //Sterline
				converti(prezzo, GBP, val_end);
				break;
			case 4: //JPY
				converti(prezzo, JPY, val_end);
				break;
		}
		printf("\nVuoi effettuare un'altra conversione?\t< 1 > Yes\t< 14 > No\n");
		scelta = 0;

		while ( scanf("%d", &scelta) < 1  || (scelta != 1 && scelta != 14) ) 
		{
		 	printf("ERROR: scelta non valida (capra)\n");
		 	while (getchar() != '\n');
		}
		if (scelta == 14)
			stato = EXIT;

		printf("\n___________________________________________________\n\n");

	} while (stato == REPEAT);

	return 0;
}

void converti(float imp_in, float start_val, int end_val)
{
	float conv_val;

	switch(end_val)
	{
		case 1:
			conv_val = EUR;
			break;
		case 2:
			conv_val = USD;
			break;
		case 3:
			conv_val = GBP;
			break;	
		case 4:
			conv_val = JPY;
			break;
		default:
			break;
	}

	printf("%19.2f%19.2f", imp_in, round((imp_in / start_val * conv_val)*100)/100 );
}



