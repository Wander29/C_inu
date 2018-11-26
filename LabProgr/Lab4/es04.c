#include <stdio.h>

#define MAX 10

typedef enum{
			MATCHED,
			FAILED		
		} state;

int main(){
	int x[MAX];
	state stato = FAILED;

	for (int i = 0; i < MAX; i++)
	{
		while ( scanf("%d", &x[i]) < 1) 
		{
		 	while (getchar() != '\n');
		}
	}

	for (int i = 0; (i < MAX - 1) && (stato == FAILED); i++)
	{
		if( (x[i] >= 0 && x[i]%2 == 0) || (x[i]<0 && [x+1] >= 0 ) )
		{
			printf("%d\n", x[i]);
			stato = MATCHED;
		}
	}

	if(stato == FAILED)
		//printf("%d\n", -1);
	

	return 0;
}