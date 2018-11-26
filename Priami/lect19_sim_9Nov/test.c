#include <stdio.h>
#include <ctype.h>
#include <string.h>

//STRUTTURE
typedef struct {
    char staz_partenza[20];
    char staz_arrivo[20];
    short h_arrivo, m_arrivo, h_part, m_part;
} Riga;

//PROTOTIPI FUNCTIONS
void str_to_lower(char *s);
void capitalize(char *s);
void add_station(char *staz[], size_t *cnt, char *new_city);

int main()
{
    size_t cnt_rows = 0;
    FILE *fPtr;

    if( (fPtr = fopen("input.txt", "r") ) == NULL )
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

    Riga righe[cnt_rows]; //array di strutture Riga
    char *stazioni[cnt_rows]; //array di puntatori a caratteri, di ogni stringa viene memorizzato l'indirizzo del primo char
    size_t cnt_stazioni = 0;                      
//Lettura da file delle info
    for ( size_t a = 0; !feof(fPtr); a++ )
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
//Stampa Array di struttura
    for (size_t j = 0; j < cnt_rows; j++)
    {
        printf("%20s\t%02hd:%02hd%20s\t%02hd:%02hd\n", 
                righe[j].staz_partenza, righe[j].h_part,    righe[j].m_part, 
                righe[j].staz_arrivo,   righe[j].h_arrivo,  righe[j].m_arrivo 
        );    
    }
    printf("cnt: %lu\n", cnt_stazioni);
    printf("%10s\n", righe[0].staz_partenza);
    printf("Stazione: \n");
    for (size_t a = 0; a < cnt_stazioni; a++)
    {
        printf("%20s\n", stazioni[a]);
    }

    fclose(fPtr);
}

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

void add_station(char *staz[], size_t *cnt, char *new_city)
{
    for (size_t a = 0; a < *cnt; a++)
    {
        if (staz[a] == new_city)
            return;
    }
    staz[(*cnt)++] = new_city;
    return;
}

