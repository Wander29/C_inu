#include <stdio.h>
#include <stdbool.h>

//Prototipi Func
int read_int();
int mcd(int a, int b);
int mcm(int a, int b);
bool check_prime(int num);

int main()
{
    int x = read_int();
    int y = read_int();

    if (x < y) //ordino i due numeri
    {
        x += y;
        y = x - y;
        x -= y;
    }
    //printf("%d\n%d\n", mcd(x, y), mcm(x, y));
    printf("%d\n", mcd(x, y));
}

int read_int()
{
    int temp;
    while( scanf("%d",&temp) < 1 || temp < 0 )
    {
        printf(" Inserisci un intero positivo.\n");
        while(getchar() != '\n');
    }
    return temp;
}

int mcd(int a, int b)
{
    for (int i = (int) b/2; i > 1; i--)
    {
        if ( check_prime( i ) )
        {
            if (a % i == 0)
                return i;
        }
    }
    return 1; //se non ci sono fattori comuni MCD = 1
}

int mcm(int a, int b)
{
    int temp;
    for(int i = 1; 1; i++)
    {
        temp = a*i;
        if (temp%b == 0)
            break;
    }
    return temp;
}

bool check_prime(int num)
{
    bool flag = true;
    for (int i = 0; i <= num/2; i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
        return true;
    else
        return false;
}