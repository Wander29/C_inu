#include <stdio.h>

int main()
{
	int v = 3;

	printf("%p\n%d\n", &v, *&(v));

}