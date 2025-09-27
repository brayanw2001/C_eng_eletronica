#include <stdlib.h>
#include <stdio.h>

#include "pilhaDinamica.h"

struct no
{
    int dado;
    No* proximo;
};

No* IniciaPilha()
{
    No* topo = NULL;
    return topo;
}

No* Empilha(No* topo, int dado)
{
    No* novoNo = (No*)malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->proximo = topo;
        novoNo->dado = dado;

        topo = novoNo;

        return novoNo;
    }
    else
    {
        fprintf(stderr, "Erro ao alocar memoria!");
        exit(EXIT_FAILURE);
    }
}

No* Desempilha(No* topo)
{
    if (topo != NULL)
    {
        No* desempilhado = topo;

        topo = topo->proximo;

        printf("Dado removido: %d\n", desempilhado->dado);

        free(desempilhado);

        return topo;
    }
    else
    {
        fprintf(stderr, "A pilha está vazia. impossivel desempilhar\n");
        exit(EXIT_FAILURE);
    }
}

void MostraPilha(No* topo)
{
    printf("\nPilha:");

    for (No* ptr = topo; ptr != NULL; ptr = ptr->proximo)
    {
        printf("\n%d", ptr->dado);
    }
}