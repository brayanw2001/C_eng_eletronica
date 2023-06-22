#include <stdio.h>
#include <math.h>
#include <locale.h>

struct gym
{
    char nome[20];
    char sexo;
    int idade, peso;
    float altura;
    float imc;
};

struct gym IMC (struct gym Alunos[]);         //a função do tipo STRUCT GYM, chamada IMC, receberá a cópia de struct gym alunos[20]

int main (){

    setlocale(LC_ALL, "");
    int i, j;

    struct gym alunos[20];

    inicio:
    for (i = 0; i < 20; i++){
        printf("Insira o nome do aluno: ");
        scanf ("%20[^\n]", alunos[i].nome);
        while (getchar() != '\n');    //limpa buffer

        printf("Insira 'M' para masculino ou 'F' para feminino: "); 
        scanf ("%c", &alunos[i].sexo);
        if (alunos[i].sexo != 'M' || alunos[i].sexo != 'F' || alunos[i].sexo != 'm' || alunos[i].sexo != 'f'){
            printf("Opção inválida!\n");
            while (getchar() != '\n');
            goto inicio;
        }

        printf("Insira a idade: ");
        scanf("%d", &alunos[i].idade);

        printf("Insira o peso: ");
        scanf("%d", &alunos[i].peso);

        printf("Insira a altura, em metros: ");
        scanf("%f", &alunos[i].altura);

        IMC (alunos);               //A função IMC recebe a variável alunos

    }
 
return 0;
}

struct gym IMC (struct gym Alunos[]){
    int i;

    for (i = 0; i < 20; i++)
    {
        Alunos[i].imc = (Alunos[i].peso) / ((Alunos[i].altura)*(Alunos[i].altura));             //calculo imc

        if (Alunos[i].sexo == 'm' || Alunos[i].sexo == 'M'){
            if (Alunos[i].imc > 30.0){
                printf("Aluno: %s\nIMC: %.2f: Obesidade\n", Alunos[i].nome, Alunos[i].imc);
            }
            else if (Alunos[i].imc < 18.5){
                printf("Aluno: %s\nIMC: %.2f: Abaixo do peso\n", Alunos[i].nome, Alunos[i].imc);
            }
            else{
                printf("Aluno: %s\nIMC: %.2f: Peso normal\n", Alunos[i].nome, Alunos[i].imc);
            }
        }
        else if (Alunos[i].sexo == 'f' || Alunos[i].sexo == 'F'){
            if (Alunos[i].imc > 25.0){
                printf("Aluno: %s\n IMC: %.2f: Obesidade\n", Alunos[i].nome, Alunos[i].imc);
            }
            else if (Alunos[i].imc < 17.0){
                printf("Aluna: %s\n IMC: %.2f: Abaixo do peso\n", Alunos[i].nome, Alunos[i].imc);
            }
            else{
                printf("Aluna: %s\n IMC: %.2f: Peso normal", Alunos[i].nome, Alunos[i].imc);
            }            
        }
    }  
}
