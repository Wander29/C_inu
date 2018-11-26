#include <stdio.h>
#include <stdlib.h> // per funzioni sulla memoria
#include <string.h> // per funzioni sulle stringhe
#include <stdarg.h> // per param variabili

#define N 3 // dimensione tabella (quadrata)

void who_wins(char*** mat, size_t dim);
void compare_winners(char* str, size_t dim, short n_args, ...);

int main ()
{
    char** mat = calloc(N, sizeof(char*)); // puntatore ad N puntatori char (aka array di pointers)
    for (size_t a = 0; a < N; a++)
        *(mat+a) = calloc(N, sizeof(char)); // ad ogni elemento dell'array di pointers alloco N char

    for (size_t j = 0; j < N; j++)
    {
    	for (size_t k = 0; k < N; k++)
    		scanf(" %c", *(mat+j)+k ); 	// dereferenzio -> la derefernziazione del ptr mat + il num Righe 
    									// a cui aggiungo il num di colonna
    }

	who_wins(&mat, N); // passo l'indirizzo del puntatore mat

    return 0;
}

void who_wins(char*** mat, size_t dim) // mat = indirizzo mem di un puntatore ad N puntatori char
{
	char x[dim+1], o[dim+1], aux[dim+1];
	*(x + dim) 	 = '\0';
	*(o + dim) 	 = '\0';
	*(aux + dim) = '\0'; // li definisco come stringhe, in modo da poter utilizzare le funzioni di comparazione

	for (size_t j = 0; j < dim; j++)
	{
		*(x+j) = 'x';
		*(o+j) = 'o';
	}
	// Il controllo verrà effettuato copiando temporaneamente e confrontando riga per riga e colonna per colonna 
	// la matrice con 'xxx' e 'ooo'

// Controllo per righe
	for (size_t j = 0; j < dim; j++)
	{
		for (size_t k = 0; k < dim; k++)
		{
			//*(aux+k) =  *(*(*mat+j)+k); 	// dereferenzio il pointer di mat, aggiungo l'offset della RIGA(j), 
											// dereferenzio -> ottengo il primo char della riga J, aggiungo l'offset
											// della colonna(k) -> ottengo il char in mat[j][k]
			//printf("AUX+k: %p\t%c\n", aux+k, *(aux+k));
			//printf("(*(*mat+j)+k): %p\t%c\n", (*(*mat+j) + k), *(*(*mat+j) + k) ) ;
		}
		memcpy(aux, *(*mat+j), dim); // MA in caso di una stringa con char contigui (in una riga) posso fare un memcpy 
		compare_winners(aux, dim, 2, x, o); // 2 = num param variabili
// Controllo per colonne
		for (size_t k = 0; k < dim; k++)
		{
			*(aux+k) =  *(*(*mat+k)+j); 	// la riga si muove e la col sta ferma -> mat[k][j]
		}
		compare_winners(aux, dim, 2, x, o);
	}
// Controllo per diagonale
	for (size_t k = 0; k < dim; k++)
	{
		*(aux+k) =  *(*(*mat+k)+k); 		// diagonale, mat[k][k]
	}
	compare_winners(aux, dim, 2, x, o);

	printf("pareggio\n");
}

void compare_winners(char* str, size_t dim, short n_args, ...) // necessario il numero di argomenti variabili
	{
		char* str_win = calloc(dim+1, sizeof(char));

		va_list arg; // lista di argomenti da inizializzare
		va_start(arg, n_args); // inserisco gli ultimi n_args argomenti nella lista (devono stare alla fine)

		for (short a = 0; a < n_args; a++)
		{
			str_win = va_arg(arg, char*); // assegno la stringa letta negli argomenti in lista a quella di appoggio
			if (memcmp(str, str_win, dim) == 0) // memcmp confronta gli N bytes e vede sono uguali
			{
				printf("vince %c\n", str_win[0]);
				exit(EXIT_SUCCESS); // uscita dal programma
			}
		}
	}
