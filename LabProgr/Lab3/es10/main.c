#include <stdio.h>

#define stampaIntestazione(x) printf("%20s\t%20s\t%20s\t\n", "Prezzo_Init", "Percentuale", x)

int main(){
    short scelta;
    float prz, prz_end, perc;
    if(scanf("%hd", &scelta) == 1)
    {
        if(scelta == 0 || scelta == 1)
        {
            if(scanf("%f", &prz) == 1)
            {
                if (prz > 0)
                {
                    if(scanf("%f", &perc) == 1)
                    {
                        if(perc >= 0 && perc <= 100) 
                        {
                            switch(scelta)
                            {
                                case 0: //prezzo scontato
                                    prz_end = prz*((100-perc)/100);
                                    stampaIntestazione("Prezzo_scontato");
                                    break;
                                case 1: //prezzo ivato
                                    prz_end = prz*((perc+100)/100);
                                    stampaIntestazione("Prezzo_ivato");
                                    break;
                                default:
                                    printf("invalid input");
                                    return 0;
                                    break;
                            }
                            printf("%20.2f\t%20.2f\t%20.2f\t", prz, perc, prz_end);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("invalid input");
    return 0;
}