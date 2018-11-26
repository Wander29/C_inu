#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int read_int();
unsigned long long int fibo (
                        int n,
                        unsigned long long int next,
                        unsigned long long int res
                    );

int main()
{
    //devo utilizzare i parametri come accumualtori
    //scomporre il programma in un sottoproblema di dimensioni minori.
    int x = read_int();
    printf("\ntermine %d° di Fibonacci %llu\n", x, fibo(x, 1, 0) );
    
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 1)
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

unsigned long long int fibo (
                        int n,
                        unsigned long long int next,
                        unsigned long long int res
                    )
{
    if (n == 0) //Fib(0) = 0, Fib(1) = 1, Fib(2) = 1, Fib(3) = 2, Fib(4) = 3
        return res; //sarebbe Fib(2)
    else 
        return fibo( n-1, next + res, next ); //complessità lineare, costo minimo = assegnazione (dei parametri)
}