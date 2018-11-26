#include <stdio.h>

int main(void){
	int n;
	scanf("%d", &n);
	printf("%lu\n", sizeof(n)*n);
	return 0;
}