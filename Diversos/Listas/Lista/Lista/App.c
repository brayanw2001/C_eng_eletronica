#include <stdio.h>
#include <stdlib.h>

#include "Lista.h"

int main()
{
	no* topo = NULL;

	topo = InsereNoTopo(topo, 10);
	topo = InsereNoTopo(topo, 11);
	topo = InsereNoTopo(topo, 12);
	MostraLista(topo);
	printf("\n");
	topo = InsereNoFim(topo, 20);
	topo = InsereNoFim(topo, 21);
	topo = InsereNoFim(topo, 22);
	MostraLista(topo);

	return 0;
}