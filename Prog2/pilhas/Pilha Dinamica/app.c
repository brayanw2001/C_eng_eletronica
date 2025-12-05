#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 

#include "pilhaDinamica.h"

int main(void)
{
    No *pilha = IniciaPilha();

    pilha = Empilha(pilha, 1);
    pilha = Empilha(pilha, 2);
    pilha = Empilha(pilha, 3);
    pilha = Empilha(pilha, 4);

    MostraPilha(pilha);
    Desempilha(&pilha);
    MostraPilha(pilha);


    return 0;
}