#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

void menu();

int main()
{
    char opc = '0';
    no* topo = NULL;
    pessoa contato;

    while (opc != '7')
    {
        printf("[1] - Inserir contato\n"
            "[2] - Listar Contatos\n"
            "[3] - Buscar Contato\n"
            "[4] - Editar Contato\n"
            "[5] - Remove Contato\n"
            "[6] - Remove Contato duplicado\n"
            "[7] - Sair\n"
            "Insira uma opcao: > "
        );
        scanf("%c", &opc);
        getchar();

        switch (opc)
        {
            case '1':
                printf("\nNome: ");
                fgets(contato.nome, sizeof(contato.nome), stdin);
                contato.nome[strlen(contato.nome) - 1] = '\0';
                
                printf("Numero: ");
                fgets(contato.telefone, sizeof(contato.telefone), stdin);
                contato.telefone[strlen(contato.telefone) - 1] = '\0';

                printf("email: ");
                fgets(contato.email, sizeof(contato.email), stdin);
                contato.email[strlen(contato.email) - 1] = '\0';

                topo = InsereNoTopo(topo, contato);
                printf("\n");
                break;

            case '2':
                MostraLista(topo);
        default:
            break;
        }
    }


    return 0;
}

