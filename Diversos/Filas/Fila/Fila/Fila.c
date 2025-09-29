#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Fila.h"

struct No
{
	int value;
	no* proximo;
	int size;
};

struct Fila
{
	fila* inicio;
	fila* fim;
	int tamanho;
};

