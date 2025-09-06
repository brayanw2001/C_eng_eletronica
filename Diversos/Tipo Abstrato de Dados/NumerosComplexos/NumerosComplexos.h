#include<stdio.h>
#include<stdlib.h>

typedef struct NumeroComplexo NumeroComplexo;
// numReal
// numImaginario
typedef struct VetorNumerosComplexos VetorNumerosComplexos;
//capacidade
//tamanho
//dados

VetorNumerosComplexos* criaVetor(int capacidade);
NumeroComplexo* adicionaComplexos(VetorNumerosComplexos *vec, int real, int imaginario);
//VetorNumerosComplexos destroiVetor(VetorNumerosComplexos** vec_ref);
void soma (VetorNumerosComplexos* vec, int n1, int n2);
//void sub (VetorNumerosComplexos* vec, int n1, int n2);
//void div (VetorNumerosComplexos* vec, int n1, int n2);
//void mul (VetorNumerosComplexos* vec, int n1, int n2);