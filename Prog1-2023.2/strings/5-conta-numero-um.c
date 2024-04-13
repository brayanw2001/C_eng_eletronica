#include <stdio.h>
#include <math.h>
#include <locale.h>

void contaBin (char *, int *);

int main (){
    setlocale(LC_ALL, "");
    char bin[20];
    int j = 0;

    printf("Insira um binário, iremos contar a quatidade de 1: ");
    fgets (bin, 20, stdin);

    contaBin (bin, &j);

    printf ("A quantidade de '1' é: %d", j);

return 0;
}
void contaBin (char *bin, int *j){
    int i = 0;

    while (bin[i] != '\0')
    {
        if (bin[i] == '1'){
            *j = *j+1;
        }
        i++;
    }
}