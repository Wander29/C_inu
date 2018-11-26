#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_int();
int fibo(int f2);

int x;

int main()
{
    x = read_int();
    printf("%d° Fibonacci: %d\n", x, fibo(1) );
}

int fibo(int f2)
{
    static int cnt = 2;
    static int f0 = 0;
    static int f1 = 1; 

    if(cnt < x)
    {
        cnt ++;
        f0 = f1;
        f1 = f2;
        fibo(f0 + f1);
    } else {
        return f2;
    }
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1)
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}