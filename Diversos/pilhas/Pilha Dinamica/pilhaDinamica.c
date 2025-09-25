#include <stdlib.h>
#include <stdio.h>

#include "pilhaDinamica.h"

struct no
{
    int dado;
    No *proximo;
};

void iniciaPilha (No *topo)
{
    topo = NULL;
}

No* empilha(No *topo, int dado)
{
    No* novoNo = (No*)malloc(sizeof(No));

    if (novoNo)
    {
        novoNo->proximo = topo;
        novoNo->dado = dado;     

        topo = &novoNo;

        return novoNo;
    }
    else
    {
        fprintf(stderr, "Erro ao alocar memoria!");
        exit(EXIT_FAILURE);
    }
}