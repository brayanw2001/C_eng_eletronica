#include <iostream>

typedef struct Produto
{
	int produtoId;
	char nome[15];
	float preco;
	int estoque;
} Produto;

// fun lerPedido
Produto cadastraProduto();
void mostraProduto(Produto p);

// fun AtualizaEstoque

int main()
{
	Produto produtos[5];

	for (int i = 0; i < 5; i++)
	{
		produtos[i] = cadastraProduto();

		mostraProduto(produtos[i]);

	}
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

void mostraProduto(Produto p)
{
	printf("\nProdutoId: %d", p.produtoId);
	printf("\nNome: %s", p.nome);
	printf("Preco: %.2f", p.preco);
	printf("\nEstoque: %d", p.estoque);
	printf("\n\n");
}