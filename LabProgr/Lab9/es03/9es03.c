#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define DIM_BUF 102

int read_int();

int main()
{
	FILE* fPtr;

	if ( (fPtr = fopen("input.txt", "r")) == NULL )
	{
		puts("Impossibile aprire il file\n");
		exit(EXIT_FAILURE);
	}

	char buffer[DIM_BUF], 
	char* aux = calloc(DIM_BUF, sizeof(char));
	if (!aux)
		puts("Memoria esaurita\n");
	aux[DIM_BUF-1] = '\0';

	memset(buffer, 0, DIM_BUF);

	int cnt_seq = 0;
	int max_len = 0;
	int tot = 0;
	int cnt_rows, len_temp;

	fgets(buffer, DIM_BUF, fPtr); // scarto
	while (!feof(fPtr))
	{
		cnt_rows = 1;

		fgets(buffer, DIM_BUF, fPtr); // prima riga utile
		do
		{
			sscanf(buffer, "%[^\n]\n", buffer);
			//len_temp = strlen(buffer);

			if (cnt_rows > 1)
				aux = realloc(aux, sizeof(char)*cnt_rows*DIM_BUF);

			strcat(aux, buffer);
			fgets(buffer, DIM_BUF, fPtr); 
			cnt_rows++;
		} while (buffer[0] != '>');

		if (buffer[0] == '>')
			fgets(buffer, DIM_BUF, fPtr);
		else
		{
			fgets(aux, DIM_BUF, fPtr);
		}
		cnt_seq++;

		sscanf(buffer, "%[^\n]\n", buffer);


		puts(buffer);
	}

}
