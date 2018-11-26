#include <stdio.h>

#define MAX 10

int main(){
	char c;

	while (scanf("%[a-z]", &c) != 1) {
		printf("Input errato. Inserisci uncarattere in [a-z]: ");
		scanf("%*[^\n]%*c");
	}

	return 0;
}