#include <iostream>

#define NUM  2

typedef struct Produto
{
	int produtoId;
	char nome[15];
	float preco;
	int estoque;
} Produto;

Produto cadastraProduto();
void mostraProduto(Produto *p);
void solicitaProduto(Produto *p);

int main()
{
	Produto produtos[5];

	// Falta adicionar um menu

	for (int i = 0; i < NUM; i++)
	{
		produtos[i] = cadastraProduto();
		printf("\n");
	}
		mostraProduto(produtos);
		printf("\n=== Solicite seu produto ===\n");
		solicitaProduto(produtos);
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

void solicitaProduto(Produto *p)
{
	Produto produtoSolicitado;

	printf("Insira o id do produto solicitado: ");
	scanf_s("%d", &produtoSolicitado.produtoId);

	printf("Insira a quantidade desejada: ");
	scanf_s("%d", &produtoSolicitado.estoque);

	for (int i = 0; i < NUM; i++)
	{
		if (p[i].produtoId == produtoSolicitado.produtoId)
		{
			if (p[i].estoque > 0 && (p[i].estoque >= produtoSolicitado.estoque))
			{
				p[i].estoque -= produtoSolicitado.estoque;
				printf("Estoque de %s: %d", p[i].nome, p[i].estoque);
			}
			else
			{
				printf("Nao ha estoque o suficiente");
				scanf_s("%d");	// apenas para visualizar o resultado final, antes do fechamento do programa
			}
		}
	}
}