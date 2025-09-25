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

void empilha(No *topo, int dado)
{
    No* NovoNo = (No*)malloc(sizeof(No));

    NovoNo->proximo = topo;
    NovoNo->dado = dado;

    topo = &NovoNo;
}