#include <stdio.h>

#define MAX 3

int main(){
	float n, media;

	for(int i=0; i<MAX; i++){
		scanf("%f", &n);
		media += n;
	}
	printf("%.3f\n", media/MAX);
}