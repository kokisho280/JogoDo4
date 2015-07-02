#include "gestaoTab.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>


void cod_alfanum(char *st)
{
	char alf[63]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int x;
	
	srand(time(NULL));

	for(x=0;x<5;x++)
		*(st+x)=alf[rand()%61];
	*(st+5)='\0';
	return;

}



void guardarjogo( char *tabela, int njogadas, int linhas, int colunas, jogador **j, int njogadores, int njog, int ord, int undo, int *posicoes, int njact)
{

																							/* Ficheiro de jogo 
																						N.total de jogadores no jogo
																						Estrutura(nome,registado,undo)
																						.
																						.
																						linhas
																						colunas
																						N.total de jogadas
																						N.jogadores ainda em jogo
																						ordem
																						undo
																						N.jogadas actuais
																						posicoes
																						.
																						.
																						tabela
																						*/



	int i, tamanho;

	


	char st[6];
	FILE *f;

	cod_alfanum(st);
	

	printf("\n\t\tCodigo de jogo: '%s'\n\n", st);



	f = fopen(st,"w");				//abre ficheiro
	if(f==NULL)
	{
		printf("\n\t[Erro acesso ao ficheiro]\n");
		return;
	}

	tamanho=colunas*linhas;

	fprintf(f, "%d\n", njogadores); //comeca por escrever numero total jogadores

	for(i=0;i<njogadores;i++)		//escreve campos da estrutura jogadores
	{
		fprintf(f,"%s\n",j[i]->nickj);
		fprintf(f,"%d\n",j[i]->registado);
		fprintf(f,"%d\n",j[i]->undo);
	}

	
	fprintf(f, "%d\n%d\n%d\n%d\n%d\n", linhas, colunas, njogadas, njog, ord); 
	
	
	fprintf(f, "%d\n%d\n", undo, njact);
	for(i=0;i<njact;i++)
	{
		fprintf(f,"%d\n", posicoes[i]);
	}

	for(i=0;i<tamanho;i++)
	{
		fputc(tabela[i], f);
	}
	
	
	fclose(f);

	getchar();
	





}
		
player carregarjogo(player lista)		//funcao carrega jogo
{
	int i, tamanho, linhas, colunas, njogadores, njogadas, len, jcria=0, mc=0, njog, ord, njact, *posicoes, undo;
	char inf, *tabela;
	char cod[8];
	FILE *f;
	jogador **j;


	
	titulo();
	printf("\n\n\tMenu principal\n\t  >>Carregar Jogo\n");
	printf("\n\tPor favor insira codigo de jogo:");
	gets(cod);

	f = fopen(cod,"r");		//abre ficheiro com nome de codigo inserido
	if(f==NULL)
	{
		printf("\n\t[Erro acesso ao ficheiro]\n");
		return lista;
	}

	else 
	{ 
	fscanf(f, " %d ", &njogadores); 

	j = malloc(sizeof(jogador)*njogadores);//cria array de ponteiros para estrutura jogadores 


		if(j==NULL)
		{
			printf("erro alocacao");	
		}

		for(i=0;i<njogadores;i++)//cria espaco para alocar jogadores
		{
			j[i]= malloc(sizeof(jogador));

		}

		for(i=0;i<njogadores;i++)//le dados para estruturas
		{
			fgets(j[i]->nickj, 20, f);
			fscanf(f, " %d ", &j[i]->registado);
			fscanf(f, " %d ", &j[i]->undo);

			len = strlen(j[i]->nickj);//corrige o tamanho (gets guardo com \n)
			if (len > 0 && j[i]->nickj[len-1] == '\n')  // se newline
				j[i]->nickj[len-1] = '\0';
		}

		

		fscanf(f, " %d ", &linhas);
		fscanf(f, " %d ", &colunas);
		fscanf(f, " %d ", &njogadas);
		fscanf(f, " %d ", &njog);
		fscanf(f, " %d ", &ord);
		fscanf(f, " %d ", &undo);
		fscanf(f, " %d ", &njact);


		


		

		

		posicoes = malloc(sizeof(int)*(njact+1));//aloca espaco para as posicoes jogadas

		for(i=0;i<njact;i++)
		{
			fscanf(f," %d ", &posicoes[i]);
		}
		tamanho=colunas*linhas;

		tabela = malloc(sizeof(char)*tamanho);

		if(tabela == NULL)
		{
			puts("[Erro na alucacao de memoria]");
			return lista;
		}
		fgets(tabela,tamanho,f);//guarda tabela de jogo


	fclose(f); 
	
	//apresenta alguns dados do jogo


	titulo();
	printf("\n\n\tMenu principal\n\t  >>Carregar Jogo\n");
	printf("\t\t\t\tInformacao do jogo:");
	printf("\n\n\t\tJogadores:%d\n", njogadores);

	for(i=0;i<njogadores;i++)
		{
			printf("\t\t%d:%s\n", i+1, j[i]->nickj);

			
			
		}

	printf("\n\n\t\tTamanho do tabuleiro, linhas:%d, colunas:%d\n", linhas, colunas);
	printf("\n\n\t\tNumero total de jogadas efectuadas:%d\n\n", njogadas);

	
	do{
		printf("\t\tContinuar?");
		printf("\t\t  sim[s]\tnao[n] \t");
		scanf("%c", &inf);
		fflush(stdin);
	}while(inf != 's' && inf != 'n');

	if(inf=='s'){

	jogo(njogadores, j, mc, linhas, colunas, jcria, tabela, njog, ord, njogadas, lista, undo, posicoes, njact);
	
	remove(cod);
	}
	}





	j=Libertarnomes(njog, j);//liberta os ponteiros para estruturas dentro do array
	free(j);//liberta array
	
	return lista;


		

}




void escrevetab(char *tab, int colunas, int linhas)//Funcao escreve na consola a tabela 'formatada'  
{
		/*exemplo 3*3:     A B C
						  A+-+-+
						   | | |
						  B+-+-+
						   | | |
						  C+-+-+
		*/

	int i, j;
	
	
	for(i=0;i<linhas*2;i++)
	{		
		if(i==0)														//Se linha 0 imprime letras
		{
			printf("\n\t ");
	
			for(j=0;j<colunas;j++)
				printf("%c ", j+65);
		}else{														//Se nao for linha 0

				printf("\n\t");
				if(i%2==0)											//Se linha for par imprime '| '
				{
					printf(" ");
					for(j=0;j<colunas;j++)
						printf("| ");
				}else{												//Se nao for linha 0 nem par

						printf("%c", (i/2)+65);						//Imprime letra
						for(j=0;j<colunas;j++)
						{
			
							printf("%c",tab[j+((i/2)*colunas)]);	//E imprime cada caracter do array seguido de '-' 
							if(j!=colunas-1)
								printf("-");						//Excepto na ultima coluna

						}
					}
				}
	}
}






void inicializatab(char *tab, int tamanho)
{
	int i;
	for(i=0;i<tamanho;i++) //Inicializa tabela com caracter '+' ,caso seja aumentado o tamanho da tabela nao altera as posicoes jogadas antes
	{
		if(tab[i]!='O' && tab[i]!='0')
		tab[i]='+';
	}
}


void tamtab( int *l, int *c)//Funcao que pede ao jogador o numero de colunas e linhas para saber o tamanho da tabela
{
	do{
	//system("cls");
	puts("\n\tCom  que tamanho deseja iniciar o tabuleiro?");
	printf("\n\tNumero de linhas (Minimo 3, Maximo inicial 8):");
	scanf("%d", l);
	fflush(stdin);
	printf("\n\tNumero de colunas (Minimo 3, Maximo inicial 15):");
	scanf("%d", c);
	fflush(stdin);
	}while((*l>8 || *l<3)|| (*c>15 || *c<3));
}
	
player jogo(int njogadores, jogador **j, int mc, int linhas, int colunas, int jcria, char *tabela, int njog, int ord, int njogadas, player lista, int undo, int *posicoes, int njact)
{
	//funcao que gere jogadores e tabela enquanto se joga
	
	char *tab;
	jogador *aux;
	int tamanho, x, pov, c=0;
	int posh, posv, ret, i, *posicoes1;
	
	
	tamanho=colunas*linhas;
	inicializatab(tabela,tamanho);//Inicializa tabela com caracter '+' ,caso seja aumentado o tamanho da tabela nao altera as posicoes jogadas antes
	titulo();
	printf("\t\t\tSair[x]\n");
	if(undo==0)
	{
		printf("\t\t\t\t\t\t\t\tUndo[u]\n");
	}
	
	escrevetab(tabela, colunas, linhas);
	putchar('\n\n');
	

	do{
	
		
			do{			
			
				printf("\n\tJogador - %s\n\n", j[ord]->nickj);
			ret = pos_jog( &posh, &posv, colunas, linhas, mc, posicoes, tabela, j[ord], &njact, njogadores, ord, undo);//funcao pede coordenadas, x, e undo
			pov = posv;
			posv= posv*colunas;

			if(ret==1){//se a funcao pos_jog devolver 1 e pa sair do jogo


				if(mc==0){

				guardarjogo( tabela, njogadas, linhas, colunas, j, njogadores, njog, ord, undo, posicoes, njact);
				}

				free(tabela);
				
				return lista;


			}
			
			if((posh>=colunas || posh<0) || (pov>=linhas || pov<0)){//caso facam undo ou x torna apresentar tabela etc e continua a jogar
				
					titulo();
					printf("\t\t\tSair[x]\n");
					if(undo==0)
					{
						printf("\t\t\t\t\t\t\t\tUndo[u]\n");
					}
					escrevetab(tabela, colunas, linhas);
					
					putchar('\n');
					printf("\t\t\tNumero de jogadas efectuadas:%d\n\n", njogadas);
					
			}else{
				if(tabela[posh+posv]=='O' || tabela[posh+posv]=='0'){
					printf("\n\tNao pode repetir posicoes!\n\n");
					posh = -1;
				}else{
					tabela[posh+posv]='O';//insere posicao inserida na tabela
					posicoes[njact] = posh+posv;//guarda posicao inserida
					
					njact++;//aumenta jogadas actuais(undo)
					njogadas++;//aumenta total de jogadas efectuadas
					posicoes1 = realloc(posicoes,sizeof(int)*(njact+1));//aumenta tamanho de posicoes para receber proxima jogada
					if(posicoes1 == NULL)
						{
							printf("ERRO alocacao memoria posicoes");
					}else{

						posicoes=posicoes1;
					
						}
					
				}
			}
		
			
			}while((posh>=colunas || posh<0) || (pov>=linhas || pov<0));//verifica se posicoes inseridas sao validas

			

			
			for(i=1;i<colunas-posh;i++)	
				//verifica se desde a posicao escolhida para frente ate ao final dessa linha
		{
		if(tabela[posh+posv+i]=='O' || tabela[posh+posv+i]=='0'){ 
			//com o i(distancia) de cima, verifica se com o mesmo i para baixo.
			if((tabela[posh+posv+(colunas*i)]=='O' || tabela[posh+posv+(colunas*i)]=='0') && (tabela[posh+posv+i+(colunas*i)]=='O' || tabela[posh+posv+i+(colunas*i)]=='0')){
				//se verificar quadrado altera as posicoes para '0'
				tabela[posh+posv]='0';
				tabela[posh+posv+i]='0';
				tabela[posh+posv+(colunas*i)]='0';
				tabela[posh+posv+i+(colunas*i)]='0';
				if(njog>=3){//e se njog actuais altera ordem dos jogadores no array **j e altera colunas e linhas para mais a frente fazer nova alocacao com +1 linha e coluna
				
				aux=j[ord];//aux guarda jogador que perdeu
				for(x=0;x<(njog-1)-ord;x++)//desde a posicao que jogador perdeu ate njogadores actuais- ordem (ex: jC perde desde posicao de C ate ultimo jogador em jogo altera posicao para cima)
				{
				j[(ord+x)]=j[(ord+1+x)];
				}
				j[(ord+x)]=aux;//mete jgador que perdeu nao posicao a seguir ao ciclo
				ord=ord-1;
				njog--;
				colunas++;
				linhas++;
				c=1;//flag para fazer nova alocacao
			}else{
			if(njog<3){//se njogadores actuais menor que 3 altera ordem na mesma mas n altera linhas nem colunas pois tabuleiro nao vai mudar

				aux=j[ord];
				for(x=0;x<(njog-1)-ord;x++)
				{
				j[(ord+x)]=j[(ord+1+x)];
				}
				j[(ord+x)]=aux;
				ord=ord-1;
				njog--;
				}
				}

			}else{//com o i(distancia) de cima, verifica se com o mesmo i para cima.
				if((tabela[posh+posv-(colunas*i)]=='O' || tabela[posh+posv-(colunas*i)]=='0') && (tabela[posh+posv+i-(colunas*i)]=='O' || tabela[posh+posv+i-(colunas*i)]=='0')){
					tabela[posh+posv]='0';
					tabela[posh+posv+i]='0';
					tabela[posh+posv-(colunas*i)]='0';
					tabela[posh+posv+i-(colunas*i)]='0';
					if(njog>=3){

					aux=j[ord];
				for(x=0;x<(njog-1)-ord;x++)
				{
				j[ord+x]=j[ord+1+x];
				}
				j[ord+x]=aux;
				ord=ord-1;
						njog--;
						colunas++;
						linhas++;
						c=1;
					}else{
					if(njog<3){
							
							aux=j[ord];
				for(x=0;x<(njog-1)-ord;x++)
				{
				j[ord+x]=j[ord+1+x];
				}
				j[ord+x]=aux;
				ord=ord-1;
					njog--;
					}
					}
				}


			}
		}
	}

	if(c==0)
	{
		for(i=1;i<=posh;i++)	
			//verifica se desde a posicao escolhida para tras ate ao inicio dessa linha
		{
			if(tabela[posh+posv-i]=='O' || tabela[posh+posv-i]=='0')
			{
				//com o i(distancia) de cima, verifica se com o mesmo i para baixo.
				if((tabela[posh+posv+(colunas*i)]=='O' || tabela[posh+posv+(colunas*i)]=='0') && (tabela[posh+posv-i+(colunas*i)]=='O' || tabela[posh+posv-i+(colunas*i)]=='0'))
				{
					tabela[posh+posv]='0';
					tabela[posh+posv-i]='0';
					tabela[posh+posv+(colunas*i)]='0';
					tabela[posh+posv-i+(colunas*i)]='0';
					if(njog>=3)
					{
						aux=j[ord];
						for(x=0;x<(njog-1)-ord;x++)
							j[ord+x]=j[ord+1+x];
						j[ord+x]=aux;
						ord=ord-1;
						njog--;
						colunas++;
						linhas++;
						c=1;
					}else
					{
						if(njog<3)
						{
				
							aux=j[ord];
							for(x=0;x<(njog-1)-ord;x++)
								j[ord+x]=j[ord+1+x];
				
							j[ord+x]=aux;
							ord=ord-1;
							njog--;
						}

					}
				}else
				{//com o i(distancia) de cima, verifica se com o mesmo i para cima.
					if((tabela[posh+posv-(colunas*i)]=='O' || tabela[posh+posv-(colunas*i)]=='0') && (tabela[posh+posv-i-(colunas*i)]=='O' || tabela[posh+posv-i-(colunas*i)]=='0'))
					{
						tabela[posh+posv]='0';
						tabela[posh+posv-i]='0';
						tabela[posh+posv-(colunas*i)]='0';
						tabela[posh+posv-i-(colunas*i)]='0';
						if(njog>=3)
						{
							aux=j[ord];
							for(x=0;x<(njog-1)-ord;x++)
								j[ord+x]=j[ord+1+x];
				
							j[ord+x]=aux;
							ord=ord-1;
							njog--;
							colunas++;
							linhas++;
							c=1;
						}else
						{
							if(njog<3)
							{
								aux=j[ord];
								for(x=0;x<(njog-1)-ord;x++)
									j[ord+x]=j[ord+1+x];
								j[ord+x]=aux;
								ord=ord-1;
								njog--;
							}
						}
					}
				}
			}
		}
	}

	if(c==1 && njog>=2){//se a c =1 indicao para alterar tabela e se njogadores actuais for menor que 3
		undo=1;//undo deixa de funcionar pk um jogador perdeu
		tamanho = colunas*linhas;
		tab = realloc(tabela,sizeof(char)*tamanho);//nova alocacao com novo tamanho maior

		if(tab == NULL)
		{
			printf("ERRO alocacao memoria novo tamanho tabela");
		}else{

			tabela=tab;

		}

		//codigo em baixo-linha 1 posicao nao altera, linha 2 posicao altera -1 , linha 3 posicao altera - 2 (relatorio)

		for(i=linhas-1;i>=0;i--)//compoe posicoes da tabela ao fim de aumento do array, comecao do fim para o principio
		{
			for(x=colunas-1;x>=0;x--){//ultima linha ultima coluna(final do array)
				if(tabela[i*colunas+x]=='O')//verifica se foi posicao jogada
				{
					if((colunas-x)<=i+1)//verifica se a posicao e menor que a linha
					{
						tabela[i*colunas+x]='+';//altera posicao que estava o 'O' para + 
						tabela[i*colunas+x+i+1]='O';//
					}else{
						tabela[i*colunas+x]='+';
						tabela[i*colunas+x+i]='O';
					}
				}
				if(tabela[i*colunas+x]=='0')//mmo que em cima mas se as posicoes tiverem '0'
				{
					if((colunas-x)<=i+1)
					{
						tabela[i*colunas+x]='+';
						tabela[i*colunas+x+i+1]='0';
					}else{
						tabela[i*colunas+x]='+';
						tabela[i*colunas+x+i]='0';
					}
				
				}

			}
		}
		
		

		inicializatab(tabela,tamanho);//funcao que mete todas posicoes do array excepto as preenchidas com '+'

	}

	
	if(ord+1>=njog)//altera ordem se ordem =njogadores actuais volta ao 1 
	
		ord=0;
	else
		ord++;

	
	c=0;//flag de nova alocacao de tabela a 0



	titulo();
	printf("\t\t\tSair[x]\n");
	if(undo==0)
	{
		printf("\t\t\t\t\t\t\t\tUndo[u]\n");
	}
			

	escrevetab(tabela, colunas, linhas);
	putchar('\n');
	printf("\t\t\tNumero de jogadas efectuadas:%d\n\n", njogadas);


	}while(njog>1);//condicao para terminar jogo


	titulo();
	printf("\t\t\tSair[x]\n\n");
			
			

	escrevetab(tabela, colunas, linhas);
	printf("\t\t\tJogo terminado ");
	putchar('\n');
	printf("\n\t\t\tNumero de total de jogadas efectuadas:%d\n\n", njogadas);
	printf("\n\t\t\t\tVencedor:%s\n", j[0]->nickj);
	for(i=1;i<njogadores;i++){
		printf("\n\t\t\tDerrotado:%s\n", j[i]->nickj);
	}


	for(i=0;i<njogadores;i++)//percorre todos os jogadores e altera pontuacao dos registados
	{
		lista = ranking(lista,j[i]->nickj,i);

	}

	

	free(posicoes);//liberta arrays
	free(tabela);

	getchar();
	
	
	return lista;

}	


int pos_jog(int *c, int *l, int colunas,int linhas, int mc, int *posicoes, char *tabela, jogador *j, int *njact, int njogadores, int ord, int undo) //recebe as posicoes dos jogadores e valida(undo e sair)
{
	char ph, pv;
	int ret, esc, i, postabela;

	do{
	printf("\tInsira posicao horizontal:");
	
	ph = getchar();
	fflush(stdin);
	ph = toupper(ph);
	*c = ph - 'A';
	if(ph == 'X')
	{	ret = sairJ(mc);//confirma se quer sair do jogo
		if(ret==1)
			return 1;
		if(ret==0)
			return 0;
		}

	if(ph == 'U')
	{

		if(j->undo==1 && undo==0)		//se inda nao fez undo
		{					//pode fazer
		//undo();

		
		printf("\tJa fez %d jogadas", *njact/njogadores);	//njogadas actual / njogadores

		/*for(i=0;i<*njact;i++)
		{
			printf("\n%d-%d", i+1, posicoes[i]);
		}*/



	do{
		printf("\n\tPara que jogada deseja voltar?\t\t0-voltar");//pergunta para que jogada quer voltar
		scanf("%d", &esc);
		fflush(stdin);
		if(esc==0)
			return 0;

	}while(esc<0 || esc>*njact/njogadores);
		for(i=0;i<*njact-ord-njogadores*(esc-1);i++)//desde a jogada escolhida ate ao fim das jogadas guardadas
		{
		postabela=posicoes[ord+njogadores*(esc-1)+i];//vai ao array que guarda posicoes buscar valor da jogada 
		tabela[postabela]='+';//troca tabela posicao para 'O'
		
		}

		*njact=ord+njogadores*(esc-1);//actualiza njogadas actuais
		posicoes = realloc(posicoes,sizeof(int)*(*njact+1));//realloca o array para tamanho de jogadas necessarias +1 para receber proxima jogada
		

			j->undo=0;//altera estrutura do jogador actual para n poder fazer mais undo
		}else{
			if(undo==1){
			printf("\tJa nao pode utilizar [undo], alguns jogadores ja perderam ");
			getchar();
			}
			else
			{//caso ja tenham na estrutura k j->undo=0
				printf("\tJa utilizou [undo] uma vez");
				getchar();
			}

		}
		
		return 0;
		
		

	}else{//se escolheu posicao horizontal continua e pede vertical

	


	printf("\tInsira posicao vertical:");
	//scanf("%c", &pv); 
	//flushall();
	pv = getchar();
	fflush(stdin);
	pv = toupper(pv);
	*l = pv - 'A';

	if(pv=='X')
	{	ret=sairJ(mc);
		
		if(ret==1)
			return 1;
		if(ret==0)
			return 0;
	
	}
	


	if((*c>=colunas || *c<0) || (*l>=linhas || *l<0))
					printf("\n\t---Coordenadas nao sao validas---\n\n");
	
	}
	}while((*c>=colunas || *c<0) || (*l>=linhas || *l<0));

	return 0;
}



int sairJ(int mc)		//opcao sair confirmar ou nao a saida do Jogo
{
	char res;
	
	do{

		if(mc==1){//se modo convidado n guarda

						printf("\n\tNao esta a jogar em modo registado");
						printf("\n\tO jogo nao sera guardado");
						

					}
		if(mc==0){//se modo convidado informa que vau guardar

						printf("\n\tEsta a jogar em modo registado");
						printf("\n\tO jogo sera guardado");
						

					}
		
		printf("\n\t     Tem a certeza que pretende sair do jogo?\n\n\t\t  sim[s]\tnao[n] \n\t\t\t   ");

		res = getchar();
		fflush(stdin);

		if(res == 's')
		{
		return 1;

		}else{if(res == 'n')
			break;}

	}while(res != 's' || res != 'n');
	return 0;
}