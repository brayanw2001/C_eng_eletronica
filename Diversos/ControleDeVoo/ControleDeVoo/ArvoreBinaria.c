#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"
#include  "ControleDeVoo.h"

no* Inicializa()
{
	return NULL;
}

no* CriaNo(dados info)
{
	no* novoNo = (no*) malloc(sizeof(no));
	novoNo->dado = info;
	novoNo->esq = NULL;
	novoNo->dir = NULL;

	return novoNo;
}

void InsereNos(no* no, dados info)
{
	while (no != NULL)
	{
		if (info.prior < no->dado.prior)
			no = no->esq ;
		else if (info.prior > no->dado.prior)
			no = no->dir;
	}

	 if (info.prior < no->dado.prior)
		no->esq = CriaNo(info);
	 else if (info.prior > no->dado.prior)
	 	no->dir = CriaNo(info);
	 else
		printf("No ja existente ou invalido");
}

void Imprime(no* raiz, int tab)
{
	for (int i = 0; i < tab; i++)
	{
		printf("-");
	}

	if (raiz != NULL)
	{
		printf("%c\n", raiz->info);
		Imprime(raiz->esq, tab + 2);
		printf("\n");
		Imprime(raiz->dir, tab + 2);
	}
	else printf("vazio");
}

no* Busca(no* no, int id)
{
	if (no == NULL)
		return NULL;

	while (no != NULL)
	{
		if (id < no->id)
			no = no->esq;
		else if (id > no->id)
			no = no->dir;
		else                        // se for igual (achou) retorna o no
			return no;
	}
	return NULL;
}

