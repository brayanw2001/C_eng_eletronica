#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include"pilha.h"

int main(void) {
    setlocale(LC_ALL, "pt-br");

    pilhas* pilha = criaPilha();

    push(pilha, 5);
    push(pilha, 14);
    push(pilha, 13);
    push(pilha, 27);

    imprimeLista(pilha);
    pop(pilha);
    printf("\n");
    topo(pilha);
    printf("\n");
    imprimeLista(pilha);


    free(pilha);
        
    return 0;
}
