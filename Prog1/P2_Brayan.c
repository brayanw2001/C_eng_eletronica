/*ALUNO: Brayan W. da Silveira
* Prova 2. 11/12/2023. PRG22003
*/
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    char nome [20];
    char genero [15];
    char duracao [6];
    int posicao;
} coletanea;

void preencheColetanea (coletanea *musicas, int *);
void encontraGenero (coletanea *musicas, int*);
void encontraMusica (coletanea *musicas, int*);

int main (){

    setlocale(LC_ALL, "");
    coletanea musicas [5];
    int n = 0;
    char menu = '1';

    while (menu == '1'){
        printf("O que gostaria de fazer?\n");
        printf("[1] Preencher a coletânea\n[2] Filtrar por genênero\n[3] Encontrar uma música pelo seu nome\n[4] Fechar o programa\n\nInsira o número da opção desejada: ");
        switch (getchar()) {
        case '1':
            preencheColetanea(musicas, &n);
            break;
        
        case '2':
            encontraGenero (musicas, &n);;
            break;

        case '3':
            encontraMusica (musicas, &n);;
            break;
        case '4':
            return 0;
        }
    }

return 0;
}

void preencheColetanea (coletanea *musicas, int *n) {
    int  i;
    getchar();                  //limpa o buffer deixado pelo menu
    *n = *n+1;

    for (i = *n; i <= 5; i++){
        int verificador = 1;

        printf("\n\t[Música %d] \n", i);
        printf("Insira o nome da música: ");
        fgets(musicas[i].nome, 20, stdin);

        printf("Insira o gênero: ");
        fgets(musicas[i].genero, 15, stdin);

        printf("Insira a duração (no formato 00:00): ");
        fgets(musicas[i].duracao, 6, stdin);

        while (verificador == 1)
        {
            printf("Insira a posição na playlist: ");
            scanf("%d", &musicas[i].posicao);

            if (musicas[i].posicao < 1 || musicas[i].posicao > 5){
                printf("Entrada inválida! Tente novamente.\n");
                getchar();
            } 
            else {
                verificador = 0;
            }
        }
        printf("\n");                                                    //quebra linha para a proxima passagem do laço
        getchar();                                                       //limpa o buffer do teclado deixado pela ultima entrada
        *n = i;                                                          //numero de bandas preenchidas
    
        printf ("Deseja retornar ao menu [1]? Ou prefere continuar preenchendo [2]?\nInsira a opção: ");
        if (getchar() == '1') {
            getchar();
            printf("\n------------------------------------\n\n");
            return;
        } else {
            getchar();
        }
    }
}

void encontraGenero (coletanea *musicas, int *n) {
//    #include <string.h>
//    #include <unistd.h>
    getchar();                  //limpa o buffer deixado pelo menu 

    char compara_genero [15];
    int i = 0, pesquisa, soma;

    printf("Insira o gênero pelo qual deseja filtrar sua pesquisa: ");
    fgets(compara_genero, 15, stdin);

    for (i = 0; i <= *n; i++){
        pesquisa = strcmp(musicas[i].genero, compara_genero);
        if (pesquisa == 0){ 
            printf("\nEncontramos!\nNome: %sDuração: %sPosição: %i\n\n", musicas[i].nome, musicas[i].duracao, musicas[i].posicao);
            sleep (1.0);
            soma = 0;
        }
    }

    if (soma != 0) {
        printf("Parece que não há músicas com esse gênero :(\n\n");
        sleep (1.5);
    }

}

void encontraMusica (coletanea *musicas, int *n) {
//    #include <string.h>
//    #include <unistd.h>
    getchar();                  //limpa o buffer deixado pelo menu 

    char compara_musica [15];
    int i = 0, pesquisa, soma;

    printf("Insira o gênero pelo qual deseja filtrar sua pesquisa: ");
    fgets(compara_musica, 15, stdin);

    for (i = 0; i <= *n; i++){
        pesquisa = strcmp(musicas[i].nome, compara_musica);
        if (pesquisa == 0){ 
            printf("\nEncontramos!\nNome: %sGênero: %sDuração: %sPosição: %i\n\n", musicas[i].nome, musicas[i].genero, musicas[i].duracao, musicas[i].posicao);
            sleep (1.0);
            soma = 0;
        }
    }

    if (soma != 0) {
        printf("Não encontramos resultados para sua pequisa :(\n\n");
        sleep (1.5);
    }

}