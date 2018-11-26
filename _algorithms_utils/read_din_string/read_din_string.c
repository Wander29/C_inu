#include <stdio.h>
#include <stdlib.h>

char *readString();
char *read_string_size(size_t size)

int main() {
    char *nome = readString_size(10);
    puts(nome);

    free(nome); // essendo mem allocata manualmente va deallocata
    return 0;
}

// parto da una dimensione base, che mi e' utile solamente per evitarmi di allocare memoria per ogni char
// la dimensione totale sara' dinamica
// uso un incremento costante per non gravare troppo sulle prestazioni
// un incremento per ogni char ad ogni passaggio nella maggior parte dei casi e' eccessivo
// ritorno una riallocazione della memoria senza sprechi, riallocandola con la dimensione effettiva
char *read_string_size(size_t size)
{
#define INCR 3
    char ch, *str;
    size_t len;

    str = malloc(sizeof(char) * size);
    if (!str)
        return str;

    while( (ch = getchar()) != EOF && ch != '\n' )
    {
        str[len++] = ch;

        if (size == len)
        {
            str = realloc(str, sizeof(char) * (size += sizeof(char) * INCR )  );
            if (!str)
                return str;
        }
    }
    str[len++] = '\0'; // terminatore stringa


    #undef INCR
    return realloc(str, sizeof(char) * len); // rialloco con la dim esatta
}

// funzione meno efficiente ma più diretta, senza dim come param
// sconsigliata
char *readString()
{
    char *str;
    char ch;
    size_t len = 0;

    str = malloc(sizeof(char));
    if(!str)
        return str;

    while( EOF != (ch = getchar()) && ch != '\n')
    {
        str[len++] = ch;

        str = realloc(str, sizeof(char)*len);
        if(!str)
            return str;
    }
    str[len++] = '\0'; //terminatore stringa

    return str;
}