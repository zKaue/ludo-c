#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

#define VERMELHO SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4)
#define VERDE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2)
#define AZUL SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1)
#define AMARELO SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6)
#define BRANCO SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)
#define LINHAS 31
#define COLUNAS 61

char Tabuleiro[LINHAS][COLUNAS] = {
    {201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,'#',' ','#',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',201,205,205,205,203,205,205,205,187,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',201,205,205,205,203,205,205,205,187,' ',' ',' ',' ',' ',' ',' ',186},
   	{186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',200,205,205,205,202,205,205,205,188,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',200,205,205,205,202,205,205,205,188,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,'&',' ','&',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {204,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,206,205,205,205,202,205,205,205,202,205,205,205,206,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,203,205,205,205,185},
    {186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,'&',' ','&',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,'#',' ','#',186},
    {204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185},
    {186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186},
    {204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,206,205,205,205,185},
    {186,'#',' ','#',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,'&',' ','&',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186},
    {204,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,206,205,205,205,203,205,205,205,203,205,205,205,206,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,185},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,'&',' ','&',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',201,205,205,205,203,205,205,205,187,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',201,205,205,205,203,205,205,205,187,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',200,205,205,205,202,205,205,205,188,' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',200,205,205,205,202,205,205,205,188,' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',204,205,205,205,206,205,205,205,206,205,205,205,185,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
   	{186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186,' ',' ',' ',186,' ',' ',' ',186,'#',' ','#',186,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',186},
    {200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,202,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188},
};

int jogadorAtual = 0;
int numeroJogadores = 0;
float valorAposta = 0;
int ordemJogadores[4];
char Jogador[4][10];
int valoresDado[4];
int pecaValida[16] = {0};
float valorPeca = 0;
int pecasFinal[4] = {0};

typedef struct {
    int posicao;
    char cor[20];
    char letra;
    int posicaoInicial;
    int jogador;
} Pecas;

typedef struct {
	int Jogador[4];
	int Peca[16];
}TerminarStruct;


Pecas pecas[16];
					
char CasasMatriz[88];
char CasasFinal[4][6];

void limparBuffer(){
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void limparBuffer2() {
    while (kbhit()) getch();
}

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void linhaCima(){
	
	int i;
	// LINHA DE CIMA DO MENU
    printf("%c", 201);
    for (i = 0; i < 60; i++) {
        printf("%c", 205); // LINHA HORIZONTAL
    }
    printf("%c\n", 187);
}

void linhaBaixo(){
	
	int i;
	// LINHA DE BAIXO DO QUADRADO
    printf("%c", 200);
    for (i = 0; i < 60; i++){
        printf("%c", 205);
    }
    printf("%c\n", 188);
}

void telasMenu(){
	
	system("cls");
	
	linhaCima();    
    //ESPAï¿½O PARA ESCREVER
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
	linhaBaixo();
}

void telaInicial(){
	
	system("cls");	
	
	linhaCima();
    //ESPAï¿½O PARA ESCREVER
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c               Bem Vindo(a) ao Ludo Bet Play!               %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c           Pressione qualquer tecla para continuar          %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
	linhaBaixo();
	gotoxy(51,9);
	getch();
}

void mensagemInicial(){
	
	system("cls");		
	
    linhaCima();
    //ESPAï¿½O PARA ESCREVER
    printf("%c Prezado(a) jogador(a)                                      %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Bem-vindo ao nosso jogo! Antes de comecar a jogar, gostar- %c\n", 186, 186);
    printf("%c iamos de ressaltar a extrema importancia de ler cuidadosa- %c\n", 186, 186);
    printf("%c mente as regras do jogo. Elas foram elaboradas para garan- %c\n", 186, 186);
    printf("%c ir uma experiencia justa, divertida e imersiva para todos  %c\n", 186, 186);
    printf("%c os participantes.                                          %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Divirta-se e boa sorte!                                    %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Atenciosamente,                                            %c\n", 186, 186);
    printf("%c RoyalWin Games                                             %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Precione qualquer tecla para acessar a aba de regras       %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
	linhaBaixo();
	gotoxy(54,14);
	getch();
}

void telaRegras01(){
	
	system("cls");
	linhaCima();    
    //ESPAï¿½O PARA ESCREVER
    printf("%c                           REGRAS                           %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Os jogadores definem o valor da aposta antes do inicio da  %c\n", 186, 186);
    printf("%c partida                                                    %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c O jogador que tirar o numero mais alto no dado comeca a    %c\n", 186, 186);
    printf("%c partida                                                    %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Os jogadores so poderao mover os peoes das casas iniciais  %c\n", 186, 186);
    printf("%c se tirarem 6 no dado.                                      %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Se tirar 6 se tem o direito de jogar novamente.            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                           (1/3)                Proximo (P) %c\n", 186, 186);
	linhaBaixo();
}

void telaRegras02(){
	
	system("cls");
	linhaCima();    
    //ESPAï¿½O PARA ESCREVER
    printf("%c                           REGRAS                           %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Se um peao cair em uma casa que ja possua um peao de outra %c\n", 186, 186);
    printf("%c cor, este que ja estava na casa deve retornar ao comeco    %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Ao cair nas casas com '&' o jogador fica protegido das pe- %c\n", 186, 186);
    printf("%c cas adversarias                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Ao cair nas casas com '#' o jogador deve avancar para a    %c\n", 186, 186);
    printf("%c proxima casa com o caracter '#'                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Ganha o primeiro que dar a volta no tabuleiro e chegar ao  %c\n", 186, 186);
    printf("%c centro dele com as 4 pecas                                 %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Voltar (V)                (2/3)                Proximo (P) %c\n", 186, 186);
	linhaBaixo();
}

void telaRegras03(){
	
	system("cls");
	linhaCima();    
    //ESPAï¿½O PARA ESCREVER
    printf("%c                          PAGAMENTO                         %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c O valor ganho por jogador e determinado pela soma das apo- %c\n", 186, 186);
    printf("%c stas de todos os participantes. Cada peca do tabuleiro te- %c\n", 186, 186);
    printf("%c m seu valor calculado por: Valor da Peca = (Numero de Jog- %c\n", 186, 186);
    printf("%c adores * 4) / Valor da Aposta. O saldo do ganhador e calc- %c\n", 186, 186);
    printf("%c ulado por: Saldo do Vencedor = 4 * Valor da Peca + (Valor  %c\n", 186, 186);
    printf("%c da Peca * ((Numero de Jogadores - 1) * 4 - Pecas chegadas))%c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c Voltar (V)                (3/3)                Proximo (P) %c\n", 186, 186);
	linhaBaixo();
}

void navegarTelaRegras(){
	
	
	int paginaAtualRegras = 1;
	char escolhaRegras;
	
    do {
        if (paginaAtualRegras == 1) {
            telaRegras01();
        } else if (paginaAtualRegras == 2) {
            telaRegras02();
        } else if (paginaAtualRegras == 3) {
			telaRegras03();
		}
        
        escolhaRegras = getch();
        
        if (escolhaRegras == 'P' || escolhaRegras == 'p') {
            if (paginaAtualRegras < 3) {
                paginaAtualRegras++;
            } else {
                break;
            }
        } else if (escolhaRegras == 'V' || escolhaRegras == 'v') {
            if (paginaAtualRegras > 1) {
                paginaAtualRegras--;
            }
        }
    } while (paginaAtualRegras <= 3);
}

void telaNomeJogadores(){
	
	system("cls");
	linhaCima();
    //ESPAï¿½O PARA ESCREVER
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                    Registro de Jogadores                   %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c           Por favor, insira o nome dos jogadores           %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
	linhaBaixo();
}

void selecionarNumeroJogadores(){
	
	int selecionarEscolhaJogadores = 0;
	
	do{
		system("cls");
		
		linhaCima();
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c               Quantos jogadores participarao               %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c                     Opcoes disponiveis                     %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c                        2 Jogadores                         %c\n", 186, 186);
	    printf("%c                        3 Jogadores                         %c\n", 186, 186);
	    printf("%c                        4 Jogadores                         %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c         Por favor, escreva o numero de jogadores:          %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
	    printf("%c                                                            %c\n", 186, 186);
		linhaBaixo();
		
		gotoxy(51,12);
		if (scanf("%i", &selecionarEscolhaJogadores) != 1) {
            limparBuffer();
			}
	
	} while (selecionarEscolhaJogadores < 2 || selecionarEscolhaJogadores > 4);
	
	numeroJogadores = selecionarEscolhaJogadores;
	
	telaNomeJogadores();
	
	int i;
	int y = 7;
	for(i = 0; i < selecionarEscolhaJogadores; i++){
		gotoxy(12, y);
		printf("Jogador %i:", i+1);
		y += 2;
	}
	
	y = 7;
	for(i = 0; i < selecionarEscolhaJogadores; i++){
		gotoxy(22, y);
		scanf("%9s", Jogador[i]);
		y += 2;
	}
}

void selecionarValorAposta(){
	
	int selecionarAposta = 0;
	
	do{
		system("cls");
		
		linhaCima();
		//ESPAï¿½O PARA ESCREVER
		printf("%c                                                            %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		printf("%c                      Valores de Aposta                     %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		printf("%c                       1 - (R$ 5,00)                        %c\n", 186, 186);
		printf("%c                       2 - (R$ 10,00)                       %c\n", 186, 186);
		printf("%c                       3 - (R$ 20,00)                       %c\n", 186, 186);
		printf("%c                       4 - (R$ 50,00)                       %c\n", 186, 186);
		printf("%c                       5 - (R$ 100,00)                      %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		printf("%c           Por favor, escolha uma opcao de aposta:          %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		printf("%c                                                            %c\n", 186, 186);
		linhaBaixo();
		
		gotoxy(51,13);
		if (scanf("%i", &selecionarAposta) != 1) {
            limparBuffer();
			}
			
	} while (selecionarAposta < 1 || selecionarAposta > 5);
	
	if(selecionarAposta == 1){
		valorAposta = 5;
	} else if(selecionarAposta == 2){
		valorAposta = 10;
	} else if(selecionarAposta == 3){
		valorAposta = 20;
	} else if(selecionarAposta == 4){
		valorAposta = 50;
	} else if(selecionarAposta == 5){
		valorAposta = 100;
	}
}

void revisaoPartida(){
	
	system("cls");
	float totalAposta = 0;
	
	totalAposta = numeroJogadores * valorAposta;
	valorPeca = (numeroJogadores * valorAposta) / (numeroJogadores * 4);
	
	linhaCima();    
    //ESPAï¿½O PARA ESCREVER
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c              Numero de jogadores:%i                        \n", 186, numeroJogadores);
    printf("%c              Valor total apostado:R$%.2f                   \n", 186, totalAposta);
    printf("%c              Valor Apostado por jogador:R$%.2f             \n", 186, valorAposta);
    printf("%c              Valor de cada peca:R$%.2f                     \n", 186, valorPeca);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c        Precione qualquer tecla para ir para o jogo         %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
	linhaBaixo();
	//BORDAS DA DIREITA
	int i;
	for(i = 5; i <= 11; i++){
		gotoxy(61,i);
		printf("%c", 186);
	}
	gotoxy(52,11);
	getch();
	gotoxy(23, 13);
	printf("Carregando:");
	for (i = 0; i <= 100; i++) {
		gotoxy(34, 13);
        printf("%d%%", i);
        fflush(stdout);
        Sleep(12);
    }
}

void ranking(){
	int i, y = 6;
	system("cls");
	
	linhaCima();    
    //ESPAï¿½O PARA ESCREVER
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                    Ranking Dos Jogadores                   %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("%c                          %c                                 %c\n", 186, 186, 186);
    printf("%c                          %c Valor Total Apostado [R$%.2f]   \n", 186, 186, valorAposta * numeroJogadores);
    printf("%c                          %c                                 %c\n", 186, 186, 186);
    printf("%c                          %c    Valor de Cada Peca [R$%.2f]   \n", 186, 186, valorPeca);
    printf("%c                          %c                                 %c\n", 186, 186, 186);
    printf("%c                          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 186, 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
    printf("%c                                                            %c\n", 186, 186);
	linhaBaixo();
		
			
		for(i = 7; i <= 10; i++){
			gotoxy(61,i);
			printf("%c", 186);
		}
	
		for(i = 0; i < numeroJogadores; i++){
		gotoxy(6, y);
		printf("%s [R$%.2f]", Jogador[i], pecasFinal[i] * valorPeca);
		y += 2;
	}
	
}

void limparDado(){
	int i;
	for(i=4;i<=10;i++){
	gotoxy(71,i);
	printf("             ");
	}
}

void limparMensagemDado(){
	gotoxy(63, 2);
    printf("                            ");
}

void limparNomeOrdem(){
	int i;
	for(i=11;i<=14;i++){
	gotoxy(64,i);
	printf("                     ");
	}
}

void limparEscolhaPeca(){
	int i;
	for(i = 0; i < 7; i++){
		 gotoxy(63, 16 + i);
		 printf("                              ");
	}
}

void limparNome(){
	gotoxy(75, 1);
	printf("               ");
}

void nomeJogadores(){
	
	int x;
	int i;
	int y;
	
	if(numeroJogadores == 2){
		i = 13;
	} else if(numeroJogadores == 3){
		i = 12;
	} else if(numeroJogadores == 4){
		i = 11;
	}
	
	//ATRIBUIR VALOR DE I PRA Y
	if(i == 13){
		y = 13;
	} else if(i == 12){
		y = 12;
	} else if(i == 11){
		y = 11;
	}
	
	for(x = 0; x < numeroJogadores; x++){
		gotoxy(64,i);
		printf("Jogador   :%s", Jogador[x]);
		i++;
	}
	
	for(x = 1; x <= numeroJogadores; x++){		
		gotoxy(71,y);
		    	
    	if(x == 1){
    		VERMELHO;
		} else if(x == 2){
			VERDE;
		} else if(x == 3){
			AZUL;
		} else if(x == 4){
			AMARELO;
		}
		
        printf("[%i]", x);
        BRANCO;
        
        y++;
	}
}

void desenharDado(int numeroDado){

	int x_dado = 71;
	int y_dado = 4;

    if (numeroDado == 1) {
    	gotoxy(x_dado,4);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
        gotoxy(x_dado,5);
        printf("%c   %c   %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,7);
        printf("%c   %c O %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,8);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,9);
        printf("%c   %c   %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,10);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    } else if (numeroDado == 2) {
    	gotoxy(x_dado,4);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
        gotoxy(x_dado,5);
        printf("%c   %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,7);
        printf("%c   %c   %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,8);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,9);
        printf("%c O %c   %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,10);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    } else if (numeroDado == 3) {
    	gotoxy(x_dado,4);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
        gotoxy(x_dado,5);
        printf("%c   %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,7);
        printf("%c   %c O %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,8);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,9);
        printf("%c O %c   %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,10);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    } else if (numeroDado == 4) {
    	gotoxy(x_dado,4);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
        gotoxy(x_dado,5);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,7);
        printf("%c   %c   %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,8);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,9);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,10);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    } else if (numeroDado == 5) {
    	gotoxy(x_dado,4);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
        gotoxy(x_dado,5);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,7);
        printf("%c   %c O %c   %c", 186, 186, 186, 186);
        gotoxy(x_dado,8);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,9);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,10);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    } else if (numeroDado == 6) {
    	gotoxy(x_dado,4);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
        gotoxy(x_dado,5);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,7);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,8);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
        gotoxy(x_dado,9);
        printf("%c O %c   %c O %c", 186, 186, 186, 186);
        gotoxy(x_dado,10);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
    }
}

void mensagemOrdem(){
	gotoxy(63, 8);
	printf("A ordem de jogada foi definida");
	Sleep(1500);
	gotoxy(63, 8);
	printf("                              ");
}

void trocaInt(int *a, int *b) {
    int temp = *a;		
    *a = *b;
    *b = temp;
}		

void bubbleSort(int valoresDado[], int ordemJogadores[], int n) { //ORDENAR
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (valoresDado[j] < valoresDado[j + 1]) {
                trocaInt(&valoresDado[j], &valoresDado[j + 1]);
                trocaInt(&ordemJogadores[j], &ordemJogadores[j + 1]);
            }
        }
    }
}

void mensagemOrdemInicial(){
	
	gotoxy(64, 8);
	printf("A ordem de jogada sera feita");
	Sleep(1500);
	gotoxy(63, 8);
	printf("                              ");
}

void capturar_peca(int num_peca) {
	
    int idx = num_peca;
    if (idx >= 0 && idx < 16) {
        CasasMatriz[72 + idx] = pecas[idx].letra;
    }
    
	pecaValida[idx] = 0;
    CasasMatriz[72 + idx] = pecas[idx].letra;
    pecas[idx].posicaoInicial = 0;
}

int posicao_ocupada_por_adversario(int posicao, int num_peca) {
	int idx = num_peca - 1;
	int i;
    for (i = 0; i < 16; i++) {
        if (i != idx && pecas[i].posicao == posicao && pecas[i].jogador != pecas[idx].jogador) {
            return 1;
        }
    }
    return 0;
}

int posicao_ocupada_por_amigo(int posicao , int num_peca){
	int idx = num_peca - 1;
	int i;
    for (i = 0; i < 16; i++) {
        if (i != idx && pecas[i].posicao == posicao && pecas[i].jogador == pecas[idx].jogador) {
            return 1;
        }
    }
    return 0;
}

int encontrar_peca_na_posicao(int posicao) {
	int i;
    for (i = 0; i < 16; i++) {
        if (pecas[i].posicao == posicao) {
            return i;
        }
    }
    return -1;
}

void moverPecas(int num_peca, int movimento) {
	
    int idx = num_peca - 1;
    char letras[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    int jogador = idx / 4 + 1;
    pecas[idx].letra = letras[idx];
    pecas[idx].jogador = jogador;
    
    int entradaCaminhoVitoria[4] = {51, 12, 38, 25};

    if (pecas[idx].posicaoInicial == 0) {
        pecas[idx].letra = letras[idx];

        if (num_peca <= 4) {
            pecas[idx].posicao = 1;
            CasasMatriz[1] = pecas[idx].letra;
            CasasMatriz[72 + idx] = ' ';
        } else if (num_peca <= 8) {
            pecas[idx].posicao = 14;
            CasasMatriz[14] = pecas[idx].letra;
            CasasMatriz[72 + idx] = ' ';
        } else if (num_peca <= 12) {
            pecas[idx].posicao = 40;
            CasasMatriz[40] = pecas[idx].letra;
            CasasMatriz[72 + idx] = ' ';
        } else {
            pecas[idx].posicao = 27;
            CasasMatriz[27] = pecas[idx].letra;
            CasasMatriz[72 + idx] = ' ';
        }
        pecas[idx].posicaoInicial = 1;
    } else {
        int jogadorIdx = idx / 4;
		
		if (pecas[idx].posicaoInicial == 3){
        	gotoxy(65,18);
        	printf("Peca %c ja chegou ao final", pecas[idx].letra);
        	Sleep(1500);
		}
		
        if (pecas[idx].posicaoInicial == 1) { // Verifica se a peça está no tabuleiro
            CasasMatriz[pecas[idx].posicao] = ' '; // Remove a peça da posição atual na matriz de casas
            int novaPosicao = pecas[idx].posicao + movimento; // Calcula a nova posição da peça após o movimento

            if (!(num_peca <= 4 && novaPosicao == 50) && !(num_peca > 4 && num_peca <= 8 && novaPosicao == 11) &&
                !(num_peca > 8 && num_peca <= 12 && novaPosicao == 37) && !(num_peca > 12 && novaPosicao == 24)) {
                if (novaPosicao == 11 || novaPosicao == 24 || novaPosicao == 37 || novaPosicao == 50) {
                    novaPosicao += 13;
                }
            }
			
			if (posicao_ocupada_por_adversario(novaPosicao, num_peca)) {
				
			    int peca_adversaria = encontrar_peca_na_posicao(novaPosicao);
			    
			    capturar_peca(peca_adversaria);
			    
			    gotoxy(68, 18);
			    printf("Peca %c foi capturada", pecas[peca_adversaria].letra);
			    Sleep(1500);
			} 
					
            if (pecas[idx].posicao <= entradaCaminhoVitoria[jogadorIdx] && novaPosicao > entradaCaminhoVitoria[jogadorIdx]) {
                // Se a peça está se movendo para o caminho da vitória
                CasasMatriz[pecas[idx].posicao] = ' '; // Limpa a posição anterior na matriz de casas
                pecas[idx].posicao = novaPosicao - entradaCaminhoVitoria[jogadorIdx] - 1; // Calcula a nova posição dentro do caminho da vitória
                pecas[idx].posicaoInicial = 2; // Marca a peça como no caminho da vitória
                CasasFinal[jogadorIdx][pecas[idx].posicao] = pecas[idx].letra;
                
            } else if (novaPosicao > 51) {
                novaPosicao -= 52; // Ajusta a posição caso a peça ultrapasse o final do tabuleiro
                pecas[idx].posicao = novaPosicao;
                CasasMatriz[pecas[idx].posicao] = pecas[idx].letra; // Atualiza a matriz de casas com a nova posição da peça
            } else {
                pecas[idx].posicao = novaPosicao; // Atualiza a posição da peça
                CasasMatriz[pecas[idx].posicao] = pecas[idx].letra; // Atualiza a matriz de casas com a nova posição da peça
            }
        } else if (pecas[idx].posicaoInicial == 2) { // Verifica se a peça está no caminho da vitória
            CasasFinal[jogadorIdx][pecas[idx].posicao] = ' '; // Remove a peça da posição atual na matriz final
            int novaPosicao = pecas[idx].posicao + movimento; // Calcula a nova posição da peça após o movimento

            if (novaPosicao > 5) {
            	gotoxy(67,18);
            	printf("Tirou mais do que devia");
                novaPosicao -= movimento; // Ajusta a posição caso a peça ultrapasse o final do caminho da vitória
                CasasFinal[jogadorIdx][pecas[idx].posicao] = pecas[idx].letra; // Atualiza a matriz final com a nova posição da peça
                Sleep(1500);
            } else {
                pecas[idx].posicao = novaPosicao; // Atualiza a posição da peça
                CasasFinal[jogadorIdx][pecas[idx].posicao] = pecas[idx].letra; // Atualiza a matriz final com a nova posição da peça

                if (novaPosicao == 5) {
                	int jogadorIdx = idx / 4;
                	gotoxy(67,18);
                    printf("Peca %c chegou ao final", pecas[idx].letra);
                    pecas[idx].posicaoInicial = 3;
                    Sleep(1500);
                    pecasFinal[jogadorIdx]++;
                }
            }
        }
    }
}

void mapearMatriz() {
	
	int i;

    Tabuleiro[5][10] = CasasMatriz[72];
    Tabuleiro[5][14] = CasasMatriz[73];
    Tabuleiro[7][10] = CasasMatriz[74];
    Tabuleiro[7][14] = CasasMatriz[75];
    Tabuleiro[5][46] = CasasMatriz[76];
    Tabuleiro[5][50] = CasasMatriz[77];
    Tabuleiro[7][46] = CasasMatriz[78];
    Tabuleiro[7][50] = CasasMatriz[79];
    Tabuleiro[23][10] = CasasMatriz[80];
    Tabuleiro[23][14] = CasasMatriz[81];
    Tabuleiro[25][10] = CasasMatriz[82];
    Tabuleiro[25][14] = CasasMatriz[83];
    Tabuleiro[23][46] = CasasMatriz[84];
    Tabuleiro[23][50] = CasasMatriz[85];
    Tabuleiro[25][46] = CasasMatriz[86];
    Tabuleiro[25][50] = CasasMatriz[87];
    
    Tabuleiro[13][2] = CasasMatriz[0];
    Tabuleiro[13][6] = CasasMatriz[1];
    Tabuleiro[13][10] = CasasMatriz[2];
    Tabuleiro[13][14] = CasasMatriz[3];
    Tabuleiro[13][18] = CasasMatriz[4];
    Tabuleiro[13][22] = CasasMatriz[5];
    Tabuleiro[11][26] = CasasMatriz[6];
    Tabuleiro[9][26] = CasasMatriz[7];
    Tabuleiro[7][26] = CasasMatriz[8];
    Tabuleiro[5][26] = CasasMatriz[9];
    Tabuleiro[3][26] = CasasMatriz[10];
    Tabuleiro[1][26] = CasasMatriz[11];
    Tabuleiro[1][30] = CasasMatriz[12];
    Tabuleiro[1][34] = CasasMatriz[13];
    Tabuleiro[3][34] = CasasMatriz[14];
    Tabuleiro[5][34] = CasasMatriz[15];
    Tabuleiro[7][34] = CasasMatriz[16];
    Tabuleiro[9][34] = CasasMatriz[17];
    Tabuleiro[11][34] = CasasMatriz[18];
    Tabuleiro[13][38] = CasasMatriz[19];
    Tabuleiro[13][42] = CasasMatriz[20];
    Tabuleiro[13][46] = CasasMatriz[21];
    Tabuleiro[13][50] = CasasMatriz[22];
    Tabuleiro[13][54] = CasasMatriz[23];
    Tabuleiro[13][58] = CasasMatriz[24];
    Tabuleiro[15][58] = CasasMatriz[25];
    Tabuleiro[17][58] = CasasMatriz[26];
    Tabuleiro[17][54] = CasasMatriz[27];
    Tabuleiro[17][50] = CasasMatriz[28];
    Tabuleiro[17][46] = CasasMatriz[29];
    Tabuleiro[17][42] = CasasMatriz[30];
    Tabuleiro[17][38] = CasasMatriz[31];
    Tabuleiro[19][34] = CasasMatriz[32];
    Tabuleiro[21][34] = CasasMatriz[33];
    Tabuleiro[23][34] = CasasMatriz[34];
    Tabuleiro[25][34] = CasasMatriz[35];
    Tabuleiro[27][34] = CasasMatriz[36];
    Tabuleiro[29][34] = CasasMatriz[37];
    Tabuleiro[29][30] = CasasMatriz[38];
    Tabuleiro[29][26] = CasasMatriz[39];
    Tabuleiro[27][26] = CasasMatriz[40];
    Tabuleiro[25][26] = CasasMatriz[41];
    Tabuleiro[23][26] = CasasMatriz[42];
    Tabuleiro[21][26] = CasasMatriz[43];
    Tabuleiro[19][26] = CasasMatriz[44];
    Tabuleiro[17][22] = CasasMatriz[45];
    Tabuleiro[17][18] = CasasMatriz[46];
    Tabuleiro[17][14] = CasasMatriz[47];
    Tabuleiro[17][10] = CasasMatriz[48];
    Tabuleiro[17][6] = CasasMatriz[49];
    Tabuleiro[17][2] = CasasMatriz[50];
    Tabuleiro[15][2] = CasasMatriz[51];
    
    // CASAS FINAL JOGADOR 1
    for(i = 0; i < 6; i++){
    	Tabuleiro[15][6 + i * 4] = CasasFinal[0][i];
	}
	
	// CASAS FINAL JOGADOR 2
	for(i = 0; i < 6; i++){
		Tabuleiro[3 + i * 2][30] = CasasFinal[1][i];
	}
		
	// CASAS FINAL JOGADOR 3
	for(i = 0; i < 6; i++){
		Tabuleiro[27 - i * 2][30] = CasasFinal[2][i];
	}
	
	// CASAS FINAL JOGADOR 4
	for(i = 0; i < 6; i++){
		Tabuleiro[15][54 - i * 4] = CasasFinal[3][i];
	}
}

void imprimirTabuleiro(){
	mapearMatriz();
    int i, j;
    
	for (i = 0; i < LINHAS; i++) {
        for (j = 0; j < COLUNAS; j++){
        	//PINTAS AS PEÇAS DO TABULEIRO
	        if((Tabuleiro[i][j] == 'A') || (Tabuleiro[i][j] == 'B') || (Tabuleiro[i][j] == 'C') || (Tabuleiro[i][j] == 'D')){
	       		VERMELHO;
			} else if((Tabuleiro[i][j] == 'E') || (Tabuleiro[i][j] == 'F') || (Tabuleiro[i][j] == 'G') || (Tabuleiro[i][j] == 'H')){
        		VERDE;
			} else if((Tabuleiro[i][j] == 'I') || (Tabuleiro[i][j] == 'J') || (Tabuleiro[i][j] == 'K') || (Tabuleiro[i][j] == 'L')){
        		AZUL;
			} else if((Tabuleiro[i][j] == 'M') || (Tabuleiro[i][j] == 'N') || (Tabuleiro[i][j] == 'O') || (Tabuleiro[i][j] == 'P')){
        		AMARELO;
			}
			
        	//CONDIÇÃO PRA PINTAR OS QUADRADOS DO TABULEIRO
            else if((i == 4 && j >= 8 && j <= 16)  || (i >= 5 && j == 8 && i <= 8) || (i == 8 && j >= 9 && j <= 16) || (i >= 5 && j == 16 && i <= 8) || (i == 6 && j >= 9 && j <= 16) || (i >= 5 && j == 12 && i <= 7)){
    			VERMELHO;
			} else if((i == 22 && j >= 8 && j <= 16) || (i >= 22 && j == 8 && i <= 26) || (i == 26 && j >= 9 && j <= 16) || (i >= 22 && j == 16 && i <= 26) || (i == 24 && j >= 9 && j <= 16) || (i >= 23 && j == 12 && i <= 25)){
    			AZUL;
			} else if((i == 4 && j >= 44 && j <= 52) || (i >= 5 && j == 44 && i <= 8) || (i == 8 && j >= 45 && j <= 52) || (i >= 5 && j == 52 && i <= 7) || (i == 6 && j >= 45 && j <= 51) || (i >= 5 && j == 48 && i <= 7)){
    			VERDE;
			} else if((i == 22 && j >= 44 && j <= 52) || (i >= 23 && j == 44 && i <= 26) || (i == 26 && j >= 45 && j <= 52) || (i >= 23 && j == 52 && i <= 26) || (i == 24 && j >= 45 && j <= 52) || (i >= 23 && j == 48 && i <= 25)){
    			AMARELO;
			}
			
			//PINTAR AS EXTREMIDADES
			else if((i >= 0 && j == 0 && i <= 6) || (i == 0 && j >= 0 && j <= 12)){
				VERMELHO;
			} else if((i == 30 && j >= 0 && j <= 12) || (i >= 24 && j == 0 && i <= 30)){
				AZUL;
			} else if((i >= 0 && j == 60 && i <= 6) || (i == 0 && j >= 48 && j <= 60)){
				VERDE;
			} else if((i == 30 && j >= 48 && j <= 60) || (i >= 24 && j == 60 && i <= 30)){
				AMARELO;
			}
			
			//PINTAR AS DIREÇÃO DO TABULERO
			else if((i == 14 && j >= 5 && j <= 7) || (i == 14 && j >= 9 && j <= 11) || (i == 14 && j >= 13 && j <= 15) || (i == 14 && j >= 17 && j <= 19) || (i == 14 && j >= 21 && j <= 23) || (i == 16 && j >= 5 && j <= 7) || (i == 16 && j >= 9 && j <= 11) || (i == 16 && j >= 13 && j <= 15) || (i == 16 && j >= 17 && j <= 19) || (i == 16 && j >= 21 && j <= 23) || (i == 12 && j >= 5 && j <= 7) || (i == 13 && j == 4) || (i == 15 && j == 4)|| (i == 13 && j == 8) || (i == 15 && j == 5) || (i == 15 && j == 8) || (i == 15 && j == 12) || (i == 15 && j == 16) || (i == 15 && j == 20) || (i == 15 && j == 24)){
				VERMELHO;
			} else if((i == 2 && j >= 29 && j <= 31) || (i == 4 && j >= 29 && j <= 31) || (i == 6 && j >= 29 && j <= 31) || (i == 8 && j >= 29 && j <= 31) || (i == 10 && j >= 29 && j <= 31) || (i == 12 && j >= 29 && j <= 31) || (i == 2 && j >= 33 && j <= 35) || (i == 4 && j >= 33 && j <= 35) || (i == 3 && j == 28) || (i == 3 && j == 32) || (i == 3 && j == 36) || (i == 5 && j == 28) || (i == 5 && j == 32) || (i == 7 && j == 28) || (i == 7 && j == 32) || (i == 9 && j == 28) || (i == 9 && j == 32) || (i == 11 && j == 28) || (i == 11 && j == 32)){
				VERDE;
			} else if((i == 14 && j >= 37 && j <= 39) || (i == 14 && j >= 41 && j <= 43) || (i == 14 && j >= 45 && j <= 47) || (i == 14 && j >= 49 && j <= 51) || (i == 14 && j >= 53 && j <= 55) || (i == 16 && j >= 37 && j <= 39) || (i == 16 && j >= 41 && j <= 43) || (i == 16 && j >= 45 && j <= 47) || (i == 16 && j >= 49 && j <= 51) || (i == 16 && j >= 53 && j <= 55) || (i == 18 && j >= 53 && j <= 55) || (i == 15 && j == 36) || (i == 15 && j == 40) || (i == 15 && j == 44) || (i == 15 && j == 48) || (i == 15 && j == 52) || (i == 15 && j == 56) || (i == 17 && j == 52) || (i == 17 && j == 56)){
				AMARELO;
			} else if((i == 18 && j >= 29 && j <= 31) || (i == 20 && j >= 29 && j <= 31) || (i == 22 && j >= 29 && j <= 31) || (i == 24 && j >= 29 && j <= 31) || (i == 26 && j >= 29 && j <= 31) || (i == 28 && j >= 29 && j <= 31) || (i == 28 && j >= 25 && j <= 27) || (i == 26 && j >= 25 && j <= 27) || (i == 19 && j == 28) || (i == 19 && j == 32) || (i == 21 && j == 28) || (i == 21 && j == 32) || (i == 23 && j == 28) || (i == 23 && j == 32) || (i == 25 && j == 28) || (i == 25 && j == 32) || (i == 27 && j == 28) || (i == 27 && j == 32) || (i == 27 && j == 24)){
				AZUL;
			}
			gotoxy(j, i);
			printf("%c", Tabuleiro[i][j]);
			BRANCO;
        }
        printf("\n");
    }
}

void telaTabuleiro(){
		int h, v;
    	gotoxy(62, 0);
    	printf("%c", 201);
    	for(v = 0; v < 29; v++){
    		gotoxy(62,v+1);
    		printf("%c", 186);
		}
		
		gotoxy(62, 23);
		BRANCO;
		printf("%c", 204);
		for(h = 0; h < 30; h++){
		printf("%c", 205);
		}
		
		gotoxy(62, 15);
		printf("%c", 204);
		for(h = 0; h < 30; h++){
		printf("%c", 205);
		}
		
		//LINHA DE CIMA
		gotoxy(62,30);
		printf("%c", 200);
		
		for(v = 0; v < 30; v++){
			gotoxy(63+v,0);
			printf("%c", 205);
		}
		
		//LINHA DA DIREITA
		gotoxy(93,0);
    	printf("%c", 187);
    	
    	for(v = 0; v < 29; v++){
    		gotoxy(93,v+1);
    		printf("%c", 186);
    		
    		gotoxy(93, 15);
			printf("%c", 185);
			
			gotoxy(93, 23);
			printf("%c", 185);	
		}
		
		//LINHA DE BAIXO
		gotoxy(93,30);
		printf("%c", 188);
		
		for(v = 0; v < 30; v++){
			gotoxy(63+v,30);
			printf("%c", 205);
		}
}

void rankingEregras(){
	
	gotoxy(68,25);
	printf("R - Consultar Regras");
	gotoxy(68,27);
	printf("T - Consultar Ranking");
}

void proximaVez() {
    jogadorAtual = (jogadorAtual + 1) % numeroJogadores;
}

void imprimirOrdem(int ordemJogadores[], char Jogador[][10], int n){
	
	int i, x, y;	

	if(numeroJogadores == 2){
		x = 13;
	} else if(numeroJogadores == 3){
		x = 12;
	} else if(numeroJogadores == 4){
		x = 11;
	}
	//ATRIBUIR VALOR DE I PRA Y
	if(x == 13){
		y = 13;
	} else if(x == 12){
		y = 12;
	} else if(x == 11){
		y = 11;
	}
		for (i = 0; i < n; i++){
		gotoxy(64, x + i);
        printf("Jogador   :%s", Jogador[ordemJogadores[i]]);
    }
    
    for(i = 0; i < n; i++){		
		gotoxy(71,y + i);
		    	
    	if(ordemJogadores[i] == 0){
    		VERMELHO;
		} else if(ordemJogadores[i] == 1){
			VERDE;
		} else if(ordemJogadores[i] == 2){
			AZUL;
		} else if(ordemJogadores[i] == 3){
			AMARELO;
		}
        printf("[%i]", ordemJogadores[i] + 1);
        BRANCO;
	}
}

void trocaString(char a[], char b[]) {
    char temp[10];
    strcpy(temp, a);
    strcpy(a, b);			
    strcpy(b, temp);
}	

void jogarDadoInicial(){
    
	int i;
    char jogarDado;
    mensagemOrdemInicial();
    
    for (i = 0; i < numeroJogadores; i++) {
	
		int numeroDado = (rand() % 6) + 1;
		
    	nomeJogadores(); //MOSTRAR O NOME DOS JOGADORES
    	    
        limparNome();
        gotoxy(75, 1);
        
        if(i == 0){
	    	VERMELHO;
		} else if(i == 1){
			VERDE;
		} else if(i == 2){
			AZUL;
		} else if(i == 3){
			AMARELO;
		}
		
        printf("%s", Jogador[i]);
        BRANCO;
        
        gotoxy(65, 2);
        printf("Aperte J para Jogar o Dado");
        
        do {
            jogarDado = getch();
            
            if (jogarDado != 'J' && jogarDado != 'j') {
                gotoxy(70, 3);
                printf("Tecla invalida!");
            } else {
                gotoxy(70, 3);
                printf("                      ");
            }
        } while (jogarDado != 'J' && jogarDado != 'j');

        desenharDado(numeroDado);
        
        Sleep(1000);
        limparDado();
        
        valoresDado[i] = numeroDado;
        ordemJogadores[i] = i;
    }
    limparMensagemDado(); //LIMPAR MENSAGEM DO DADO ANTEZ DE MOSTRAR QUE A ORDEM FOI FINALIZADA
    limparNome(); //LIMPAR O NOME COM A MESMA FINALIDADE DA VOID DE CIMA
    limparNomeOrdem(); //LIMPAR LISTA DE JOGADORES ANTES DE ORDENAR
    mensagemOrdem(); //EXIBIR QUE A ORDEM FOI FEITA
    bubbleSort(valoresDado, ordemJogadores, numeroJogadores); //ORDENAR OS JOGADORES COM BASE NO NUMERO DO DADO
}

void iniciarPartida() {

    int i;
    int inicio, fim;
    int escolhaPeca;
    char jogarDado;
    int temPecaParaMover = 0;
    char pecasExibir[16] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    
    //INICIALIZAR PEÇAS DA MATRIZ
	for (i = 0; i < 16; i++) {
	       pecas[i].posicao = CasasMatriz[72 + i];
	       pecas[i].posicaoInicial = 0;
	}
    
    while (1) {

        limparNome();
	    gotoxy(75, 1);
	    
	    if(jogadorAtual[ordemJogadores] == 0){
	    	VERMELHO;
		} else if(jogadorAtual[ordemJogadores] == 1){
			VERDE;
		} else if(jogadorAtual[ordemJogadores] == 2){
			AZUL;
		} else if(jogadorAtual[ordemJogadores] == 3){
			AMARELO;
		}
		
        printf("%s", Jogador[ordemJogadores[jogadorAtual]]);
        
		BRANCO;
        gotoxy(65, 2);
        printf("Aperte J para Jogar o Dado");
    
        do {
            jogarDado = getch();
            
             if (jogarDado == 'R' || jogarDado == 'r') {
             	
                navegarTelaRegras();
                limparBuffer2();
                system("cls");
                imprimirTabuleiro();
                telaTabuleiro();
                imprimirOrdem(ordemJogadores, Jogador, numeroJogadores);
                rankingEregras();
                
                gotoxy(75, 1);
			    if(jogadorAtual[ordemJogadores] == 0){
			    	VERMELHO;
				} else if(jogadorAtual[ordemJogadores] == 1){
					VERDE;
				} else if(jogadorAtual[ordemJogadores] == 2){
					AZUL;
				} else if(jogadorAtual[ordemJogadores] == 3){
					AMARELO;
				}
				
		        printf("%s", Jogador[ordemJogadores[jogadorAtual]]);
		        
				BRANCO;
		        gotoxy(65, 2);
		        printf("Aperte J para Jogar o Dado");
                continue;
            }
            
            if(jogarDado == 'T' || jogarDado == 't'){
            	
            	ranking();
            	getch();
                limparBuffer2();
                system("cls");
                imprimirTabuleiro();
                telaTabuleiro();
                imprimirOrdem(ordemJogadores, Jogador, numeroJogadores);
                rankingEregras();
                
                gotoxy(75, 1);
			    if(jogadorAtual[ordemJogadores] == 0){
			    	VERMELHO;
				} else if(jogadorAtual[ordemJogadores] == 1){
					VERDE;
				} else if(jogadorAtual[ordemJogadores] == 2){
					AZUL;
				} else if(jogadorAtual[ordemJogadores] == 3){
					AMARELO;
				}
				
		        printf("%s", Jogador[ordemJogadores[jogadorAtual]]);
		        
				BRANCO;
		        gotoxy(65, 2);
		        printf("Aperte J para Jogar o Dado");
                continue;
            }
            
            if (jogarDado != 'J' && jogarDado != 'j') {
                gotoxy(70, 3);
                printf("Tecla invalida!");
            } else {
                gotoxy(70, 3);
                printf("                      ");
            }
        } while (jogarDado != 'J' && jogarDado != 'j');

        int numeroDado = (rand() % 6) + 1;
        desenharDado(numeroDado);

        Sleep(1000);
        
		if (numeroDado == 6) {
		    gotoxy(63, 16);
		    printf("Qual peca deseja movimentar:");
		
		    if (jogadorAtual[ordemJogadores] == 0) {
		        inicio = 0;
		        fim = 3;
		    } else if (jogadorAtual[ordemJogadores] == 1) {
		        inicio = 4;
		        fim = 7;
		    } else if (jogadorAtual[ordemJogadores] == 2) {
		        inicio = 8;
		        fim = 11;
		    } else if (jogadorAtual[ordemJogadores] == 3) {
		        inicio = 12;
		        fim = 15;
		    }
		
		    int jogador = jogadorAtual[ordemJogadores];
		
		   	gotoxy(63, 17);
		    for (i = inicio; i <= fim; i++) {
		        if (pecas[i].posicaoInicial != 3 && (!(pecas[i].posicaoInicial == 2 && pecas[i].posicao + numeroDado > 5))) {
		            printf("(%d=%c) ", i + 1, pecasExibir[i]);
		        }
			}
		    gotoxy(91, 16);
		    scanf("%i", &escolhaPeca);
		
		    int inicio = jogador * 4 + 1;
		    int fim = inicio + 3;
		
		    if (escolhaPeca >= inicio && escolhaPeca <= fim) {
		        moverPecas(escolhaPeca, numeroDado);
		        pecaValida[escolhaPeca - 1] = 1;
		        imprimirTabuleiro();
		        limparEscolhaPeca();
		        limparDado();
		        continue;
		    } else {
		        gotoxy(64, 18);
		        printf("Peca invalida! Perdeu a vez");
		        Sleep(1000);
		    }
		    limparBuffer();
		} else {
        	
            for (i = jogadorAtual[ordemJogadores] * 4; i < jogadorAtual[ordemJogadores] * 4 + 4; i++) {
                if (pecaValida[i] == 1 && pecas[i].posicaoInicial != 3 && (!(pecas[i].posicaoInicial == 2 && pecas[i].posicao + numeroDado > 5))) {
                    temPecaParaMover = 1;
                    break;
                }
            }
		} if (temPecaParaMover){
	            gotoxy(63, 16);
	            printf("Qual peca deseja movimentar:");
	            
			    if (jogadorAtual[ordemJogadores] == 0) {
			        inicio = 0;
			        fim = 3;
			    } else if (jogadorAtual[ordemJogadores] == 1) {
			        inicio = 4;
			        fim = 7;
			    } else if (jogadorAtual[ordemJogadores] == 2) {
			        inicio = 8;
			        fim = 11;
			    } else if (jogadorAtual[ordemJogadores] == 3) {
			        inicio = 12;
			        fim = 15;
			    }
			    gotoxy(63, 17);
			    for (i = inicio; i <= fim; i++) {
			        if (pecaValida[i] == 1 && pecas[i].posicaoInicial != 3 && (!(pecas[i].posicaoInicial == 2 && pecas[i].posicao + numeroDado > 5))) {
			            printf("(%d=%c) ", i + 1, pecasExibir[i]);
			        }
			    }
			
				gotoxy(91, 16);
	            scanf("%i", &escolhaPeca);
			
            if ((escolhaPeca > 0 && escolhaPeca <= 4 && pecaValida[escolhaPeca - 1] == 1 && jogadorAtual[ordemJogadores] == 0) ||
                (escolhaPeca > 4 && escolhaPeca <= 8 && pecaValida[escolhaPeca - 1] == 1 && jogadorAtual[ordemJogadores] == 1) ||
                (escolhaPeca > 8 && escolhaPeca <= 12 && pecaValida[escolhaPeca - 1] == 1 && jogadorAtual[ordemJogadores] == 2) ||
                (escolhaPeca > 12 && escolhaPeca <= 16 && pecaValida[escolhaPeca - 1] == 1 && jogadorAtual[ordemJogadores] == 3)) {
                moverPecas(escolhaPeca, numeroDado);
            } else {
            	gotoxy(65, 18);
                printf("Impossivel mover essa peca");
                Sleep(1000);
            }
            temPecaParaMover = 0; //VOLTAR A VARIAVEL PARA 0 NOVAMENTE
            limparBuffer();
		}
		system("cls");
        imprimirTabuleiro();
        telaTabuleiro();
        imprimirOrdem(ordemJogadores, Jogador, numeroJogadores);
        limparEscolhaPeca();
        limparDado();
        rankingEregras();
        jogadorAtual = (jogadorAtual + 1) % numeroJogadores;
    }
}

main(){
	
    CasasMatriz[72] = 'A';
    CasasMatriz[73] = 'B';
    CasasMatriz[74] = 'C';
    CasasMatriz[75] = 'D';
    CasasMatriz[76] = 'E';
    CasasMatriz[77] = 'F';
    CasasMatriz[78] = 'G';
    CasasMatriz[79] = 'H';
    CasasMatriz[80] = 'I';
    CasasMatriz[81] = 'J';
    CasasMatriz[82] = 'K';
    CasasMatriz[83] = 'L';
    CasasMatriz[84] = 'M';
    CasasMatriz[85] = 'N';
    CasasMatriz[86] = 'O';
    CasasMatriz[87] = 'P';
    
	telaInicial();
	mensagemInicial();
	navegarTelaRegras();
	selecionarNumeroJogadores();
	selecionarValorAposta();
	revisaoPartida();
	system("cls");	
	imprimirTabuleiro();
	rankingEregras();
    telaTabuleiro(); //EXIBIR MENU DO LADO DO TABULEIRO
    srand(time(NULL));
    jogarDadoInicial(); //JOGAR O DADO PELA PRIMEIRA VEZ (FAZ A ORDEM)
	imprimirOrdem(ordemJogadores, Jogador, numeroJogadores); //EXIBIR OS JOGADORES ORDENADOS
	iniciarPartida();
}
