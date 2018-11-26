#include <stdio.h>
#include <math.h>

#define tasso_interesse 0.0312
#define anni 10
#define capitale 1000

	/*******************************************************
		_investo inizialmente 1000$, guadagno annualmente il 3.12%
		e investo gli interessi guadagnati nell'anno successivo.
		
		>>OUTPUT
		_tabella 2 colonne: interessi annui e saldo totale alla fine di 
		ogni anno, per 10 anni
		_saldo totale interessi dopo 10 anni

		----------------------
		HINT: formula calcolo interessi a = p(1+r)^n
			a = saldo alla fine dell'anno
			p = investimento iniziale
			r = tasso annuale di interesse (5% = 0.05)
			n = numero di anni
	********************************************************/

int main(){
	float temp, saldo;
	printf("\n\n%5s\t\t%5s\t%7s\n", "ANNO", "INTERESSI", "SALDO");
//Cornice :D
	for (int a=0; a<60; a++)
		printf("-");
	printf("\n");

	for(int i = 1; i <= anni; i++)
	{//Metodo 2, con uso della potenza per il calcolo degli interessi
		saldo = (roundf( capitale*pow(1 + tasso_interesse, i) *100)/100);
		printf("%5d\t\t%c%4.2f\t\t%c%6.2f\n", i, '$', (saldo - capitale - temp), '$', saldo);
		temp = saldo - capitale;
	}
//Cornice :D
	printf("\n");
	for (int a=0; a<60; a++)
		printf("=");
	printf("\n");

	printf("TOTALE INTERESSI IN %d ANNI:  $%.2f\n\n\n", anni, (saldo - capitale) );
}