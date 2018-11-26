#include <stdio.h>
#include <stdlib.h>

#define DIM_STR 256

typedef enum {
	OK = 1, FAILED = 999
} STATO;

int move(int state, char c);

STATO status_riconoscimento = OK;

int main()
{
	int stato = 0; // stato iniziale

	char *buffer = calloc(DIM_STR, sizeof(char));
	buffer[DIM_STR-1] = '\0'; // lo definisco stringa, non array di char semplicemente

	scanf("%[^\n]", buffer); // buffer interno

	char c;
	int i = 1; // cnt che mi servirà per scorrere il buffer

	sscanf(buffer, "%c", &c); // leggo la prima lettera nel buffer stringa
	while (status_riconoscimento == OK && c != '\0')
	{	
		stato = move(stato, c);
		c = buffer[i++];
	}

//Stati FINALI, in questo solamente 1
	const int end = 6;
	if (stato == end)
		printf("Stringa rincosciuta!\n");
	else
		printf("Stringa NON rincosciuta...\n");
	
}

int move(int state, char c)
{
	switch(state)
	{
		case 0:
			if(c >= 'a' && c <= 'z')
				return 1;
			else
				status_riconoscimento = FAILED;
			break;

		case 1:
			if (c >= '0' && c <= '9')
				return 2;
			else if (c == 'f')
				return 3;
			else
				status_riconoscimento = FAILED;
			break;

		case 2:
			if (c >= '0' && c <= '9')
				return 2;
			else if (c == 'f')
				return 3;
			else
				status_riconoscimento = FAILED;
			break;

		case 3:
			if (c == 'i')
				return 4;
			else
				status_riconoscimento = FAILED;
			break;

		case 4:
			if (c == 'n')
				return 5;
			else
				status_riconoscimento = FAILED;
			break;

		case 5:
			if (c == 'e')
				return 6;
			else
				status_riconoscimento = FAILED;
			break;

		default:
			status_riconoscimento = FAILED;
			break;
	}
	return status_riconoscimento;
}
