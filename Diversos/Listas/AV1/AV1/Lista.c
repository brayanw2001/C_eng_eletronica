#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Lista.h"

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
	if (topo == NULL) return;

	char nome[40];
	printf("Nome: ");
	fgets(nome, sizeof(nome), stdin);
	nome[strlen(nome) - 1] = '\0';

	no* ptrAux = topo;

	while (strcmp((ptrAux->contato.nome), nome) != 0)
	{
		if (ptrAux->proximo == NULL)
			return NULL;

		ptrAux = ptrAux->proximo;
	}
	printf("ptrAux->contato.nome = %s\n", ptrAux->contato.nome);
	printf("Endereço de ptrAux: %p\n", (void*)ptrAux);
	return ptrAux;
}

void AtualizaContato(no* topo)
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
	printf("Endereço de ptrAux: %p\n", (void*)pesquisa);
	printf("pesquisa->contato.nome = %s\n", pesquisa->contato.nome);

	if (ptrAux == NULL) return;
	
	if (topo == pesquisa)
	{
		topo = topo->proximo;
		free(pesquisa);
		return topo;
	}
	else
	{
		while (ptrAux->proximo != pesquisa)
		{
			ptrAux = ptrAux->proximo;
			if (ptrAux == NULL) return;
		}

		ptrAux->proximo = pesquisa->proximo;

		free(pesquisa);
		return topo;
	}
}

void RemoveDuplicado(no* topo)
{
	if (topo == NULL) return;
	if (topo->proximo == NULL) return;

	no *ptrAux, *ptrAux2, *duplicado;
	ptrAux = topo;

	while (ptrAux != NULL && ptrAux->proximo != NULL)
	{
		ptrAux2 = ptrAux;

		while (ptrAux2->proximo != NULL)
		{
			if (strcmp(ptrAux->contato.nome, ptrAux2->proximo->contato.nome) == 0)
			{
				duplicado = ptrAux2->proximo;
				ptrAux2->proximo = ptrAux2->proximo->proximo;
				free(duplicado);
				MostraLista(topo);
			}
			else
			{
				ptrAux2 = ptrAux2->proximo;
			}
		}
		ptrAux = ptrAux->proximo;
	}
}

void OrdenaListaAlfabetica(no* topo)
{
	if (topo == NULL || topo->proximo == NULL)
		return;

	int trocou;
	no* ptrAux;
	pessoa temp;

	do
	{
		trocou = 0;
		ptrAux = topo;

		while (ptrAux->proximo != NULL)
		{
			if (strcmp(ptrAux->contato.nome, ptrAux->proximo->contato.nome) > 0)
			{
				temp = ptrAux->contato;
				ptrAux->contato = ptrAux->proximo->contato;
				ptrAux->proximo->contato = temp;
				trocou = 1;
			}
			ptrAux = ptrAux->proximo;
		}

	} while (trocou);
}
