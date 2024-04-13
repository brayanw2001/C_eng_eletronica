#include <stdio.h>
#include <locale.h>

void preencheString (char *, char *);
int comparaString (char *, char *);

int main (){
    char str1 [50], str2 [50];
    int comp;

    setlocale(LC_ALL, "");
    preencheString (str1, str2);

    if ((comp = comparaString (str1, str2)) == 1){
        printf("Diferentes!");
    }
    else {
        printf("Iguais!");
    }

return 0;
}

void preencheString (char *str1, char *str2){
    printf("Insira a primeira string: ");
    fgets(str1, 50, stdin);
    printf("Insira a segunda string: ");
    fgets(str2, 50, stdin);
}

int comparaString (char *str1, char *str2){
    int i = 0;

    while (str1[i] != '\0'){
        if (str1[i] != str2[i]){
            return 1;
        }
        i++;
    }
    return 0;
}