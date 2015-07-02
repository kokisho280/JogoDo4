#ifndef GESTAOTAB_H
#define GESTAOTAB_H
#define _CRT_SECURE_NO_WARNINGS

#define ST_NICK 50
#define ST_PW 20

typedef struct pessoa no, *player; 
// Estrutura para armazenar informacao sobre um jogador
struct pessoa{
	char nome[ST_NICK]; // Nome do jogador
	char nick[ST_NICK]; // nick do jogador
	char pw[ST_PW];		// password do jogador
	int victoria;		// numero de victorias
	int derrota;		// numero de derrotas
	int pontuacao;		// pontuaçao do jogador
	player prox; // Ponteiro para proximo no da lista 
}; 

//Estrutura para armazenar informacao sobre jogadores que estao a jogar
typedef struct {
		char nickj[ST_PW];					// Nick jogador
         
        int registado;						// registado 0/1
		int undo;							//Undo 0/1
} jogador;



void titulo();
int pos_jog(int *c, int *l, int colunas, int linhas, int mc, int *posicoes, char *tabela, jogador *j, int *njact, int njogadores, int ord);
int sairJ(int mc);
int main();
void orgnomes(char *n,int ord);
player ranking(player p, char *nome, int x);
jogador **Libertarnomes (int nJog, jogador **j);

player jogo(int nJogadores, jogador **j, int mc, int linhas, int colunas, int jcria, char *tabela, int njog, int ord, int njogadas, player lista, int undo, int *posicoes, int njact);

#endif