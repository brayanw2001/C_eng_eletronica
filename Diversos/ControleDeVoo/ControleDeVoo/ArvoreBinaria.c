#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"
#include  "ControleDeVoo.h"

no* Inicializa()
{
	return NULL;
}

//void InsereNos(no* no, dados* info)
//{
//	dados* novoNo = CriaNo(info);
//
//	while (no != NULL)
//	{
//		if (info->prior < no->dado->prior)
//			no = no->esq ;
//		else if (info->prior > no->dado->prior)
//			no = no->dir;
//	}
//
//	 if (info->prior < no->dado->prior)
//		no->esq = CriaNo(info);
//	 else if (info->prior > no->dado->prior)
//	 	no->dir = CriaNo(info);
//	 else
//		printf("No ja existente ou invalido");
//}
no* InsereNos(dados* info, int numTarefas)
{
	no* no = Inicializa();

	if (no == NULL)
	{
		no = malloc(sizeof(no));
		no->dado = info[0];
		no->esq = NULL;
		no->dir = NULL;
	}

	struct no* raiz = no;

		for (int i = 1; i < numTarefas; i++) 
		{
			while (no != NULL)
			{
				if (info[i].prior < no->dado.prior)
				{
					//no->esq = info[i].prior;
					if (no->esq == NULL)
					{
						no->esq = malloc(sizeof(no));
						no->esq->dado = info[i];
						no->esq->esq = NULL;
						no->esq->dir = NULL;
						break;
					}

					no = no->esq;
				}
				else if (info[i].prior > no->dado.prior)
				{
					if (no->dir == NULL)
					{
						no->dir = malloc(sizeof(no));
						no->dir->dado = info[i];
						no->dir->dir = NULL;
						no->dir->esq = NULL;
						break;
					}
					no = no->dir;
				}
			}
			no = raiz;
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

