#include <stdio.h>

void fibonacci(int x);

static int f0 = 0, f1 = 1, f2 = 1;

int main()
{
	int x;
	while (scanf("%d", &x) < 1 || x < 0)
	{
		while (getchar() != '\n');
	}

	printf("%d\n", f0);
	if (x != 0)
	{
		printf("%d\n", f1);
		fibonacci(x);
	}
	return 0;
}

void fibonacci(int x)
{
	if (f2 <= x)
	{
		printf("%d\n", f2);
		f0 = f1;
		f1 = f2;
		f2 = f0 + f1;

		fibonacci(x);
	}
}