#include <stdio.h>
#include <stdlib.h>

#include "ArvoreBinaria.h"

int main()
{
	no* raiz;
	
	raiz = CriaNo('A');
	raiz->esq = CriaNo('B');
	raiz->dir = CriaNo('C');
	raiz->dir->esq = CriaNo('D');
	raiz->dir->dir = CriaNo('E');

	Imprime(raiz, 0);

	return 0;
}