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
        printf("[1] Criar Vetor\n"
               "[2] Incrementar tarefas\n"
               "[3] ...");

        printf("Insira a opcao: ");
        scanf("%d", &opc);

        while (getchar() != '\n');

        switch (opc) 
        {
            case 1:
                printf("\nQuantas tarefas? ");
                scanf("%d", &numTarefas);

                while (getchar() != '\n'); 

                printf("\n");
                tarefas = novaTarefa(numTarefas);

                break;

            case 2:
                tarefas = incrementarTarefas(tarefas, &numTarefas);
                printf("\n\n");
                break;
            // ... outros cases
            case 9:
                printf("\n===== TAREFAS =====");
                for (int i = 0; i < numTarefas; i++)
                {
                    printf("\nDescricao: %s", tarefas[i].tarefa);
                    printf("\nPrioridade: %d", tarefas[i].prior);
                    printf("\n");
                }
                printf("==================\n\n");

                break;
        }
    } while (opc != 8);

    // não esquecer de limpar memoria
}