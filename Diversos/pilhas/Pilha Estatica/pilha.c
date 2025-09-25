#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

struct pilhas 
{
    int topo;
    int dados[TAM_DADOS_PILHA];
};

pilhas* criaPilha()
{
    pilhas* pilha = (pilhas*)malloc(sizeof(pilhas));

    pilha->topo = 0;

    return pilha;
}

void push (pilhas *pilha, int dado)
{
    if(pilha->topo > TAM_DADOS_PILHA)
    {
        fprintf(stderr, "Tamanho maximo da pilha atingido!\n");
        exit(EXIT_FAILURE);
    }
    
    pilha->dados[pilha->topo] = dado;
    pilha->topo++;
}

void pop(pilhas *pilha)
{
    int aux = pilha->dados[pilha->topo-1];
    
    if (pilha->topo < 0  || pilha->topo > TAM_DADOS_PILHA)
    {
        fprintf(stderr, "Pilha corrompida!");
        exit(EXIT_FAILURE);
    }

    if (pilha->topo == 0)
    {
        fprintf(stderr, "A pilha já está vazia");
    }

    printf("Dado removido: %d", aux);

    pilha->topo = pilha->topo - 2;      // avaliar mudar essa logica para um aux ponteiro

}

void topo(pilhas *pilha)
{
    printf("Valor no topo: %d", pilha->dados[pilha->topo]);
}

void imprimeLista(pilhas *pilha)
{
    for (int i = 0; i <= pilha->topo; i++)
    {
        printf("%d\n", pilha->dados[i]);
    }
}