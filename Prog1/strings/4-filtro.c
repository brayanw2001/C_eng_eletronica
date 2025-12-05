#include <stdio.h>
#include <locale.h>
#include <string.h>

void preencheString (char *, char *, int *);
void verificaString (char *, int *);

int main (){
    char nome [50], sexo [4];
    int idade;
    
    setlocale (LC_ALL, "");
    preencheString (nome, sexo, &idade);
    verificaString (sexo, &idade);

return 0;
}

void preencheString (char *nome, char *sexo, int *idade) {
    printf ("Nome: ");
    fgets (nome, 50, stdin);
    printf ("Sexo: ");
    fgets (sexo, 4, stdin);
    printf ("Idade: ");
    scanf("%d", idade);
}

void verificaString (char *sexo, int *idade){
    int sexResult;

    sexResult = strcmp (sexo, "fem");

    if (sexResult == 0 && *idade < 25){
        printf ("Aceita!");
    }
    else {
        printf ("Não aceita!");
    }
}