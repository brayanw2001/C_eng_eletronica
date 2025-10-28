#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Grafos.h"

void inicializa(Grafo** g)
{
	(*g)->idVertice = 0;
}

//Grafo* preencheVertices(Grafo* g)
//{
//
//	//for (int i = 2; i < 6; i++)
//	//{
//	//	Grafo* novoVertice = (Grafo*) calloc(1, sizeof(Grafo));
//	//	g = novoVertice;
//	//	novoVertice->prox = NULL;
//	//	novoVertice->idVertice = i;
//	//	novoVertice->primeiroVizinho = NULL;
//	//}
//
//	int i = 1;
//
//	while (g->prox != NULL)
//	{
//		Grafo* novoVertice = (Grafo*)calloc(1, sizeof(Grafo));
//		novoVertice->prox = NULL;
//		novoVertice->primeiroVizinho = NULL;
//		novoVertice->idVertice = i;
//		
//		g = novoVertice;
//
//		i++;
//	}
//	
//	return g;
//}

void imprimeGrafo(Grafo* g) 
{
	while (g != NULL) 
	{
		printf("Vértice %d\n", g->idVertice);
		printf("Vizinhos: ");
		Vizinho* v = g->primeiroVizinho;

		while (v != NULL) 
		{
			printf("%d ", v->idVizinho);
		}

		v = v->prox;

		printf("\n\n");
	}
}

void libera(Grafo* g) 
{
	while (g != NULL) 
	{
		liberaVizinhos(g->primeiroVizinho);
		Grafo* temp = g;
		g = g->prox;
		free(temp);
	}
}

void liberaVizinhos(Vizinho* v) 
{
	while (v != NULL) 
	{
		Vizinho* temp = v;
		v = v->prox;
		free(temp);
	}
}

int numeroDeArestas(Grafo* g)
{
	int numeroDeArestas = 0;

	while (g != NULL)
	{
		while (g->primeiroVizinho != NULL)
		{
			numeroDeArestas++;

			g = g->primeiroVizinho;
		}
		g = g->prox;
	}

	return numeroDeArestas;
}

int numeroDeVertices(Grafo* g)
{
	int numeroDeVertices = 0;

	while (g->prox != NULL)
	{
		numeroDeVertices++;

		g = g->prox;
	}
}

bool testek(Grafo* g, int k)
{
	if (numeroDeVertices == k)
		return true;

	return false;
}

bool GrafosIguais(Grafo* g1, Grafo* g2)
{
	if ( (numeroDeVertices(g1) != numeroDeVertices(2)) && (numeroDeArestas(g1) != numeroDeArestas(g2)) )
		return false;
	else
		while (g1 != NULL && g2 != NULL)
		{
			if (g1->idVertice != g2->idVertice)
				return false;

			while (g1->primeiroVizinho != NULL && g2->primeiroVizinho != NULL)
			{
				if (g1->primeiroVizinho->idVizinho != g2->primeiroVizinho->idVizinho)
					return false;

				g1 = g1->primeiroVizinho;
				g2 = g2->primeiroVizinho;
			}
			g1 = g1->prox;
			g2 = g2->prox;
		}

	return true;
}