#ifndef RUMMIKUB_H_INCLUDED
#define RUMMIKUB_H_INCLUDED

typedef struct{
    char cor;
    char nbr;
}t_carta;

typedef struct{
    int cards;//quantidade de cartas do jogador
    t_carta* carta;
 	int numjogada;
}t_player;

struct tabuleiro{
	t_carta carta[13];
	struct tabuleiro *next;
};
typedef struct tabuleiro t_tabuleiro; 
typedef t_tabuleiro *t_tabuleiro_ptr;

void criar_baralho(t_carta* carta); //cria o baralho
t_player* alocar_jogadores(int player_nbr); //aloca espaço para os jogadores e para seus baralhos
void liberar_jogadores(int player_nbr, t_player* player);//Libera o espaço usado pelos jogadores e seus baralhos
void clear(); //limpa a tela (windows e linux)
void distribuir_baralho(int player_nbr, t_player* player, t_carta* baralho, int* cartas_baralho); // distribui aleatoriamente o baralho antes do jogo começar
void comprar_carta(t_player* player, t_carta* baralho, int* cartas_baralho, int numpl); //faz com que o jogador "numpl" receba uma carta aleatória do monte
void imprime_tabuleiro(t_tabuleiro_ptr conjunto, int n); //função que imprime tabuleiro
void imprime_mao(t_player* player, int numpl); //imprime a mao do jogador na tela
void adicionar_carta(t_tabuleiro_ptr conjunto, t_player* player, int numpl); //Deixa o player posicionar uma carta no tabuleiro
void mudar_pos(t_tabuleiro_ptr conjunto, t_player* player, int numpl); //Deixa o player pegar uma carta da mesa
void resetar_jogada(t_tabuleiro_ptr conjunto_temp, t_tabuleiro_ptr conjunto, t_player* player, t_player player_temp, int numpl); //Reseta o tabuleiro para o inicio da jogada caso o player faça uma jogada errada
t_tabuleiro_ptr copia_reset(t_tabuleiro_ptr conjunto_temp, t_tabuleiro_ptr conjunto, t_player* player, t_player* player_temp, int numpl); //Copia o tabuleiro e o player para que se possa resetar a jogada
int checar(t_tabuleiro_ptr conjunto); //Checa se a jogada eh valida
int somar_mao(t_player* player, int numpl); // Soma a mao do jogador
void fim_jogo(int player_nbr , t_player* player, t_tabuleiro_ptr conjunto); // Calcula os pontos no final do jogo
void distribuir_baralho_texto(int player_nbr,t_player* player, t_carta* baralho, int* cartas_baralho); //distribui baralho usando baralho.txt
int hexa_binario(char c); //transforma hexa em binario
void liberar_coluna(t_tabuleiro_ptr conjunto); //Libera espaço ocupado pelo tabuleiro

#endif // RUMMIKUB_H_INCLUDED