#include <stdio.h>

int main(void){
	int persone;
	float u=0.00567;					//Costante di contagio base
	int nuovi_infetti;	
	int infetti=1;
	int k=0;						//Giorni ("assumere tempo discreto con incrementi costanti")
	
	printf("Inserire totale persone\n");			//"Assumendo il numero di persone costante"
	scanf("%d", &persone);

	while (infetti<persone) {
		u+=u*infetti/persone;				// "La probabilità di essere infettati è proporzionale al numero di persone malate"
		nuovi_infetti=u*(persone-infetti); 		// "Il numero di persone infettate è proporzionale al numero di persone sane" (*random??) 
		if ((persone-infetti-nuovi_infetti)<0){		//Controllo nel caso in cui vengano infettate piu persone di quante siano sane
				nuovi_infetti=persone-infetti;
		}
		infetti+=nuovi_infetti;
		printf("Giorno: %d\tProbabilità d'infezione: %.6f\tNuovi Infetti: %d\tPersone infettate: %d/%d\n", k++, u, nuovi_infetti, infetti, persone);
	}
	return 0;
}