#include <stdio.h>
#include <stdlib.h>

void titulo() //O titulo do jogo
{
	system("cls");
	printf("\n\t\t   %c-%c-+-+-+-+   +-+-+", 79, 79);
	printf("\n\t\t   | |J o g o|   |d o|");
	printf("\n\t\t   %c-%c-+-+-+-+-+-+-+-+-%c-%c", 79, 79, 79, 79);
	printf("\n\t\t       |Q u a d r a d o| |");
	printf("\n\t\t       +-+-+-+-+-+-+-+-%c-%c", 79, 79);
}


void imgJogo()  //O titulo e uma imagem de um tabuleiro do jogo do quadrado
{
		
		printf("\n\n\t\t     +-+-+-+-%c-+\n\t\t     | | | | | |\n\t\t     +-%c-+-+-+-+\n\t\t     | | | | | |\n\t\t     +-+-%c-+-%c-+\n\t\t     | | | | | |\n\t\t     +-%c-+-+-+-%c\n\n", 79, 79, 79, 79, 79, 79);

}



void escreve_instrucoes() //Instrucoes/guias de como jogar o jogo
{
	titulo();
	
	printf("\n");
	
	printf("\n\n\tMenu principal\n\t  >>Instrucoes");
	printf("\n\n\t\tO jogo do quadrado, na sua variante mais simples, e\n\tum jogo para duas pessoas que decorre num tabuleiro com um\n\tdeterminado numero de linhas e colunas.\n\n");
	printf("\t\tEste numero de linhas e colunas e determinado pelos\n\tjogadores no inicio de um novo jogo.\n\n");
	printf("\t\tO jogo inicia-se num tabuleiro vazio e os jogadores\n\talternadamente inserem coordenadas, para escolher em que \n\tposicao do tabuleiro desejam jogar\n");
	printf("\n\t1/2");
	puts("\n\t");
	getchar();

	titulo();
	
	
	
	printf("\n\n\tMenu principal\n\t  >>Instrucoes");
	printf("\n\n\t\tO objectivo do jogo e 'obrigar' os adversarios a formar\n\t um quadrado quando isso acontece esse jogador e eliminado, o\n\t tabuleiro aumenta, respectivamente uma linha e uma coluna e os\n\t restantes jogadores continuam com o jogo ate ficar so um que\n\t vai ser o vencedor.\n\n");
	printf("\t\t\t\t+-0-+-0-+\n\t\t\t\t| | | | |\n\t\t\t\t+-O-+-+-+\n\t\t\t\t| | | | |\n\t\t\t\tO-0-+-0-+\n");
	
	
	printf("\n\t2/2");
	puts("\n\t");

	getchar();

}
