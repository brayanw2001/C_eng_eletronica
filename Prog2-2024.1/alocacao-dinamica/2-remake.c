#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void alocaVetor (int **vetor, int *qtdVetor);
void apresentaVetor (int *vetor, int *qtdVetor);

int main (){

    setlocale(LC_ALL, "pt-br");

    int *pt1_vetor, qtdVetor = 0;

    alocaVetor (&pt1_vetor, &qtdVetor);
    apresentaVetor (pt1_vetor, &qtdVetor);

return 0;
}

void alocaVetor (int **vetor, int *qtdVetor){
    printf ("Insira a quantidade de vetores desejada: ");
    scanf ("%d", qtdVetor);

    *vetor = calloc (*qtdVetor, sizeof(int));

    for (int i = 0; i < *qtdVetor; i++) {
        printf("Insira N%d: ", i+1);
        scanf("%d", &((*vetor)[i]));
    }
}

void apresentaVetor (int *vetor, int *qtdVetor){
    printf("\n");
    for (int j = 0; j < *qtdVetor; j++) {
        printf("[%d]: %d\n", j, vetor[j]);
    }    
}