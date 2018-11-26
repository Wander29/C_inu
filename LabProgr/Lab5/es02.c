#include <stdio.h>
#include <stdlib.h>

int read_int();
void multipli(int n, int m);

int main()
{
    int x = read_int();
    int y = read_int();
    multipli(x, y);

}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 1 )
    {
        printf(" Inserisci un intero.\n");
        while(getchar() != '\n');
    }
    return temp;
}

void multipli(int n, int m)
{
    int temp = m;

    for (int a = 2; temp <= n; a++)
    {
        printf("%d\n", temp);
        temp = m * a;
    }
}
