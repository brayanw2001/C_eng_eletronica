#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int preencheVetor (int TamVetor);
int *alocaVetor (int *Vetor, int TamVetor);
void apresentaVetor (int *Vetor, int TamVetor);

int main (){

    setlocale(LC_ALL, "pt-br");
    int tamVetor = 0, *vetor;

    tamVetor = preencheVetor(tamVetor);
    vetor = alocaVetor (vetor, tamVetor);
    apresentaVetor (vetor, tamVetor);

    free(vetor);

return 0;
}

int preencheVetor (int TamVetor){
    printf("Insira o tamanho desejado: ");
    scanf ("%d", &TamVetor);
    return TamVetor;
}

int *alocaVetor (int *Vetor, int TamVetor){
    Vetor = calloc (TamVetor, sizeof(int));

    for (int i = 0; i < TamVetor; i++){
        printf ("Insira N%d: ", i);
        scanf("%d", &Vetor[i]);
    }
    /*for (int j = 0; j < TamVetor; j++){
        printf("[TESTE]: %d\n", Vetor[j]);
    }*/
    return Vetor;
}

void apresentaVetor (int *Vetor, int TamVetor){
    for (int i = 0; i < TamVetor; i++){
        printf ("[%d]: %d\n", i, Vetor[i]);
    }
}