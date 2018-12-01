#include <stdio.h> 

void diff_abs(float* a, float* b);

int main()
{
	float var1, var2;
	scanf("%f\n%f", &var1, &var2);
	diff_abs(&var1, &var2);

	printf("%.2f\n%.2f\n", var1, var2);

	return 0;
}

void diff_abs(float* a, float* b)
{
	*a -= *b;
	*b -= (*a + *b);
}