#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Alunos
{
    unsigned int matricula;
    char nome[20];
    unsigned int anoNascimento;

} Alunos;

Alunos* ptrAlunos(int* qtdAlunos);
void cadastraAlunos(Alunos* alunos, int qtdAlunos);
void mostraAlunos(Alunos* alunos, int qtdAlunos);


int main()
{
    setlocale(LC_ALL, "portuguese");

    int qtdAlunos;

    Alunos* alunos = ptrAlunos(&qtdAlunos);

    cadastraAlunos(alunos, qtdAlunos);
    mostraAlunos(alunos, qtdAlunos);
    
    free(alunos);

    return 0;
}

Alunos* ptrAlunos(int* qtdAlunos)
{
    printf("Quantos alunos serao cadastrados? ");
    scanf_s("%d", qtdAlunos);
    while (getchar() != '\n');

    return (Alunos*)calloc(*qtdAlunos, sizeof(Alunos));
}

void cadastraAlunos(Alunos* alunos, int qtdAlunos)
{
    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("\nAluno %d", i+1);

        printf("\nInsira a matricula: ");
        scanf_s("%u", &alunos[i].matricula);
        while (getchar() != '\n');

        printf("Insira o nome: ");
        fgets(alunos[i].nome, 20, stdin);
        
        printf("Insira o ano de nascimento: ");
        scanf_s("%u", &alunos[i].anoNascimento);
        while (getchar() != '\n');
    }
}

void mostraAlunos(Alunos* alunos, int qtdAlunos)
{
    for (int i = 0; i < qtdAlunos; i++)
    {
        printf("\nAluno %d", i + 1);
        printf("\n%u", alunos[i].matricula);
        printf("\n%s", alunos[i].nome);
        printf("%u", alunos[i].anoNascimento);
        printf("\n");
    }
}
