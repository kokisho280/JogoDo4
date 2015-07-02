#include"JogoMenu.h"
#include "output.h"
#include <stdio.h>


int main()
{
	char res;
	int z;
	player lista = NULL;		// Ponteiro de lista
	lista=recupera(lista);		// recupera a lista dos jogadores do momento em que encerrou o jogo
	
	do{

		do{
			z = menu();  
			switch(z){
			case 1:lista=novoJogo(lista);break;
			case 2:lista=carregarjogo(lista);break;
			case 3:lista=jogadores(lista);break;
			case 4:instrucoes();break;
			case 5:top1(lista);break;
			}
		}while(z!=6);

		do{
			titulo();
			imgJogo();
			printf("\t     Tem a certeza que pretende sair?\n\n\t\t  sim[s]\tnao[n] \n\t\t\t   ");

			res = getchar();
		

			if(res == 's')
			{
				titulo();
				printf("\n\n\n\n\n\t\t\t    Made by:\n\n\t Rodolfo Lima 21170826 & Ricardo Dinis 21170949\n\n\n\n\n\t\tIsec 2010\\2011 Cadeira:Programacao\n\n\n");
				grava_ficheiro(lista);		// grava a lista dos jogadores antes de encerrar o jogo
				getchar();
				return 0;
			}
		}while(res != 's' && res != 'n');

	}while(res != 's');

}