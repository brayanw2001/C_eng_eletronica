typedef struct No
{
	int id;
	char info;
	struct No* dir;
	struct No* esq;
} no;

no* Inicializa();
no* CriaNo(char info);
int geraId();
void Imprime(no* raiz, int tab);
no* Busca(no* no, int id);
