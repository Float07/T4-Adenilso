#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Rummikub.h"

#define CARTA_NBR 104
#define CORINGA_NBR 2

int main()
{	
	clock_t seed = clock();
	srand(seed);//define uma seed para o rand
    clear();
    int primeira;
    t_player* player;
    t_player player_temp;
    t_carta* baralho;
    baralho = (t_carta*)malloc((CARTA_NBR+CORINGA_NBR)*sizeof(t_carta));
    if (baralho == NULL)
    {
    	printf("Memoria insuficiente, encerrando!!!(Sindo muito)\n");
    	exit(0);
    }

    /*cria e zera o conjunto de cartas*/
    t_tabuleiro_ptr conjunto = (t_tabuleiro*)malloc(sizeof(t_tabuleiro));
    t_tabuleiro* conjunto_temp = NULL;
    if (conjunto == NULL)
    {
    	printf("Memoria insuficiente, encerrando!\n");
    	exit(0);
    }
    conjunto->n = 0;
    conjunto->next = NULL;
    for (int i = 0; i < 13; ++i)
    {
    	conjunto->carta[i].nbr = '0';
    }
    /*cria e zera o conjunto de cartas*/

    int player_nbr;
    int flag = 0;
    int cartas_baralho = (CARTA_NBR + CORINGA_NBR);
    int victory = 0; //verifica se alguem venceu
    int numpl = 0; //indica o numero do player que está jogando
    int finalizar = 0; //verifica se o player deseja finalizar a jogada
    int opt; //registra a escolha do player durante sua jogada

    criar_baralho(baralho);
    printf("                          -----------------------------\n");
    printf("                          |   Bem Vindo ao Rummikub!  |\n");
    printf("                          -----------------------------\n");
    while(!flag){
        printf("Numero de jogadores(1 - 5):");
        scanf("%d", &player_nbr);
        if(player_nbr < 1 || player_nbr > 5){
            printf("Numero invalido! Digite novamente!\n");
        }else{
            flag = 1;
        }
    }
    flag = 0;
   	clear();

    player = alocar_jogadores(player_nbr);
    for (int i = 0; i <= player_nbr; ++i)
    {
        player->numjogada=0;
    }
    distribuir_baralho(player_nbr, player, baralho, &cartas_baralho);
    while(!victory)
    {
    	printf("vez do jogador %d!\n", numpl + 1);

    	while(!finalizar){
	    	copia_reset(conjunto_temp, conjunto , player, &player_temp , numpl);
            printf("                               Mesa:\n");
            imprime_tabuleiro(conjunto, 1);
	    	printf("\n\n                               Sua mao:\n");
	    	imprime_mao(player, numpl);
	    	printf("\n\n                 O que deseja fazer?\n                 1-Adicionar uma carta\n                 2-Pegar uma carta\n                 3-Comprar uma carta\n\n                 0-Finalizar jogada\n");
	    	scanf("%d", &opt);
	    	clear();
	    	printf("                               Mesa:\n");
	    	imprime_tabuleiro(conjunto, 1);
	    	printf("\n\n                               Sua mao:\n");
	    	imprime_mao(player, numpl);
	    	printf("\n");
	    	if(player->numjogada == 0){
                primeira = somar_mao(player , numpl);
            }
            if (opt == 1)
	    	{
	    		adicionar_carta(conjunto, player, numpl);
	    	}else if(opt == 2)
	    	{
	    		pegar_carta(conjunto, player, numpl);
	    	}else if (opt == 3)
	    	{
	    		comprar_carta(player, baralho, &cartas_baralho, numpl);
	    	}
            else if(opt == 0){
                if(player[numpl].numjogada == 0){
                    printf("qualquer coisa0\n");
                    int aux = somar_mao(player, numpl)-primeira;
                    if (aux < 30)
                    {
                        printf("qualquer coisa1\n");
                        resetar_jogada( conjunto_temp, conjunto, player , player_temp , numpl); //primeira jogada nao somou 30 nas cartas
                    }
                    else{
                        printf("qualquer coisa2\n");
                        player[numpl].numjogada++;
                    }
                }
            }		
        }

    	numpl = (numpl + 1)%player_nbr;
    }
    
    liberar_jogadores(player_nbr, player);
    free(baralho);
}