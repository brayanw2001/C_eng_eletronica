#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int main()
{
    char opc = '7';
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
        );

        switch (opc)
        {
            case '1':
                printf("Nome: ");
                fgets(contato.nome, sizeof(contato.nome), stdin);
                
                printf("Numero: ");
                scanf("%hu", contato.telefone);
                InsereNoTopo(topo, contato);
                break;
        default:
            break;
        }
    }


    return 0;
}

