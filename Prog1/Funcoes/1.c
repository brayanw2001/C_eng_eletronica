#include <stdio.h>
#include <math.h>
#include <locale.h>

void VolumeCirc (float);
float VolumeCirc2 (float);
void VolumeCirc3 (float*);

int main (){
    setlocale(LC_ALL, "");
    
    float raio, v2, raio2;

    printf("Informe o raio da esfera: ");
    scanf("%f", &raio);

    //para a função 1
    VolumeCirc(raio);

    //para a função 2
    v2 = VolumeCirc2(raio);
    printf("\nO volume na função 2 é: %.2f", v2);

    raio2 = raio;
    VolumeCirc3(&raio2);
    printf("\nO volume na função 3 é: %.2f", raio2);

return 0;
}

void VolumeCirc (float r){
    float v = (4*r*r*r*3.1415)/3.0;
    printf("O volume é: %.2f", v);
}

float VolumeCirc2 (float r){
    float v2 = (4*r*r*r*3.1415)/3.0;
    return v2;
}

void VolumeCirc3 (float *ptr_raio2){
    float r = *ptr_raio2;
    *ptr_raio2 = (4*r*r*r*3.1415)/3.0;
}