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
	novoNo->info = info;
	novoNo->esq = NULL;
	novoNo->dir = NULL;

	return novoNo;
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


