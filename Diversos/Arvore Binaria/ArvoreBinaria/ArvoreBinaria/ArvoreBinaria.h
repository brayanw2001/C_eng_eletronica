typedef struct No
{
	char info;
	struct No* dir;
	struct No* esq;
} no;

no* Inicializa();
no* CriaNo(char info);
void Imprime(no* raiz, int tab);
