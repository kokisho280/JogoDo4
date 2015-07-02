#ifndef JOGOMENU_H
#define JOGOMENU_H
#define _CRT_SECURE_NO_WARNINGS
#include "gestaoTab.h"



int tras();
player jogo(int nJogadores, jogador **j, int mc, int linhas, int colunas, int jcria, char *tabela, int njog, int ord, int njogadas, player lista, int undo, int *posicoes, int njact);
void tamtab( int *l, int *c);
player carregarjogo(player lista);
player jogadores(player lista);
player login(player p);
player inserir_player(player p);
void mostrar_lista(player p);
player eliminar_player(player p);
void recoverPW(player p);
int conta_jogador(player aux);
void top(player p);
player ranking(player p, char *nome, int x);
player recupera(player p);
player novoJogo(player lista);
void instrucoes();
void grava_ficheiro(player p);
int menu();
void top1(player lista);

#endif
