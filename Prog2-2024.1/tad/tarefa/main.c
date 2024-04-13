#include "implement.c"
#include "spec.h"

int main() {
  setlocale(LC_CTYPE, "");

    jogadores *retorno_pt_jogador = criajogador();
    apresentaJogadores(retorno_pt_jogador);

   return 0;
}
