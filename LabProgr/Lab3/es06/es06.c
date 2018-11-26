#include <stdio.h>

int main(){
	char n;
	scanf("%1c",&n);
	if(n>= 'a' && n<= 'z')
		printf("%c", n+('A' - 'a'));
	else
		printf("invalid input");
	return 0;
}