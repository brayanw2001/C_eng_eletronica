#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"
#include  "ControleDeVoo.h"

no* Inicializa()
{
	return NULL;
}

void LiberaArvore(no* n)
{
	if (n != NULL)
	{
		LiberaArvore(n->dir);
		LiberaArvore(n->esq);
		free(n);
	}
}

no* InsereNos(dados* info, int numTarefas)
{
	no* novoNo = Inicializa();

	if (novoNo == NULL)
	{
		novoNo = (no*)malloc(sizeof(no));
		novoNo->dado = info[0];
		novoNo->esq = NULL;
		novoNo->dir = NULL;
	}

	struct no* raiz = novoNo;

		for (int i = 1; i < numTarefas; i++) 
		{
			while (novoNo != NULL)
			{
				if (info[i].prior < novoNo->dado.prior)
				{
					//no->esq = info[i].prior;
					if (novoNo->esq == NULL)
					{
						novoNo->esq = (no*)malloc(sizeof(no));
						novoNo->esq->dado = info[i];
						novoNo->esq->esq = NULL;
						novoNo->esq->dir = NULL;
						break;
					}

					novoNo = novoNo->esq;
				}
				else if (info[i].prior > novoNo->dado.prior)
				{
					if (novoNo->dir == NULL)
					{
						novoNo->dir = malloc(sizeof(no));
						novoNo->dir->dado = info[i];
						novoNo->dir->dir = NULL;
						novoNo->dir->esq = NULL;
						break;
					}
					novoNo = novoNo->dir;
				}
			}
			novoNo = raiz;
		}
	return raiz;
}

void Imprime(no* no, int tab)
{
	if (no == NULL)
		return;
	
	for (int i = 0; i < tab; i++)
	{
		printf("-");
	}

	if (no != NULL)
	{
		printf("%d\n", no->dado.prior);
		Imprime(no->esq, tab + 1);
		Imprime(no->dir, tab + 1);
	}
	else printf("vazio");
}

no* Busca(no* no, int id)
{
	if (no == NULL)
		return NULL;

	while (no != NULL)
	{
		if (id < no->dado.prior)
			no = no->esq;
		else if (id > no->dado.prior)
			no = no->dir;
		else                        // se for igual (achou) retorna o no
			return no;
	}
	return NULL;
}

