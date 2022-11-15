#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int l = 0;
	int c = 0;
	int perg = 0;
	int escL = 0;
	int escC = 0;
	int ptj1 = 0;
	
	
	int dama[8][8];
	
	printf("======== JOGO DE DAMA ======== \n");	
	
	
	for(l = 0; l < 8; l++){//o tabuleiro ta todo zerado, então é como fosse tudo de uma cor só, to vendo se precisa mudar ou não;
		for(c = 0; c < 8; c++){
			dama[l][c] = 0;
			
		}
		
	}
	
	for(l = 0; l <3; l++){//adiciona todas as peças brancas, ou "1";
		for(c = 0; c<8;c++){
			if(l%2==0 && c%2==0){
				dama[l][c] = 1;
			}
			else if(l%2!=0 && c%2!=0){
				dama[l][c] = 1;
			}
			
		}
	}
	
	
	for(l = 5; l <8; l++){//adiciona todas as peças pretas, ou "2";
		for(c = 0; c<8;c++){
			if(l%2==0 && c%2==0){
				dama[l][c] = 2;
			}
			else if(l%2!=0 && c%2!=0){
				dama[l][c] = 2;
			}
			
		}
	}
	dama[5][1] = 0;
	dama[4][1] = 2;
	
	while(perg !=4){// aqui tava pensando em por Coluna por Letras, tipo A B C D...
		printf(" 0   1   2   3   4   5   6   7\n");//isso faz mostrar o tabuleiro, talvez ficou muito espaçado sla
		for(l = 0; l < 8; l++){
			printf("\n");
		for(c = 0; c < 8; c++){
			
			printf("|%d| ",dama[l][c]);
			
			
		}
		printf(" %d ", l);
		printf("\n");
		
	}	
		//até agr conseguir fazer isso, mas ainda preciso separar Jogador 1, Jogador 2
		printf("\nDigite qual peca voce quer movimentar LINHA: ");
		scanf("%d",&escL);
		printf("Digite qual peca voce quer movimentar COLUNA: ");
		scanf("%d",&escC);
		if(dama[escL][escC] == 1){
			dama[escL][escC] = 0;
			printf("Digite a nova posicao LINHA: ");
			scanf("%d", &escL);
			printf("Digite a nova posicao COLUNA: ");
			scanf("%d", &escC);
			
			if(dama[escL][escC] == 2 && dama[escL +1][escC+1]==0 || dama[escL+1][escC-1] ==0 ){
				printf("peca capiturada \n");
				dama[escL+1][escC+1] = 1;
				dama[escL][escC] = 0;
				ptj1++;
				printf(" \n Pontos jogador 1 --%d-- \n", ptj1);
				
			}
			else{
				dama[escL][escC] = 1;
			}
			
			
			
			
		}
		else{
			printf("\nPosicao invalida! \n\n");
		}
		
	
		//printf("Digite 1 para parar: ");
		//scanf("%d",&perg);
		perg++;
		if(perg ==4){
			break;
		}
		//dama[2][0] = 0;
		//dama[3][1] = 1;
	
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
