#include <stdio.h>
#include <locale.h>

void media (float notas[], char, float*, float*, float*);

int main (){

    setlocale(LC_ALL, "");
    float notas[3], resA, resP, resH;
    char tipo;
    while (1)
    {
        for (int i = 0; i < 3; i++){
        printf("\nInsira a nota %d: ", i+1);
        scanf("%float", &notas[i]);
        }

        printf("\nInsira 'A' para média aritimética, insira 'P', para a média ponderada, ou insira 'H' para a média harmônica: ");
        while (getchar() != '\n');
        scanf("%c", &tipo);

        media (notas, tipo, &resA, &resH, &resP);
        printf ("A média aritimética: %.2f\nA média ponderada: %.2f\nA média harmônica: %.2f kkkkkkkkk sei oq é harmonica não", resA, resH, resP);
    }  

return 0;
}

void media (float notas[], char opc, float *ResA, float *ResP, float *ResH){
    int i;
    float soma = 0;

    if (opc == 'A' || opc == 'a'){
        for (i = 0; i < 3; i++){
        soma = soma + notas[i];
        }
        *ResA = soma/i;
    }

    else if (opc == 'P' || opc == 'p'){
        *ResP = ((notas[0]*5.0) + (notas[1]*3.0) + (notas[2]*2.0))/10.0;
    }

    else if (opc == 'H' || opc == 'h'){
        *ResH = 871289.4;
    }
    else {
        printf("Opção inválida. Por favor, digite novamente a opção desejada: ");
    }
}