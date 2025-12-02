#include "ControleDeVoo.h"

typedef struct No
{
	dados dado;
	struct No* dir;
	struct No* esq;
} no;

no* Inicializa();
no* CriaNo(dados* info);
void Imprime(no* raiz, int tab);
no* Busca(no* no, int id);
no* InsereNos(dados* info, int numTarefas);
