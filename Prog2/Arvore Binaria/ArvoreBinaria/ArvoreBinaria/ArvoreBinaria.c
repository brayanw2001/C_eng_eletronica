#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"

no* Inicializa()
{
	return NULL;
}

no* CriaNo(char info)
{
	no* novoNo = (no*) malloc(sizeof(no));
	novoNo->id = geraId();
	novoNo->info = info;
	novoNo->esq = NULL;
	novoNo->dir = NULL;

	return novoNo;
}

int geraId()
{
	static int id = 0;
	return id++;
}

void Imprime(no* raiz, int tab)
{
	for (int i = 0; i < tab; i++)
	{
		printf("-");
	}

	if (raiz != NULL)
	{
		printf("%c | %d\n", raiz->info, raiz->id);
		Imprime(raiz->esq, tab + 2);
		printf("\n");
		Imprime(raiz->dir, tab + 2);
	}
	else printf("vazio");
}

// Busca recursiva. Mais elegante, porém menos otimizada
// no* Busca(no* no, int id)
// {
// 	if (no == NULL)
// 		return NULL;
//
// 	else if (id < no->id)
// 		return Busca(no->esq, id);
//
// 	else if (id > no->id)
// 		return Busca(no->dir, id);
//
// 	else
// 		return no;
// }

// Busca iterativa
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
		else
			return no;
	}
	return NULL;
}
