#include <stdio.h>
#include <stdarg.h>

void stampa(const int n, ...);

int main(int arg)
{
	stampa(3, 'A', 3.04, 4.1);
	return 0;
}

void stampa(const int n, ...)
{
	int tmp;
	va_list arg;
	va_start(arg, n);
	if ( (tmp = va_arg(arg, int)) )
		printf("%d\n", tmp);

	va_end(arg);
}


