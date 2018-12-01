#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_DIM 15

struct cand
{
	char nome[STR_DIM];
	short voti;
	struct cand* next;
};

typedef struct cand Candidato;
typedef Candidato* CandidatoPtr;

void addVoto(CandidatoPtr *list_curr, char* voto);

void findRappr(CandidatoPtr list_curr, CandidatoPtr vet[], int fst_max, int snd_max);

int main()
{
	FILE* fPtr;

	if ( (fPtr = fopen("input.txt", "r")) == NULL )
	{
		puts("Impossibile aprire il file di input\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		CandidatoPtr list = NULL;
		char tmp[STR_DIM], tmp2[STR_DIM];
		while (!feof(fPtr))
		{
			fscanf(fPtr, "%[^,],%[^\n]\n", &tmp, &tmp2);
			//printf("%10s\t%10s\n", tmp, tmp2);
			addVoto(&list, tmp);
			addVoto(&list, tmp2);
		}
		fclose(fPtr);

		CandidatoPtr rappr[2];
		rappr[0] = NULL;
		rappr[1] = NULL;

		findRappr(list, rappr, 0, 0);

		for(int a = 0; a < 2; a++)
			printf("%s con %d voti\n", rappr[a]->nome, rappr[a]->voti);

		return 0;
	}
}

void addVoto(CandidatoPtr *list_curr, char* voto)
{
	if (*list_curr == NULL)
	{
		CandidatoPtr new_cand = calloc(1, sizeof(Candidato));

		if(!new_cand)
			puts("Memoria Esaurita\n");
		else
		{
			memmove(new_cand->nome, voto, STR_DIM);
			new_cand->voti = 1;
			new_cand->next = NULL;

			*list_curr = new_cand;
		}
	} 
	else if ( strcmp((*list_curr)->nome, voto) == 0 )
	{
		(*list_curr)->voti++;
	}
	else if ( (*list_curr)->next == NULL )
	{
		CandidatoPtr new_cand = calloc(1, sizeof(Candidato));

		if(!new_cand)
			puts("Memoria Esaurita\n");
		else
		{
			memmove(new_cand->nome, voto, STR_DIM);
			new_cand->voti = 1;
			new_cand->next = NULL;

			(*list_curr)->next = new_cand;
		}
	} else 
	{
		addVoto( &(*list_curr)->next, voto);
	}
}

void findRappr(CandidatoPtr list_curr, CandidatoPtr vet[], int fst_max, int snd_max)
{
	if (list_curr != NULL)
	{
		//printf("CANDIDATO: %-10s\tVOTI: %-4d\t\n", list_curr->nome, list_curr->voti);
		if (list_curr->voti >= fst_max)
		{
			if (vet[0] != NULL)
			{
				if ( (list_curr->voti == fst_max && strcmp(list_curr->nome, vet[0]->nome) > 0 )
					|| list_curr->voti > fst_max )
				{
					snd_max = fst_max; // al secondo assegno il vecchio primo
					vet[1] = vet[0];

					fst_max = list_curr->voti;
					vet[0] = list_curr;
				}
			} else // caso 0
			{
				fst_max = list_curr->voti;
				vet[0] = list_curr;
			}
		}
		else if (list_curr->voti >= snd_max)
		{
			if (vet[1] != NULL)
			{
				if ( (list_curr->voti == snd_max && strcmp(list_curr->nome, vet[1]->nome) > 0 )
					|| list_curr->voti > snd_max )
				{
					snd_max = list_curr->voti;
					vet[1] = list_curr;
				}
			} else // caso 0
			{
				snd_max = list_curr->voti;
				vet[1] = list_curr;
			}
		}

		findRappr(list_curr->next, vet, fst_max, snd_max);
	}


}

void print_list(CandidatoPtr list_curr)
{
	if (list_curr != NULL)
	{
		printf("CANDIDATO: %-10s\tVOTI: %-4d\t\n", list_curr->nome, list_curr->voti);
		print_list(list_curr->next);
	}
}