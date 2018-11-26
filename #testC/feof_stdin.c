#include <stdio.h>

int main()
{
	char s[10], s1[10];
	int cnt = 0;
	while (!feof(stdin))
	{
		
		scanf("%10s %10s", s, s1);
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}