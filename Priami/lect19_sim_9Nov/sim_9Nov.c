#include <stdio.h>
#include <string.h>

typedef struct {
    char staz_partenza[20];
    char staz_arrivo[20];
    int h_arrivo, m_arrivo, h_part, m_part;
} Riga;

int main()
{
    int t1, t2;
    char stringa[30] = "Pisa 10:25 Orte 22:34";

        /*fscanf(fPtr, "%s[^\x20]%2hd%*c%2hd%*c%s[^\x20]%*c%2hd%*c%2hd%*c", 
                righe[a].staz_partenza, righe[a].h_part,    righe[a].m_part, 
                righe[a].staz_arrivo,   righe[a].h_arrivo,  righe[a].m_arrivo
                */
    Riga r[1];
    sscanf(stringa, "%s%2d%*c%2d%s%2d%*c%2d", 
            r[0].staz_partenza, &r[0].h_part, &r[0].m_part, 
            r[0].staz_arrivo, &r[0].h_arrivo, &r[0].m_arrivo
        );
    

    //sscanf(stringa, "%*s%*2d%*c%*2d%*s%2d%*c%2d", &r[0].h_part, &r[0].m_part);
    
    //printf("\n%02d:%02d\n\n", r[0].h_part, r[0].m_part);
    //puts(r[0].staz_arrivo);

    
    printf("\n%20s\t%02hd:%02hd\t%20s\t%02hd:%02hd\n\n", 
                r[0].staz_partenza, r[0].h_part,    r[0].m_part, 
                r[0].staz_arrivo,   r[0].h_arrivo,  r[0].m_arrivo 
        );
    

}