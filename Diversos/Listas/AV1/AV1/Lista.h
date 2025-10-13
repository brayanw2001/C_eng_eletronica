typedef struct Pessoa
{
	char nome[40];
	char email[40];
	char telefone[15];
} pessoa;

typedef struct No
{
	pessoa contato;
	struct No* proximo;
} no;

no* InsereNoTopo(no* topo, pessoa contato);
no* InsereNoFim(no* topo, pessoa contato);
no* BuscaContato(no* topo);
no* AtualizaContato(no* topo);
no* RemoveContato(no* topo);
void MostraLista(no* topo);