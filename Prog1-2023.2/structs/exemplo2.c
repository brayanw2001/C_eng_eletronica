#include <stdio.h>
#include <math.h>
#include <locale.h>
#define TAM 10

struct turma {
    char nome [20];
    char matricula [7];
    float notas [3];
    float media;
};

int main (){

    setlocale(LC_ALL, "");

    struct turma alunos [TAM];
    char opc;
    int i, j;
    float soma = 0;

    for (i = 0; i < TAM; i++)
    {
        printf("Insira o nome do aluno: ");
        scanf ("%20[^\n]", alunos[i].nome);
        while (getchar() != '\n');

        printf("Insira a matrícula do aluno: ");
        scanf ("%7[^\n]", alunos[i].matricula);
        while (getchar() != '\n');

        for (j = 0; j < 3; j++)
        {
            printf("Insira as 3 notas do aluno: ");
            scanf("%f", &alunos[i].notas[j]);
            //while (getchar() != '\n');
            soma = alunos[i].notas[j] + soma;
            alunos[i].media = soma/(j+1);
           // printf("\n\nmedia do aluno %i: %.2f\n\n", alunos[i], alunos[i].media);
        }
        printf("A média do aluno %s, de matricula ' %s ', foi de: %.2f\n", alunos[i].nome, alunos[i].matricula, alunos[i].media);
        printf("\n\nDeseja continuar? Sim[S] ou Não[N]: ");
        while (getchar() != '\n');
        scanf("%c", &opc);
        while (getchar() != '\n');

        if (opc == 'N'||opc == 'n'){
            break;
        }
        else {
            soma = 0;
            continue;
        }
    }

return 0;
}