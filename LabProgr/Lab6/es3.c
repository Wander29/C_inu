#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool leggi_seq();
void fflush_stdin();

int main()
{
    for (int i = 0; i < 3; i ++)
    {
        printf( leggi_seq() ? "palindrome\n" : "non palindrome\n");
        fflush_stdin();
    }
}

bool leggi_seq()
{
    char c;
    scanf("%1c", &c);

    if ( c == '*' )
        return true;    
    
    if ( !leggi_seq() )
        return false;
    
    if (getchar() == c)
        return true;
    else 
        return false;
}

void fflush_stdin()
{
    char c;
    while ( (c = getchar()) != EOF && c != '\n');
}