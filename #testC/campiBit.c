#include <stdio.h>

typedef struct {
	char c; //(verrà salvato non con 5 bytes, ma con 8)
	// int : 0; forza a finire la parola di memoria e passare alla successiva per le prossime var;
	int n : 24; //così occupa 4B tutta la struct
} Stru;

int main()
{
	Stru el = {0};
	el.c = 'a';
	el.n = 34;
	printf("DIMENSIONE: %ld\n", sizeof(el)); //occupa 16 bytes poichè viene allineato alla parola (4B) 
	printf("\ncPtr: %p\tnPtr: %p\n", &el.c, &el.n);
	return 0;
}