#include <stdio.h>

typedef union {
	int i;
	int d;
	int c;
} Un;

typedef struct {
	char c[5]; //(verrà salvato non con 5 bytes, ma con 8)
	int n;
	int n1;
} Stru;

int main()
{
	//Un elem = {0};
	//elem.i = 97-32;
	//printf("int %d double %lf char %c\n", elem.i, elem.d, elem.c);
	//printf("i %d d %d c %\n", elem.i, elem.d, elem.c);
	//printf("DIMENSIONE: %ld", sizeof(elem));
	//printf("\niPtr: %p\tdPtr: %p\tcPtr: %p\n", &elem.i, &elem.d, &elem.c);

	Stru el = {0};
	el.c[0] = 'a';
	el.n = 34;
	printf("DIMENSIONE: %ld\n", sizeof(el)); //occupa 16 bytes poichè viene allineato alla parola (4B) 
	char vet[5]; //occupa 5 bytes
	printf("DIMENSIONE vet: %ld\n", sizeof(vet)); 
	return 0;
}