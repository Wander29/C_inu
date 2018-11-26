#include <stdio.h>
#include <stdlib.h>

#define MAX 10

static int x, cnt = 0;

float media(float md);

typedef enum {
        NEGATIVO,
        POSITIVO
} sgn;

static sgn segno;
int main()
{
    printf("%.2f", media(0) );
}

float media(float md)
{
    if(cnt == 0) {
        while (scanf( "%d", &x) < 1 || x != 0 ){
            while (getchar() != ' \n');
            printf("Inserisci un intero.");
        }
        cnt ++;
        if (x < 0)
            segno = NEGATIVO;
        else
            segno = POSITIVO;
        md = media((float)x);
        return (md);

    } else
    {
        if (cnt < MAX)
        {
            while (scanf( "%d", &x) < 1 || x != 0 )
            {
                while (getchar() != ' \n');
                printf("Inserisci un intero.");
            }
            cnt ++;
            switch(segno)
            {
                case POSITIVO:
                    if (x > 0)
                        md = media( (md + x) );
                    else
                        md = media(md);
                    break;

                default: // Negativo
                    if (x < 0)
                        md = media( (md + x) );
                    else
                        md = media(md);
                    break;
            }
            return md;
        } else {
            while (scanf( "%d", &x) < 1 || x != 0 )
            {
                while (getchar() != ' \n');
                printf("Inserisci un intero.");
            }

            switch(segno)
            {
                case POSITIVO:
                    if (x > 0)
                        return( (md + x)/(cnt+1) );
                    else
                        return (md);
                    break;

                default: // Negativo
                    if (x < 0)
                        return( (md + x)/(cnt+1) );
                    else
                        return (md);
                    break;
            }
        }
    }
}
