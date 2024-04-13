#ifndef IMPLEMENT_C
#define IMPLEMENT_C

#include "spec.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogador {
  char nome[20];
  unsigned short int jogos;
  unsigned short int gols;
  unsigned short int assists;
};


jogadores *criajogador() {
  jogadores *pt_jogador;
  int n;

  printf("Bem vindo ao FutDATA\n\n");
  printf("Insira a quantidade de jogadores que deseja adicionar à database: ");
  scanf("%d", &n);

  pt_jogador = calloc((n), sizeof(jogadores));

  for (int i = 0; i < n; i++) {
    printf("[Jogador %i] nome: ", i + 1);
    scanf("%s", pt_jogador[i].nome);
    printf("[Gols de %s]: ", pt_jogador[i].nome);
    scanf("%hu", &pt_jogador[i].gols);
    printf("[Assistências de %s]: ", pt_jogador[i].nome);
    scanf("%hu", &pt_jogador[i].assists);
    printf("\n");
  }
  return pt_jogador;
}

void apresentaJogadores (jogadores *pt_jogador){

  for (int i = 0; i < 3; i++){
    printf ("Nome: %s\nGols: %hu\nAssistências: %hu ", pt_jogador[i].nome, pt_jogador[i].gols, pt_jogador[i].assists);
  };
}

#endif