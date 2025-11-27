#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ControleDeVoo.h"

int main() 
{

    int numTarefas, opc;
    dados* tarefas = NULL;

    do 
    {
        printf("[1] Criar Vetor\n");

        printf("Insira a opcao: ");
        scanf("%d", &opc);

        while (getchar() != '\n');

        switch (opc) 
        {
            case 1:
                printf("Quantas tarefas? ");
                scanf("%d", &numTarefas);
                while (getchar() != '\n'); 

                tarefas = novaTarefa(numTarefas);
                break;
            // ... outros cases
        }
    } while (opc != 8);



    for (int i = 0; i < numTarefas; i++)
    {
        printf("\n\nDescricao: %s", tarefas[i].tarefa);
        printf("\nPrioridade: %d", tarefas[i].prior);
    }
}