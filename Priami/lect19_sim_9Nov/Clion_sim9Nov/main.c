#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define NUM_FASCE 24
#define LENGHT_FRAME 35

//STRUTTURE
typedef struct {
    char staz_partenza[20];
    char staz_arrivo[20];
    short h_arrivo, m_arrivo, h_part, m_part;
} Riga;

typedef struct {
    unsigned partenze;
    unsigned arrivi;
    unsigned tot_partenze;
    unsigned tot_arrivi;
} Nums_treni;

typedef struct {
    unsigned num_treni_max;
    unsigned orario;
    bool duplice;
} Orario_max;

//PROTOTIPI FUNCTIONS
void str_to_lower(char *s);
void capitalize(char *s);
void add_station(char **staz, size_t *cnt, char *new_city);
bool isSceltaCorrect(char *str, char **staz, const size_t cnt);
unsigned trova_partenze(const Riga * const dati, const char * const str, const short h, const size_t cnt);
unsigned trova_arrivi(const Riga * const dati, const char * const str, const short h, const size_t cnt);
void print_cornice();

int main()
{
    size_t cnt_rows = 1;
    FILE *fPtr;

    if( (fPtr = fopen("../input.txt", "r") ) == NULL )
        printf("ERR: Impossibile aprire il file relativo alle stazioni\n");

    char temp_char;
//Lettura numero righe nel file
    while ( !feof(fPtr) )
    {
        temp_char = fgetc(fPtr);
        if ( temp_char == '\n' )
            cnt_rows++;
    }
    rewind(fPtr); //riposiziona il pointer all'inizio del file

    Riga righe[cnt_rows]; //array di strutture struct Riga
    char *stazioni[cnt_rows*2]; //array di puntatori a caratteri, di ogni stringa viene memorizzato l'indirizzo del primo char
    size_t cnt_stazioni = 0;
//Lettura da file delle info
    for ( size_t a = 0; a < cnt_rows; a++ )
    {
        fscanf(fPtr, "%s%2hd%*c%2hd%s%2hd%*c%2hd%*c",
                righe[a].staz_partenza, &righe[a].h_part,    &righe[a].m_part,
                righe[a].staz_arrivo,   &righe[a].h_arrivo,  &righe[a].m_arrivo
            );
        if (a == 0)
            stazioni[cnt_stazioni++] = righe[0].staz_partenza;
        else
        {
            add_station(stazioni, &cnt_stazioni, righe[a].staz_partenza);
        }
        add_station(stazioni, &cnt_stazioni, righe[a].staz_arrivo);
    }
    fclose(fPtr);
//Stampa Array di struttura
    /*for (size_t j = 0; j < cnt_rows; j++)
    {
        printf("%20s\t%02hd:%02hd%20s\t%02hd:%02hd\n",
                righe[j].staz_partenza, righe[j].h_part,    righe[j].m_part,
                righe[j].staz_arrivo,   righe[j].h_arrivo,  righe[j].m_arrivo
        );
    }*/
//Inizializzazione fasce orarie (da 00 a 23)
    int fasce_orarie[NUM_FASCE] = {0};
    for (size_t a = 0; a < NUM_FASCE; a++)
        fasce_orarie[a] = a;

//Scelta della stazione di cui analizzare le info
    printf("\tStazioni: \n");
    for (size_t a = 0; a < cnt_stazioni; a++)
    {
        printf("%20s\n", stazioni[a]);
    }

    printf("Quale stazione vuoi scegliere?: ");
    char scelta[20];
    while (scanf("%s", scelta) != 1 || !isSceltaCorrect(scelta, stazioni, cnt_stazioni) )
    {
        printf("Quale stazione vuoi scegliere?: ");
        while (getchar() != '\n');
    }
//Ciclo principale
    while ( strcmp(scelta, "EXIT") != 0 )
    {
    //Inizializzazione struttre e riazzeramento
        Nums_treni num_treni = {0};
        Orario_max ora_max_traffico = {0};
        //num_treni.arrivi = num_treni.partenze = num_treni.tot_partenze = num_treni.tot_arrivi = 0;
        //ora_max_traffico.orario = ora_max_traffico.num_treni_max = 0;
        //ora_max_traffico.duplice = false;

        int temp = 0;
        print_cornice();
        printf("Stazione: %s\n", scelta);
        print_cornice();
        printf("%13s%12s%10s\n", "FASCIA ORARIA", "PARTENZE", "ARRIVI");
        for (unsigned short a = 0; a < NUM_FASCE; a++)
        {
            num_treni.partenze = trova_partenze(righe, scelta, a, cnt_rows);
            //printf("Partenze da %s alle h%02hu: %d\n", scelta, a, num_treni.partenze);
            num_treni.arrivi = trova_arrivi(righe, scelta, a, cnt_rows);
            //printf("Partenze da %s alle h%02hu: %d\n", scelta, a, num_treni.partenze);
            //printf("Arrivi a %s alle h%02hu: %d\n", scelta, a, num_treni.arrivi);

            if(num_treni.partenze > 0 || num_treni.arrivi > 0)
                printf("%02d:00 - %02d:59%12d%10d\n", a, a, num_treni.partenze, num_treni.arrivi);

            num_treni.tot_partenze += num_treni.partenze;
            num_treni.tot_arrivi += num_treni.arrivi;

            temp = num_treni.partenze + num_treni.arrivi;
            if ( temp > ora_max_traffico.num_treni_max )
            {
                ora_max_traffico.orario = a;
                ora_max_traffico.num_treni_max = temp;
                ora_max_traffico.duplice = false;
            } else if( temp == ora_max_traffico.num_treni_max )
                ora_max_traffico.duplice = true;
        }

        print_cornice();
        printf("%13s%12d%10d\n", "TOT", num_treni.tot_partenze, num_treni.tot_arrivi);
        print_cornice();
        if ( ora_max_traffico.duplice )
            printf("Ci sono piu' fasce orarie con lo stesso traffico di treni\n");
        else
            printf("Fascia oraria con maggior traffico: %02d:00 - %02d:59\n", ora_max_traffico.orario, ora_max_traffico.orario);

        //Scelta della stazione di cui analizzare le info
        input : printf("\nInserisci un'altra stazione (<LIST> per visualizzarle tutte) o <EXIT> per uscire\n");
        while (scanf("%s", scelta) != 1 || ( (strcmp(scelta, "EXIT") != 0 && strcmp(scelta, "LIST") != 0 ) &&
                !isSceltaCorrect(scelta, stazioni, cnt_stazioni) ) )
        {
            printf("Quale stazione vuoi scegliere?: ");
            while (getchar() != '\n');
        }
        if ( strcmp(scelta, "EXIT") == 0 )
            exit(EXIT_SUCCESS);
        else
            if ( strcmp(scelta, "LIST") == 0 )
            {
                printf("\tStazioni: \n");
                for (size_t a = 0; a < cnt_stazioni; a++)
                    printf("%20s\n", stazioni[a]);
                goto input;
            }
    }

}//END Main

void str_to_lower(char *s)
{
    for (size_t a = 0; s[a]; a++)
    {
        s[a] = tolower(s[a]);
    }
}

void capitalize(char *s)
{
    s[0] = toupper(s[0]);
    if (strlen(s) > 1)
    {
        for (size_t a = 1; s[a]; a++)
        {
            s[a] = tolower(s[a]);
        }
    }
}

void add_station(char **staz, size_t *cnt, char *new_city)
{
    for (size_t a = 0; a < *cnt; a++)
    {
        if (strcmp(staz[a], new_city) == 0)
            return;
    }
    staz[(*cnt)++] = new_city;
    return;
}

bool isSceltaCorrect(char *str, char **staz, const size_t cnt)
{
    capitalize(str);
    for (size_t a = 0; a < cnt; a++)
    {
        if (strcmp(staz[a], str) == 0)
            return true;
    }
    return false;
}

unsigned trova_partenze(const Riga * const dati, const char * const str, const short h, const size_t cnt)
{
    unsigned cnt_tmp = 0;
    for(size_t a = 0; a < cnt; a++)
    {
        if ( dati[a].h_part == h && strcmp(str, dati[a].staz_partenza) == 0)
            cnt_tmp++;
    }
    return cnt_tmp;
}

unsigned trova_arrivi(const Riga * const dati, const char * const str, const short h, const size_t cnt)
{
    unsigned cnt_tmp = 0;
    for(size_t a = 0; a < cnt; a++)
    {
        if ( dati[a].h_arrivo == h && strcmp(str, dati[a].staz_arrivo) == 0)
            cnt_tmp++;
    }
    return cnt_tmp;
}

void print_cornice()
{
    for (short a = 0; a < LENGHT_FRAME; a++)
        printf("-");
    printf("\n");
}
















