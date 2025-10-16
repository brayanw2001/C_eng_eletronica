#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"

//struct Pessoa
//{
//	char nome[40];
//	char email[40];
//	char telefone[15];
//};

//struct No
//{
//	pessoa contato;
//	no* proximo;
//};

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

	printf("\n%-20s%-20s%-20s\n", "NOME", "NUMERO", "EMAIL");

	while (ptrAux != NULL)
	{
        printf("%-20s%-20s%-20s\n", 
               ptrAux->contato.nome, 
               ptrAux->contato.telefone, 
               ptrAux->contato.email);

		ptrAux = ptrAux->proximo;
		i++;
	}

	printf("\n");
}

no* BuscaContato(no* topo)
{
	char nome[40];
	printf("Nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strlen(nome) - 1] = '\0';

	no* ptrAux = topo;

	while (strcmp((ptrAux->contato.nome), nome) != 0)
	{
		if (ptrAux->proximo == NULL && ptrAux->contato.nome != nome)
			return NULL;

		ptrAux = ptrAux->proximo;
	}
	return ptrAux;
}

no* AtualizaContato(no* topo)
{
	no* pesquisa = BuscaContato(topo);

	printf("\n=== EDITAR CONTATO ===");

	printf("\nNome: ");
	fgets(pesquisa->contato.nome, sizeof(pesquisa->contato.nome), stdin);
	pesquisa->contato.nome[strlen(pesquisa->contato.nome) - 1] = '\0';

	printf("Numero: ");
	fgets(pesquisa->contato.telefone, sizeof(pesquisa->contato.telefone), stdin);
	pesquisa->contato.telefone[strlen(pesquisa->contato.telefone) - 1] = '\0';

	printf("email: ");
	fgets(pesquisa->contato.email, sizeof(pesquisa->contato.email), stdin);
	pesquisa->contato.email[strlen(pesquisa->contato.email) - 1] = '\0';
}

no* RemoveContato(no* topo)
{
	no* ptrAux = topo;
	no* ptrAux2 = topo;
	no* pesquisa = BuscaContato(topo);

	while (ptrAux->proximo != pesquisa)
	{
		ptrAux = ptrAux->proximo;
	}

	ptrAux->proximo = pesquisa->proximo;

	free(pesquisa);
}
