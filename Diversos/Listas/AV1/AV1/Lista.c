#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

//struct Pessoa
//{
//	char nome[40];
//	char email[40];
//	unsigned short int telefone[15];
//};

struct No
{
	pessoa contato;
	no* proximo;
};

no* InsereNoTopo(no* topo, pessoa contato)
{
	no* novoNo = calloc(1, sizeof(no));

	if (novoNo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória. Nenhuma modificacao foi feita na fila.");
		return topo;
	}

	novoNo->proximo = topo;
	novoNo->contato = contato;
	return novoNo;
}

no* InsereNoFim(no* topo, pessoa contato)
{
	no* novoNo = calloc(1, sizeof(no));
	
	if (novoNo == NULL)
	{
		fprintf(stderr, "Erro ao alocar memória. Nenhuma modificacao foi feita na fila.");
		return topo;
	}

	novoNo->contato = contato;

	if (topo == NULL) return novoNo;

	no* ptrAux = topo;

	while (ptrAux->proximo != NULL)
	{
		ptrAux = ptrAux->proximo;
	}

	ptrAux->proximo = novoNo;
	return topo;
}

void MostraLista(no* topo)
{
	int i = 0;
	no* ptrAux = topo;		

	printf("NOME \t NUMERO \t EMAIL\n");

	while (ptrAux != NULL)
	{
		printf("%s \t %hu \t &s", ptrAux->contato.nome, ptrAux->contato.telefone, 
			ptrAux->contato.email);

		ptrAux = ptrAux->proximo;
		i++;
	}
}