//Escreva um programa que aloque dinamicamente uma matriz(de inteiros) de dimensões
//definidas pelo usuário e a leia. Em seguida, implemente uma função que receba um
//valor, retorne 1 caso o valor esteja na matriz ou retorne zero caso não esteja na matriz
#include <stdio.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS

void alocaMatriz(int m, int n, int*** matriz);

int main()
{
    int m, n;
    int** matriz;

    printf("Insira o numero de linhas da matriz: ");
    scanf("%d", &m);
    //while (getchar() != '\n');

    printf("Insira o numero de colunas da matriz: ");
    scanf("%d", &n);
    //while (getchar() != '\n');

    alocaMatriz(m, n, &matriz);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Insira o membro [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n[%d]", matriz[i][j]);
        }
    }

    return 0;
}

void alocaMatriz(int m, int n, int*** matriz)
{
    *matriz = (int**)calloc(m, sizeof(int*));

    for (int i = 0; i < m; i++)
    {
        (*matriz)[i] = (int*)calloc(m, sizeof(int));
    }
}


