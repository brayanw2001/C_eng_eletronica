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
void MostraLista(no* topo);
no* BuscaContato(no* topo);
void AtualizaContato(no* topo);
no* RemoveContato(no* topo);
void RemoveDuplicado(no* topo);