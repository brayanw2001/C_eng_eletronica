#include "ControleDeVoo.h"

typedef struct No
{
	dados dado;
	struct No* dir;
	struct No* esq;
} no;

no* CriaNo(dados info);
void LiberaArvore(no* n);
no* CriaNo(dados* info);
void Imprime(no* raiz, int tab);
no* Busca(no* no, int id);
no* InsereNos(dados* info, int numTarefas);
