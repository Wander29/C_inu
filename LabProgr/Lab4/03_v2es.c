#include <stdio.h>

void findMaxFibo(int max);

static int f0 = 0, f1 = 1, f2;

int main(){
	int x = 0;

	while ( scanf("%d", &x) < 1 ||  x < 0) 
	{
	 	printf("Inserire un intero positivo\n");
	 	while (getchar() != '\n');
	}

	printf("%d\n", f0);

	if (x != 0)
	{
		printf("%d\n", f1);
		findMaxFibo(x);
	}
	return 0;
}

void findMaxFibo(int max)
{
	f2 = f1 + f0;
	if (f2 <= max)
	{
		printf("%d\n", f2);
		f0 = f1;
		f1 = f2;
		findMaxFibo(max);
	}
}