#include <stdio.h>
#include <math.h>
#include <locale.h>

typedef struct {
    float x;
    float y;
}Ponto2D;

typedef struct {
    int R;
    int G;
    int B;
} CorRGB;

typedef struct {
    Ponto2D vA;
    Ponto2D vB;
    Ponto2D vC;
    Ponto2D vD;  
    CorRGB cor;
} Quadrilatero;

void preencheInfos (Quadrilatero *qua);

void calc_area (Quadrilatero *qua);

int main (){

    setlocale(LC_ALL, "");

    Quadrilatero qua;

    preencheInfos (&qua);
    calc_area (&qua);

return 0;
}

void preencheInfos (Quadrilatero *qua){
    printf ("Insira x de vA: ");
    scanf ("%f", &(*qua).vA.x);
    printf ("Insira y de vA: ");
    scanf ("%f", &(*qua).vA.y);

    printf ("Insira x de vB: ");
    scanf ("%f", &(*qua).vB.x);
    printf ("Insira y de vB: ");
    scanf ("%f", &(*qua).vB.y);

    printf ("Insira x de vC: ");
    scanf ("%f", &(*qua).vC.x);
    printf ("Insira y de vC: ");
    scanf ("%f", &(*qua).vC.y);

    printf ("Insira x de vD: ");
    scanf ("%f", &(*qua).vC.x);
    printf ("Insira y de vD: ");
    scanf ("%f", &(*qua).vD.y);

    printf ("Agora, insira a cor em RGB\n");
    printf ("Insira R: ");
    scanf ("%d", &(*qua).cor.R);
    printf ("Insira G: ");
    scanf ("%d", &(*qua).cor.G);
    printf ("Insira B: ");
    scanf ("%d", &(*qua).cor.B);
}

void calc_area (Quadrilatero *qua) {
    printf ("[TESTE] Valor de vA: %.2f %.2f", qua->vA.x, qua->vA.y);
}