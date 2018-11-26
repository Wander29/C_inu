#include <stdio.h>

#define MAX 10

int main(){

	char x, y, w, a, b, temp;
	int cnt = 0;

	while ( cnt < 10 )
	{
		printf("%d: ", cnt+1);
		/*while ( scanf("%[a-z]", &temp) != 1 ) 
		{
		 	printf("CARATTERE NON ALFABETICO (solo minuscolo!)\n%d: ", cnt+1);
		 	while (getchar() != '\n');
		}*/
		while (getchar() != '\n'); //svuoto il buffer di input

		scanf("%c", &temp);
		switch (cnt)
		{
			case 0:
				x = temp;
				break;
			case 1:
				y = temp;
				break;
			case 2:
				w = temp;
				break;
			case 5:
				if (temp != y && temp != w)
					a = temp;
				else
					cnt = -1;
				break;
			case 6:
				if (temp != y && temp != w)
					b = temp;
				else
					cnt = -1;
				break;
			default:
				if (temp != x)
					cnt = -1;
				break;
		}
		cnt ++;
	}
	printf("%c%c%c%c%c%c%c%c%c%c", x, y, w, x, x, a, b, x, x, x);
	return 0;

}