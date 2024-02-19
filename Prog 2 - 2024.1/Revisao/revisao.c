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
} Quadrilatero;

float preencheInfos (Ponto2D *vA, Ponto2D *vB, Ponto2D *vC, Ponto2D *vD, CorRGB *cor);

float calc_area (Quadrilatero *qua);

int main (){

    setlocale(LC_ALL, "");

    Quadrilatero qua;
    Ponto2D vA;
    Ponto2D vB;
    Ponto2D vC;
    Ponto2D vD;
    CorRGB cor;

    preencheInfos (&vA, &vB, &vC, &vD, &cor);
    calc_area (&qua);

return 0;
}

float preencheInfos (Ponto2D *vA, Ponto2D *vB, Ponto2D *vC, Ponto2D *vD, CorRGB *cor){
    printf ("Insira x de vA: ");
    scanf ("%f", &(*vA).x);
    printf ("Insira y de vA: ");
    scanf ("%f", &(*vA).y);

    printf ("Insira x de vB: ");
    scanf ("%f", &(*vB).x);
    printf ("Insira y de vB: ");
    scanf ("%f", &(*vB).y);

    printf ("Insira x de vC: ");
    scanf ("%f", &(*vC).x);
    printf ("Insira y de vC: ");
    scanf ("%f", &(*vC).y);

    printf ("Insira x de vD: ");
    scanf ("%f", &(*vD).x);
    printf ("Insira y de vD: ");
    scanf ("%f", &(*vD).y);

    printf ("Agora, insira a cor em RGB");
    printf ("Insira R: ");
    scanf ("%d", &(*cor).R);
    printf ("Insira G: ");
    scanf ("%d", &(*cor).G);
    printf ("Insira B: ");
    scanf ("%d", &(*cor).B);
}

float calc_area (Quadrilatero *qua) {
    printf ("[TESTE] Valor de vA: %f %f", qua->vA.x, qua->vA.y);
}