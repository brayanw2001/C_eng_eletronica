#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Grafos.h"

int main()
{
	Grafo* grafo;
	inicializa(&grafo); // grafo

	//grafo->prox = inicializa();
	//grafo->idVertice = 1;
	//grafo->primeiroVizinho = NULL;

	grafo = preencheVertices(grafo);
	imprimeGrafo(grafo);

	return 0;
}