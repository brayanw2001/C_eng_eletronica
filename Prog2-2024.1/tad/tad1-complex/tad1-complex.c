#include "tad1-complex.h"
#include <stdlib.h>
#include <stdio.h>


struct num_complexo {
    float real;
    float imag;
};

complexo *criaComplexo (){
    int n;
    complexo *pt_complexo; //o ponteiro deve ser criado dentro da função para que possa ser retornado

    printf ("Insira a quantidade de números complexos: ");
    scanf ("%d", &n);

    pt_complexo = calloc (n, sizeof(complexo));

    for (int i = 0; i < n; i++){
        printf ("[%d] Insira a parte real: ", i+1);
        scanf("%f", &pt_complexo[i].real);
        printf ("[%d] Insira a parte imaginária: ", i+1);
        scanf("%f", &pt_complexo[i].imag);
    }

    return pt_complexo;
}
