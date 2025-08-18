#include <iostream>

#define NUM  5

typedef struct Produto
{
	int produtoId;
	char nome[15];
	float preco;
	int estoque;
} Produto;

Produto cadastraProduto();
void mostraProduto(Produto *p);
Produto solicitaProduto();

// fun AtualizaEstoque

int main()
{
	Produto produtos[5];

	for (int i = 0; i < NUM; i++)
	{
		produtos[i] = cadastraProduto();
		printf("\n");

	}
		mostraProduto(produtos);
}

Produto cadastraProduto()
{
	Produto p;
	
	printf("Insira o Id do produto: ");
	scanf_s("%d", &p.produtoId);
	while (getchar() != '\n');

	printf("Insira o nome do produto: ");
	fgets(p.nome, sizeof(p.nome), stdin);

	printf("Insira o preco do produto: ");
	scanf_s("%f", &p.preco);
	while (getchar() != '\n');

	printf("Insira a quantidade em estoque: ");
	scanf_s("%d", &p.estoque);
	while (getchar() != '\n');

	return p;
}

void mostraProduto(Produto *p)
{
	for (int i = 0; i < NUM; i++)
	{
		printf("\nProdutoId: %d", p[i].produtoId);
		printf("\nNome: %s", p[i].nome);
		printf("Preco: %.2f", p[i].preco);
		printf("\nEstoque: %d", p[i].estoque);
		printf("\n\n");
	}
}

Produto solicitaProduto()
{
	Produto produtoSolicitado;

	printf("Insira o id do produto solicitado: ");
	scanf_s("%d", &produtoSolicitado.produtoId);

	printf("Insira a quantidade desejada: ");
	scanf_s("%d", &produtoSolicitado.estoque);
}