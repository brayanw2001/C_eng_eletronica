#include"NumerosComplexos.h"
#include<stdlib.h>
#include<stdio.h>

struct NumeroComplexo
{
    int a;          // parte real
    int b;          // parte imaginaria
};

struct VetorNumerosComplexos
{
    int tamanho;
    int capacidade;
    NumeroComplexo* dados;
};

NumeroComplexo* adicionaComplexos(VetorNumerosComplexos *vec, int real, int imaginario)
{
    if (vec->tamanho == vec->capacidade)
    {
        fprintf(stderr, "Erro ao adicionar'\n");
        fprintf(stderr, "O vetor está cheio'\n");
        exit(EXIT_FAILURE);
    }
     vec->dados[vec->tamanho].a = real;
     vec->dados[vec->tamanho].b = imaginario;
     vec->tamanho++;
}

VetorNumerosComplexos* criaVetor(int capacidade)
{
    VetorNumerosComplexos* vec = (VetorNumerosComplexos*)calloc(1, sizeof(VetorNumerosComplexos));
    vec->capacidade = capacidade;
    vec->tamanho = 0;
    vec->dados = (NumeroComplexo*)calloc(capacidade, sizeof(NumeroComplexo));
}

void soma (VetorNumerosComplexos* vec, int n1, int n2)
{
    printf("%da+%di", (vec->dados[n1].a + vec->dados[n2].a), (vec->dados[n1].b + vec->dados[n2].b));   
}