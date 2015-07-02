#include "output.h"
#include "JogoMenu.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int menu()			//Menu principal do jogo
{
	int i;

		titulo();//output
		imgJogo();//output.c
		puts("\t1) - Novo Jogo\t\t2) - Carregar Jogo\n");
		puts("\t3) - Jogadores\t\t4) - Instrucoes\n");
		puts("\t5) - Top 10\t\t6) - Sair\n");		
		printf("\n\tEscolha uma opcao:"); 
		scanf(" %d", &i); 
		fflush(stdin);

		if(i<1 || i>6)
		{
			do{ 
				titulo();//output.c
				imgJogo();//output.c		
				puts("\t1) - Novo Jogo\t\t2) - Carregar Jogo(UC)\n");
				puts("\t3) - Jogadores(UC)\t4) - Instrucoes(UC)\n");
				puts("\t5) - Top 10(UC)\t\t6) - Sair\n");
				printf("\tOpcao nao existe, por favor escolha umas das opcoes(1 a 6)\n");
				printf("\tEscolha uma opcao:"); 
				scanf(" %d", &i); 
				fflush(stdin);		
		
			}while(i<1 || i>6);
		}

	return i;
}


jogador** Libertarnomes (int nJog, jogador **j)//liberta posicoes dentro do array **j com as estruturas 
{
  int  i;  
  //if (p == NULL) return (NULL);
  
  for (i=0; i<nJog; i++)
	  free (j[i]); 

        
  return (NULL); 
}








player novoJogo(player lista) //opcao novojogo vai pedir aos jogadores as informacoes necessarias para criar um novo jogo, como numero jogadores tamanho tabuleiro se se kerem registar ou nao etc..
{
	int i, nJog, c, mc=0, ret, jcria=1, linhas, colunas, tamanho, njog, ord=0, njogadas=0, x, k=0, njact=0, *posicoes, undo=0;
	char nJogadores, res, con[12]="Convidado", inf, *tabela;
	player aux;
	jogador **j;

	//do{
	
		
		

		c=0;//numero de convidado
		do{
			titulo();
			printf("\t\tMenu Principal[x]\n");
			printf("\n\tMenu principal\n\t  >>Novo Jogo\n\n");
	
	
			printf("\n\tNumero de jogadores:\t\tMinimo 2 - Maximo 6\n\t\t");
			scanf("%c", &nJogadores);
		
			fflush(stdin);
			
			if(nJogadores == 'x')
			{	
				ret=tras();
				
					if(ret==1){

						return lista;
					}

			}

			
					
					
				

		}while(nJogadores<='1' || nJogadores>'6');





		nJog = nJogadores-'0';//como informacao pedida e char 'alterar' para int
		njog = nJog;
		j = malloc(sizeof(jogador)*nJog);//cria array de ponteiro para estruturas

		if(j==NULL)
		{
			printf("erro alocacao array jogador");
		}

		for(i=0;i<nJog;i++)
		{
			j[i]= malloc(sizeof(jogador));//cria ponteiros para estruturas

		}
	
		for(i=0;i<nJog;i++)
		{
			do{
				titulo();
				printf("\t\tMenu Principal[x]\n");
				printf("\n\tMenu principal\n\t  >>Novo Jogo\n\n");
				printf("\n\t\t\t< Novo Jogo >\t%d Jogadores\n\n", nJog);
				printf("\t\t%d Jogador deseja jogar em modo convidado?", i+1);//modo convidado ou nao
				printf("\n\n\t\t\t  sim[s]\tnao[n] \n\t\t\t");
				scanf("%c", &res);
				fflush(stdin);
				if(res == 'x')
				{	
					ret=tras();
					if(ret==1){


						return lista;
					}
				}
			}while(res != 's' && res != 'n');

		
			if(res=='s')//se modo convidado sim fica com o nome convidado e numero de convidado
			{
				con[9]=c+49;		//c numero convidado
				con[10]='\0';
				strcpy(j[i]->nickj,con);
				j[i]->registado=0;
				j[i]->undo=1;

				c++;
				mc=1;
			}else{
				do{
				printf("\t\tEsta registado?");//verifica se ja se encontra registado ou se quer registar
				printf("\n\n\t\t\t  sim[s]\tnao[n] \n\t\t\t");
				scanf("%c", &res);
				fflush(stdin);
				if(res == 'x')
				{	
					ret=tras();
					if(ret==1){


						return lista;
					}
				}

				}while(res != 's' && res != 'n');

				if(res == 's'){

				aux = login(lista);//verifica login 

				if(aux==NULL)//se login n conseguido i-1 para tornar a inserir informacao sobre esse jogador
				{
					i--;
					
				}else{
					for(x=0;x<i;x++){//verifica se jogador ja se encontra a jogar
						if(strcmp(aux->nick,j[x]->nickj)==0){
							printf("\t\tJogador ja logado");
							getchar();
							i--;
							k=1;
							break;

						}				
					
										
					}
					if(k==0){//login efectuado com exito 
						printf("\t\tBem vindo %s", aux->nick);		
						strcpy(j[i]->nickj,aux->nick);
						j[i]->registado=1;
						j[i]->undo=1;
						getchar();
					}
					//k=0;
				}
				}else{// caso se queira registar

					lista=inserir_player(lista);
					i--;




			}
		k=0;
		}
		}

		do{
			titulo();
			printf("\t\tMenu Principal[x]\n");
			printf("\n\tMenu principal\n\t  >>Novo Jogo\n\n");
			printf("\n\t\t< Novo Jogo >\t%d Jogadores\n\n", nJog);
			for(i=0;i<nJog;i++)
			{
				printf("\n\t%d Jogador-%s", i+1, j[i]->nickj);
			}
		puts("\n");

		printf("\t\tContinuar?");//confirma jogadores que vao comecar jogo
		printf("\t\t  sim[s]\tnao[n] \t");
		scanf("%c", &inf);
		fflush(stdin);
		}while(inf != 's' && inf != 'n');
		
	

	
	
	if(inf=='s'){


		

	

		titulo();
	printf("\t\t\tSair[x]\n\n");
	tamtab( &linhas, &colunas); //Funcao que pede ao jogador o numero de colunas e linhas para saber o tamanho da tabela

	tamanho=colunas*linhas;



	tabela = malloc(sizeof(char)*tamanho);//aloca tabela de jogo

	if(tabela == NULL)
	{
		puts("[Erro na alocacao de memoria tabela]");
	}

	posicoes = malloc(sizeof(int));//aloca array para posicoes
	if(posicoes==NULL)
		{
			printf("erro alocacao array posicoes");
			getchar();
			return lista;
		}



	//funcao jogo
	lista =	jogo(nJog, j, mc, linhas, colunas, jcria, tabela, njog, ord, njogadas, lista, undo, posicoes, njact); //cria matriz e dentro faz gestao do jogo || falta receber tamanho da matriz e enviar a tabela com os linhas, colunasores
	/*for(i=0;i<nJog;i++){
							free(p[i]);
						}
						//free(p);
		*/
	}
	j=Libertarnomes(nJog, j);//liberta estrutura de array de ponteiros
	free(j);
	return lista;
	
	
}

int tras()//opcao sair confirmar ou nao a saida do Jogo
{
	char res;
	
	do{
		
		printf("\n\t     Tem a certeza que pretende voltar para o menu principal?\n\n\t\t  sim[s]\tnao[n] \n\t\t\t   ");

		res = getchar();
		fflush(stdin);

		if(res == 's')
		{
		return 1;


		}else{if(res == 'n')
				break;
		
		}

	}while(res != 's' || res != 'n');
	return 0;

}



void instrucoes()
{
	escreve_instrucoes();
}




player jogadores(player lista)
{
	int op, total;


	do{
		total=conta_jogador(lista);
	titulo();
	
	printf("\n\tMenu principal\n\t  >>Jogadores\n\n");
	
	printf("\n\t1 - Inserir novo jogador");
	printf("\t\t2 - Listar jogadores");
	printf("\n\n\t3 - Eliminar jogador");
	printf("\t\t\t4 - Recuperar Password\n");
	printf("\n\t5 - Menu Principal\n");
	printf("\n\n\t----------------------------------------------------------------\n");
	printf("\n\t\tEstatisticas Globais");
	printf("\n");
	printf("\n\tNumero total de jogadores registados: %d\n\n", total);

	

	do{
		printf("\nEscolha uma opcao: ");
		scanf("%d", &op);
	}while(op<1 || op>5);
	
	switch(op){
		case 1:	system("cls");
				lista=inserir_player(lista);
				break;
		case 2: system("cls");
				mostrar_lista(lista);
				break; 
		case 3: system("cls");
				lista= eliminar_player(lista);
				break;
		case 4: system("cls");
				recoverPW(lista);
				break;
		} 

	}while(op!=5); 


	return lista;

}

void top1(player lista)//mostra 10 primeiros nomes
{
	
	char res;
	do{
	titulo();
	printf("\t\tMenu Principal[x]\n");
	printf("\n\n\tMenu principal\n\t  >>Top 10\n");
	printf("\t\t\t----------------------------------------\n");
	printf("\t\t\t Rank\t\t  Nome\t\t Pontos");
	printf("\n\t\t\t----------------------------------------");
	
	top(lista);
	printf("\n\t\t\t");
	
	scanf("%c", &res);
	fflush(stdin);
	if(res == 'x')
				{	
					return ;
				}
	}while(res != 'x');
}
//-------------------------------------------------------------------------------------------------------players


player ranking(player p, char *nome, int x) // actualizar pontuaçao do jogador (os que acabaram de jogar)
{
	player aux,act,ant=NULL,ant2=NULL;
	aux=p;					//inicializa o aux com o ponteiro do inicio da lista
	while(aux!=NULL)		// percorre a lista ligada
	{
		if(strcmp(aux->nick,nome)==0)	// compara o nick do jogador com os nicks registados
		{
			if(ant2==NULL)
			{
				p=aux->prox;
			}else{
			ant2->prox=aux->prox;
			aux->prox=NULL;
			}
			if(x==0) // o primeiro jogador inserido e aquele que ganhou, logo incrementa-se nas victorias e actualiza-se pontuaçao
			{
				aux->victoria+=1;
				aux->pontuacao+=2;
				act=p;

				while(act->prox!=NULL && aux->pontuacao<=act->pontuacao)
				{
					ant=act;
					act=act->prox;
				}
					
				if(ant==NULL)
				{
					aux->prox=act;
					p=aux;
					
				}else{

				if(act->prox!=NULL)
				{
					ant->prox = aux;
					aux->prox = act;
				}
				}
				
				
			}else{ // se nao for o primeiro jogador sao os jogadores derrotados, logo incrementa-se nas derrotas e actualiza-se pontuaçao
				aux->derrota+=1;
				aux->pontuacao-=1;
				act=p;
				while(act!=NULL && aux->pontuacao<=act->pontuacao)
				{
					ant=act;
					act=act->prox;
				}
				if(ant==NULL)
				{
					aux->prox=act;
					p=aux;

				}else{
					
				if(act!=NULL)
				{
					ant->prox = aux;
					aux->prox = act;
				}else{
					ant->prox = aux;
					aux->prox = NULL;
				}
				}
				
			}
		}
		ant2=aux;
		aux=aux->prox;
	}
	
	
	free (aux);
	return p;
}



void top(player p)    //lista os 10 jogadores com maior pontuacao
{
    int i=0;
	
    if(p==NULL)
        printf("Lista Vazia");
    else
    {
		while(i!=10 && p!=NULL)
        {
            printf("\n\t\t\t   %d\t\t%s\t\t%d", i+1,p->nick,p->pontuacao);
            p=p->prox;
            i++;
        }
    }
}







int conta_jogador(player aux) // funçao recursiva para contar o numero de jogadores existentes na lista ligada
{
	if (aux==NULL)		//esta funçao so para quando aux for NULL que indica que chegou ao final da lista
		return 0;
	else				// se nao estiver no final da lista incrementa +1
		return 1+conta_jogador(aux->prox);
}



void recoverPW(player p)
{
	char nick[ST_NICK];
	char nome[ST_NICK];
	char pw[ST_PW];
	int i=0;

	titulo();
	if (p==NULL)		//Lista encontra-se vazia
	{
		printf("Lista vazia");
		return;
	}
	printf("\n\n\t---- NOVA PASSWORD -----\n");
	getchar();printf("\n");
	printf("\n\tNick: ");
	gets(nick);
	printf("\n\tNome: ");
	gets(nome);
	
	while (p!=NULL)	
	{
		if(strcmp(p->nome,nome)==0 && strcmp(p->nick,nick)==0)	// se o nome e o nick inserido forem iguais aos do jogador 
		{														//que se encontra na lista pede-se entao para inserir uma nova password
            printf("\tInsira a nova password");
			gets(pw);
			if(strcpy(p->pw,pw))		// verificar se a password foi mesmo modificada (teste)
			{
				printf("\tPassword Modificada!");
				getchar();
				break;
				break;
			}else
				printf("ERRO!");break;break;
        }
		p=p->prox;	
	}
}






player eliminar_player(player p)		//elimina jogador
{
	player act, ant=NULL;
	char nick[ST_NICK];
	act=p;
	if (p==NULL)		// se o ponteiro do inicio da lista for igual a NULL entao a lista encontra-se vazia e retorna a lista
	{
		printf("Lista Vazia");
		return p;
	}
	getchar();
	printf("Insira o Nick do jogador que pretende eliminar: ");
	gets(nick);
	if(act==NULL) // se o ponteiro act que foi inicializado com o ponteiro para o inicio da lista for igual a NULL a lista esta vazia e retorna a lista
	{
		printf("Lista vazia\n");
		return p;
	}
	while(act != NULL && strcmp(act->nick,nick)!=0) // percorre a lista dos jogadores ate encontrar o nick do jogador inserido
	{
		ant = act;
		act = act->prox;
	}
	if(act == NULL)	// se for igual a NULL o jogador nao existe
	{
		printf("Nao existe o jogador %s",nick);
		return p;
	}
	if(ant == NULL) // se for o primeiro elemento o ponteiro da lista dos jogadores e actualizado apontando para o proximo jogador
		p = act->prox;
	else // se nao liga o jogador anterior ao seguinte eliminando o jogador que se encontrava no meio deles
		ant->prox = act->prox;
	free(act);// liberta o act
	return p;// retorna a lista
}



void mostrar_lista(player p)	//lista todos os jogadores
{
	titulo();
	printf("\n\n");
	if(p==NULL)
		printf("Lista Vazia");
	else
	{
		while(p!=NULL)
		{
			printf("\n\tNick: %s\tPontuaçao: %d\n\tVictorias: %d\tDerrotas: %d\n",p->nick,p->pontuacao,p->victoria,p->derrota);
			p=p->prox;
		}
	}
	getchar();
	getchar();
}


player login(player p) //login do jogador
{
	player aux;
	char nick[ST_NICK];
	char pw[ST_PW];
	int i=0;

	aux=p;	// inicializa o aux com o ponteiro para o primeiro elemento da lista

	if (aux==NULL)	// se for igual a NULL a lista de jogadores esta vazia e sai da funçao
	{
		printf("Lista vazia");
		return aux;
	}
	//printf("---- LOGIN -----\n");
	//getchar();
	printf("\n\t");
	printf("Nick: ");
	gets(nick);

	printf("\n\tPassword: ");
	gets(pw);
	

	while (aux!=NULL)	
	{
		if(strcmp(aux->pw,pw)==0 && strcmp(aux->nick,nick)==0)	// se a password e o nick inseridos
		{														// forem iguais a algum jogador
            i=1;break;break;									// sai do ciclo
        }
		else
			i=0;											
		aux=aux->prox;	
	}


	if (i==1){		// se for e porque encontrou o jogador na lista e validou com a password
		
		return aux;
	}else{			// se nao o jogador nao esta registado
		printf("\n\tNao esta Registado\n");
		getchar();
		return aux;
	}
	
	
}






int vnick(player p,char *nick) // função para verificar se o nick ja existe
{
    while(p!=NULL && strcmp(p->nick,nick)!=0)	// percorre a lista ligada dos jogadores 
       p=p->prox;								// e pára quando encontrar um nick igual 
    if(p==NULL)									// ao nick ja existente na lista
        return 0;
    else
        return 1;
}



player inserir_player(player p)
{
	char nick[ST_NICK], nome[ST_NICK];
	char pw[ST_PW];
	player novo, aux;

	fflush(stdin);

	titulo();
	printf("\n\n\tNome: ");
	gets(nome);
    do{
		printf("\n\tNick: ");
		gets(nick);
	}while(vnick(p,nick)!=0);	// vai estar sempre dentro ciclo ate que o utilizador 
								// insira um nick que nao exista
	printf("\n\tPassword: ");		
	gets(pw);

	novo=malloc(sizeof(no));	// aloca memoria pra lista ligada
	if (novo==NULL)				// se falhar na alocaçao de memoria retorna o ponteiro para o inicio da lista
		return p;
	strcpy(novo->nome,nome);
	strcpy(novo->nick,nick);
	strcpy(novo->pw,pw);
	novo->derrota=0;			//inicializa as derrotas
	novo->victoria=0;			//inicializa as victorias
	novo->pontuacao=100+((novo->victoria)*2)-(novo->derrota);	//inicializa a pontuaçao
	novo->prox=NULL;
	if(p==NULL ||novo->pontuacao>p->pontuacao)	// caso seja o primeiro elemento
	{
		novo->prox=p;
		p=novo;
	}
	else		// caso ja exista elementos na estrutura
	{
		aux=p;
		while(aux->prox!=NULL && novo->pontuacao<aux->prox->pontuacao) //posiciona o ponteiro para inserir de maneira ordenada pela pontuaçao
			aux=aux->prox;
		novo->prox=aux->prox;
		aux->prox=novo;
	}
	return p;
}



player recupera(player p)
{
	FILE *f;
	player novo=NULL,aux=NULL;
	f=fopen("jogadores.txt","r");
	if(f==NULL)	// se f for igual a null deu erro na abertura do ficheiro ou nao tem nada la dentro
	{
		printf("ERROOO!!! ou LISTA VAZIA");
		return p;
	}
	else
	{
		while(feof(f)==0) // faz ate chegar ao fim do ficheiro
		{
			novo=malloc(sizeof(no));					// aloca memoria
			fgets(novo->nome,50,f);						// copia os dados para a lista ligada
			novo->nome[strlen(novo->nome)-1]='\0';
			fgets(novo->nick,50,f);		
			novo->nick[strlen(novo->nick)-1]='\0';
			fgets(novo->pw,20,f);
			novo->pw[strlen(novo->pw)-1]='\0';
			fscanf(f," %d ",&novo->pontuacao);
			fscanf(f," %d ",&novo->derrota);
			fscanf(f," %d ",&novo->victoria);
			novo->prox=NULL;
			if(p==NULL ||novo->pontuacao>p->pontuacao)	// caso seja o primeiro elemento
			{
				novo->prox=p;
				p=novo;
			}
			else		// caso ja exista elementos na estrutura
			{
				aux=p;
				while(aux->prox!=NULL && novo->pontuacao<aux->prox->pontuacao) //posiciona o ponteiro para inserir de maneira ordenada pela pontuaçao
					aux=aux->prox;
				novo->prox=aux->prox;
				aux->prox=novo;
			}
	        
        }
	}
	fclose(f);
	return p;
}


void grava_ficheiro(player p)
{
	FILE *f;
	if (p==NULL)		// se a lista estiver vazia remove o ficheiro dos jogadores e retorna pra main
	{
		remove("jogadores.txt");
		return;
	}
	remove("jogadores.txt");		// remove o ficheiro jogadores.txt
	f=fopen("jogadores.txt","w");	// cria e abre para escrita o ficheiro jogadores.txt
	if (f==NULL)					//erro ao abrir o ficheiro
	{
		printf("ERRO!!!");
		return;
	}else{
		while(p!=NULL)				//percorre a lista ligada, inserindo para o ficheiro
		{
			fprintf(f,"%s\n%s\n%s\n%d\n%d\n%d\n",p->nome,p->nick,p->pw,p->pontuacao,p->derrota,p->victoria);
			p=p->prox;
		}
		free(p); // liberta o no
	}
	fclose(f); // fecha o ficheiro
}

