#include <stdio.h>
#include <math.h>

int main(){
	float num1, num2, ris;
	char op;
	//int num1_int, num2_int;

	if (scanf("%f\n%f\n%c",&num1, &num2, &op) == 3)
	{
		switch(op)
		{
			case '+':
				printf("%.1f", (float)(num1 + num2));
				break;
			case '-':
				printf("%.1f", (float)(num1 - num2));
				break;
			case '/':
				printf("%.1f", (float)(num1 / num2));
				break;
			case '%':
				printf("%.1f", (float) ((int)num1 % (int)num2));
				break;
			default:
				printf("invalid operator");
				break;
		}	
	}
	return 0;
}