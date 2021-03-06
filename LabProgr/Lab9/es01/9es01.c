#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_DIM 15

struct studente
{
	char nome[15];
	char cognome[15];
	short voto;
	struct studente* next; 
}; 

typedef struct studente Studente;
typedef Studente* StudentePtr;

void printIfPassed(StudentePtr list_curr);
void addStud(Studente** list_curr, char* nome, char* cognome, short voto);

int main()
{
	FILE* filePtr = fopen("input.txt", "r");
	if (!filePtr)
		exit(EXIT_FAILURE);

	StudentePtr list = NULL;

	char nome_tmp[STR_DIM], cogn_tmp[STR_DIM];
	memset(cogn_tmp, 0, STR_DIM);
	memset(nome_tmp, 0, STR_DIM);
	short voto_tmp = 0;

	while ( !feof(filePtr) )
	{
		fscanf(filePtr, "%[^;];%[^;];%hd\n", &cogn_tmp, &nome_tmp, &voto_tmp);
		addStud(&list, cogn_tmp, nome_tmp, voto_tmp);
	}
	fclose(filePtr);

	printIfPassed(list);
}

void printIfPassed(StudentePtr list_curr)
{
	if (list_curr != NULL && list_curr->voto >= 18)
	{
		printf("%10s%10s%4hd ESAME SUPERATO\n", list_curr->cognome, list_curr->nome, list_curr->voto);
		printIfPassed(list_curr->next);
	}
	// essendo già ordinati stop
}

void addStud(StudentePtr* list_curr, char* cognome, char* nome, short voto)
{
	if (*list_curr == NULL)
	{
		StudentePtr new_stud = calloc(1, sizeof(Studente));

		if (new_stud == NULL)
			puts("Memoria esaurita\n");
		else 
		{
			memmove(new_stud->nome, nome, STR_DIM);
			memmove(new_stud->cognome, cognome, STR_DIM);
			new_stud->voto = voto;
			new_stud->next = NULL;

			*list_curr = new_stud;
		}
	}
	else if ((*list_curr)->voto < voto)
	{
		StudentePtr new_stud = calloc(1, sizeof(Studente));

		if (new_stud == NULL)
			puts("Memoria esaurita\n");
		else 
		{
			memmove(new_stud->nome, nome, STR_DIM);
			memmove(new_stud->cognome, cognome, STR_DIM);
			new_stud->voto = voto;
			new_stud->next = *list_curr;
			*list_curr = new_stud;
		}
	} 
	else
	{
		addStud(&((*list_curr)->next), nome,  cognome, voto);
	}
}