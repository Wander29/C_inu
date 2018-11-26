#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	switch(n%2)
	{
		case 0:
			printf("%d", 1);
			break;
		case 1:
			printf("%d", 0);
			break;
		default: 
			break;
	}
	return 0;
}