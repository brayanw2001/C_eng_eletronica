#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

struct No
{
	int dado;
	no* proximo;
};

no* InsereNoTopo(no* topo, int dado)
{
	no* novoNo = calloc(1, sizeof(no));

	if (novoNo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória. Nenhuma modificacao foi feita na fila.");
		return topo;
	}

	novoNo->proximo = topo;
	novoNo->dado = dado;
	return novoNo;
}

no* InsereNoFim(no* topo, int dado)
{
	no* novoNo = calloc(1, sizeof(no));
	
	if (novoNo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória. Nenhuma modificacao foi feita na fila.");
		return topo;
	}

	novoNo->dado = dado;

	if (topo == NULL) return novoNo;

	no* ptrAux = topo;

	while (ptrAux->proximo != NULL)
	{
		ptrAux = ptrAux->proximo;
	}

	ptrAux->proximo = novoNo;
	//novoNo->proximo = NULL;  (não é necessário pois o calloc ja aloca como 0/NULL)
	return topo;
}

void MostraLista(no* topo)
{
	int i = 0;
	no* ptrAux = topo;		//não precisaria do aux, mas acredito que melhora o entendimento

	while (ptrAux->proximo != NULL)
	{
		printf("[%d] - %d\n", i, ptrAux->dado);
		ptrAux = ptrAux->proximo;
		i++;
	}
	printf("[%d] - %d\n", i, ptrAux->dado);

}