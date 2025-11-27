// ControleDeVoo.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "ControleDeVoo.h"

dados* novaTarefa(int numTarefas)
{
	dados* tarefas = (dados*) malloc (sizeof(dados) * numTarefas);

	int* prioridades = geraPrioridades(numTarefas);

	for (int i = 0; i < numTarefas; i++)
	{
		printf("Insira a tarefa: ");
		fgets(tarefas[i].tarefa, 30, stdin);
		tarefas[i].tarefa[strcspn(tarefas[i].tarefa, "\n")] = '\0';

		tarefas[i].prior = prioridades[i];		
	}

	free(prioridades);

	return tarefas;
}


int* geraPrioridades(int numTarefas)
{
	int* prioridades = (int*)malloc(sizeof(int) * numTarefas);

	for (int i = 0; i < numTarefas; i++)
	{
		prioridades[i] = rand() % ((4 *numTarefas) + 1);

		for (int j = 0; j < i; j++)
		{
			if (prioridades[i] == prioridades[j])
			{
				prioridades[i] = rand() % ((4 * numTarefas) + 1);
				j = -1;
			}
		}
	}

	return prioridades;
}

