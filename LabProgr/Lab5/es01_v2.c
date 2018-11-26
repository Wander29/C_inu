#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

int read_int();
float media();

static int stesso_segno = 1;
static bool positivo = false;

int main()
{   
    printf("%.2f\n", media() );
}


int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 )
    {
        printf("Inserisci un intero.\n");
        while(getchar() != '\n');
    }
    return temp;
}

float media()
{
   int temp = read_int();
    if (temp > 0)
        positivo = true;
    else
        positivo = false;
    float media = temp;
   for(int i = 1; i < MAX; i++)
   {
       temp = read_int();
       if (positivo)
        {
            if (temp > 0)
            {
                stesso_segno ++;
                media += temp;
            }
        } else {
            if (temp < 0)
            {
                stesso_segno ++;
                media += temp;
            }
        }
   }
   return media / stesso_segno; 
}