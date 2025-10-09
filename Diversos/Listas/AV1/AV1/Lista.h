typedef struct Pessoa
{
	char nome[40];
	char email[40];
	unsigned short int telefone[15];
} pessoa;

typedef struct No no;

no* InsereNoTopo(no* topo, pessoa contato);
no* InsereNoFim(no* topo, pessoa contato);
void MostraLista(no* topo);