#include "ControleDeVoo.h"

typedef struct No
{
	int id;
	dados dado;
	struct No* dir;
	struct No* esq;
} no;

no* Inicializa();
no* CriaNo(char info);
void Imprime(no* raiz, int tab);
no* Busca(no* no, int id);
