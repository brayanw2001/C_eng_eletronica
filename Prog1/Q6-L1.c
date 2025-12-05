#include <stdio.h>
#include <math.h>
#include <locale.h>

void preencheParcela (float *, int *);
void valor_pago (float *, int *);

int main (){

    float parcela;
    int dias;
    setlocale(LC_ALL, "");

    preencheParcela (&parcela, &dias);
    printf("VALOR: %f\n\n", parcela);
    valor_pago (&parcela, &dias);

return 0;
}

void preencheParcela (float *parcela, int *dias){
    
    printf("Insira o valor da parcela: ");
    scanf("%f", parcela);
    getchar();
    printf("Insira os dias em atraso: ");
    scanf("%d", dias);
}

void valor_pago (float *parcela, int *dias){

    if (*dias == 0){
        printf("Valor da fatura: %f", *parcela);
    }
    else {
        *parcela = (*parcela + (*parcela*0.03) + (*dias*0.01));
        printf("Valor da fatura: %.2f", *parcela);
    }
}