#include <stdio.h> //Bibliotecas utilizadas no projeto. Projeto desenvolvido utilizando Allegro.
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <math.h>

#define KEY_SEEN     1//Constantes utilizadas no projeto.
#define KEY_RELEASED 2
#define N_LINHAS 200
#define N_COLUNAS 200
#define ESCALA 5

typedef struct//Estrutura obj, base do jogo. 'obj' serve como um molde para cada elemento do jogo. Ou seja, em determinado ponto da execução, a matriz de caracteres é convertida em uma matriz de obj.
{
        int isAlive;
}obj;

void inicializa(bool teste, const char *descricao);

void drawMap(obj objImage[N_LINHAS][N_COLUNAS]);

void updateCell(obj objImage[N_LINHAS][N_COLUNAS]);

void loadMap(obj objImage[N_LINHAS][N_COLUNAS]);
