#include <stdio.h>
#include <math.h>
#include <locale.h>

void preencheString (char *);
void trocaNumeros (char *);

int main (){
    setlocale(LC_ALL, "");
    char bin [20];
    
    preencheString(bin);
    trocaNumeros(bin);

return 0;
}

void preencheString (char *bin) {
    printf ("Insira a sequência binária: ");
    fgets (bin, 20, stdin);
}

void trocaNumeros (char *bin){
    int i = 0;

    while (bin[i] != '\0')
    {
        if (bin [i] == '0'){
            bin [i] = '1';
        }
        i++;
    }
    printf ("Nova sequência: %s", bin);
}
