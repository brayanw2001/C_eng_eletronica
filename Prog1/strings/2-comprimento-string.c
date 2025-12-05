#include <stdio.h>
#include <locale.h>

void preencheString (char *);
int comprimentoString (char *);

int main (){
    char str1 [50];
    int tam;
    
    setlocale(LC_ALL, "");
    preencheString (str1);
    tam = comprimentoString(str1);
    printf("O tamanho da string é: %d", tam);

return 0;
}

void preencheString (char *str1){
    printf("Insira a string: ");
    fgets(str1, 50, stdin);
}

int comprimentoString (char *str1){
    int i = 0;

    while (str1[i] != '\0'){
        i++;
    }
    return i-1;
}