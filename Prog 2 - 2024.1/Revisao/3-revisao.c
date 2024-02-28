#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int hora, minuto;
  float tcelsius, pammhg;
  char local[30];
} meteoro;

void comparaDados(meteoro *dados);

int main(void) {

  FILE *fp;
  char filename[50];
  meteoro dados[5];

  printf("Insira o nome do arquivo: ");
  fgets(filename, 50, stdin);

  fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Impossível abrir o arquivo %s\n", filename);
    exit(0);
  }

  for (int i = 0; i < 5; i++) {
    fscanf(fp, "%d %d %f %f %s", &dados[i].hora, &dados[i].minuto,
           &dados[i].tcelsius, &dados[i].pammhg, dados[i].local);
  }

  // printf("\nContents copied: %d %d %.2f %.2f %s", dados[0].hora,
  //        dados[0].minuto, dados[0].tcelsius, dados[0].pammhg,
  //        dados[0].local);

  fclose(fp);

  comparaDados(dados);

  return 0;
}

void comparaDados(meteoro *dados) {
  int temp;

  for (int j = 0; j < 5; j++) {
    printf("\n[%d] ", j);
    for (int k = 0; k < 5; j++) {
      printf("%d, ", k);

      if (dados[k].pammhg > dados[j + 1].pammhg) {

        temp = dados[k].pammhg;
        dados[k].pammhg = dados[k + 1].pammhg;
        dados[j + 1].pammhg = temp;
      }
    }
  }
  printf("TESTE: %d", dados[0].hora);
}

// http://devfuria.com.br/logica-de-programacao/exemplos-na-linguagem-c-do-algoritmo-bubble-sort/