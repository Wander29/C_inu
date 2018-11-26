#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

#define digits 16
bool vet[digits] = {0};

short read_short();
void subtract_one_and_change_val();
bool check_zero();
short converti_bin_short(short n, short res);
short converti_bin_short_neg(short n, short res);

int main()
{
    /*for (int i = digits - 1; i >= 0; i--)
    {
        printf("%d: ", i);
        vet[i] = read_int();
    }*/
    printf("## Numero binario in complemento a 2 ##\nInserisci 16 cifre binarie (0 - 1)\n1234567890123456#####\n");
    for (int i = digits - 1; i >= 0; i--)
    {
        vet[i] = read_short();
    }

    bool flag_positivo = vet[digits - 1] == 1 ? false : true;
    bool zero_flag = check_zero();

    short result = 0;
    if (!zero_flag)
    {
        result = flag_positivo ? converti_bin_short(digits - 2, 0) :  converti_bin_short_neg(digits - 2, 0) ;
    }
    printf("CONVERTITO in SHORT: %hd\n", result);
}

bool check_zero()
{
    for (int a = 0; a < digits - 1; a++)
    {
        if (a == 0)
            continue;
        else
            return false;
    }
    return true;
}

void subtract_one_and_change_val()
{
    bool sottratto = false;
    for (int a = 0; a < digits - 1; a++)
    {
        switch(vet[a])
        {
            case 0:
                if (sottratto)
                    vet[a] = 1;
                break;
            case 1:
                if (!sottratto)
                    sottratto = true;
                else
                    vet[a] = 0;
                return;
            default:
                break;
        }
    }
}

short converti_bin_short(short n, short res)
{
    if (n == 0)
        return res + vet[0];
    else    
        return converti_bin_short(  n - 1, vet[n] == 0? res : res + pow(2, n) );
}

short converti_bin_short_neg(short n, short res)
{
    subtract_one_and_change_val();
    return -(converti_bin_short(n, res) );
}

short read_short()
{
    short temp = 0;
    if( scanf("%h",&temp) < 1 || (temp != 0  && temp != 1) )
    {
        printf("Non è un numero binario.\n");
        while(getchar() != '\n');
        exit(EXIT_FAILURE);
    }
    return temp;
}