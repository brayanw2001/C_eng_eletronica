// Implemente um TAD para representar números complexos. Crie funções para soma, subtração, 
// multiplicação, divisão e módulo de um número complexo.

#include "NumerosComplexos.h"

int main() 
{
    VetorNumerosComplexos* vec = criaVetor(5);
    adicionaComplexos(vec, 2, 3);
    adicionaComplexos(vec, 4, 5);
    soma(vec, 0, 1);
    
    char ch;
    scanf("%c", &ch);

    return 0;
}