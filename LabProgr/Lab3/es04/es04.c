#include <stdio.h>

#define MAX 3

int main(){
	int n, num_max = - 1;

	for(int i=0; i<MAX; i++){
		scanf("%d", &n);
		if (n > num_max)
			num_max = n;
	}
	printf("%d\n", num_max);
}