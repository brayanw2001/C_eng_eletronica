#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main (){

    setlocale(LC_ALL, "");

    int *alloc = calloc (5, sizeof(int));

    printf("[Insira 5 números]\n\n");

    for (int i = 0; i < 5; i++){
        printf("Insira o número %d: ", i+1);
        scanf ("%d", &alloc[i]); 
    }

    for (int j = 0; j < 5; j++){
        printf("[%d]: %d \n", j, alloc[j]);
    }

    free (alloc);
    
return 0;
}