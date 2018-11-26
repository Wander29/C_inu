#include <stdio.h>

typedef struct{
	int a;
	char b;
} Str;

void stampa1(char c);
void stampa1(int a);

int main()
{
	Str var = {10,0};
	int vet[2];

	printf("%p\n%p\n\n", var, &var);//&var stampa l'indirizzo del primo campo
	printf("%p\n", &var.a);
	//printf("%p\n%p\n", vet, &vet);

	stampa1(3);
	stampa1('c');
} 

void stampa1(int a)
{
	printf("%d", a);
}

void stampa1(char c)
{
	printf("%c", c);
}