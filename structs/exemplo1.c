#include <stdio.h>
#include <math.h>
#include <locale.h>

struct pontos           //1° passo: *declarar* a estrutura
{
    float x;
    float y;
};


int main (){

    setlocale(LC_ALL, "");
    struct pontos a;                   //2° passo: *definir* a estrutura criada
    struct pontos b;
    float distancia;

    printf("Informe a coordenada x de 'a': ");
    scanf("%f", &a.x);    //Qual variavel quero acessar? R: A variável 'a' em conjunto com o componente 'x' da struct, bem como com a componente 'y'
    printf("Informe a coordenada y de 'a': ");
    scanf("%f", &a.y);
    printf("Informe a coordenada x de 'b': ");
    scanf("%f", &b.x);
    printf("Informe a coordenada y de 'b': ");
    scanf("%f", &b.y);

    distancia = hypot (b.x-a.x, b.y-a.y);
    printf("A distância entre os pontos é igual a: %2.f", distancia);

return 0;
}