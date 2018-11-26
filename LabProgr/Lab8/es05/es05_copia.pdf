#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

int main ()
{
    printf("ehi");
    char** mat = calloc(N, sizeof(char*)); //puntatore ad N puntatori char (aka array di pointers)
    for (size_t a = 0; a < N; a++)
        *(mat+a) = calloc(N, sizeof(char)); //ad ogni elemento dell'array di pointers alloco N char
    return 0;
}
