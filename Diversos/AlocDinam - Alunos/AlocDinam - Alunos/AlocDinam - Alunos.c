#include <stdio.h>
#include <stdlib.h>

typedef struct Alunos
{
    unsigned int matricula;
    char nome[20];
    unsigned int anoNascimento;

} Alunos;

Alunos **ptrAlunos();

//função para cadastrar alunos

// função para mostrar alunos

int main()
{
    
}

Alunos ** ptrAlunos()
{
    int qtdAlunos;

    printf("Quantos alunos serão cadastrados?");
    scanf_s("%d", &qtdAlunos);

    return (Alunos*)calloc(qtdAlunos, sizeof(Alunos));
}