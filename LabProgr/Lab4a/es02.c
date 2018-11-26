#include <stdio.h>

int main(){
	int x;

	while ( scanf("%d", &x) < 1 || x < 0) 
	{
	 	while (getchar() != '\n');
	}

	if (x == 0 || x == 1)
	{
		printf("%d\n", 1);
	} else {

		long long int prodotto = x;
		for (int i = 1; i < x;i++)
		{
			prodotto *= (x-i);
		}
		printf("%lld\n", prodotto);
	}
	return 0;
}