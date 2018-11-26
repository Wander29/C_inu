#include <stdio.h>
#include <stdbool.h>

bool leggi_seq();
void fflush_stdin();
void svuota_buffer(char buf[]);
void stampa_buffer(char buf[]);

static char buffer[10];

int main()
{
    char temp, temp1, temp2;
    for (int i = 0; i < 3; i ++)
    {
        if (fgets(buffer, 10, stdin) != NULL )
        {
            //printf( ( leggi_seq() ) ? "palindrome\n" : "non palindrome\n");
            //stampa_buffer(buffer);
            sscanf(buffer, "%1c", &temp);//string scanf
            sscanf(buffer, "%1c", &temp1);//string scanf
            sscanf(buffer, "%1c", &temp2);//string scanf
            printf("TEMP2:%c\n", temp2);
            fseek(stdin, SEEK_END, SEEK_CUR);
            svuota_buffer(buffer);
        }
    }
}

void svuota_buffer(char buf[])
{
    for(int a = 0; a < 10 ; a++)
        buf[a] = 0;
}

void stampa_buffer(char buf[])
{
    for(int a = 0; a < 10 ; a++)
        printf("C:%c \n", buf[a]);
}

bool leggi_seq()
{
    char c, c1;
    //scanf("%1c", &c);
    sscanf(buffer, "%1c", &c);//string scanf
    printf("C: %c", c);

    if ( c == '*' )
        return true;   

    if ( !leggi_seq() )
        return false;
        
    sscanf(buffer, "%1c", &c1);
    printf("C1: %c", c1);
    if ( c1 == c )
        return true;
    else 
        return false;
}

void fflush_stdin()
{
    char c;
    while ( (c = getchar()) != EOF && c != '\n');
}