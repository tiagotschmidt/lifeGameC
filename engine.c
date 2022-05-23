#include "engine.h"

void inicializa(bool teste, const char *descricao)//Função de inicialização geral, para os adicionais do Allegro.
{
    if(teste) return;

    printf("Não foi possivel inicializar %s\n", descricao);
    exit(1);
}

void loadMap(obj objImage[N_LINHAS][N_COLUNAS])//Função loadMap, converte uma matriz de caracteres em uma matriz de obj.
{
    int i,j;
    int randomInt;
    srand(time(NULL));
    for(i=0;i<N_COLUNAS;i++)
    {
        for(j=0;j<N_LINHAS;j++)
        {
          randomInt = rand() % 100;
          if(randomInt > 96){
            objImage[j][i].isAlive = 1;
          }else{
            objImage[j][i].isAlive = 0;
          }
        }
    }
}

void updateCell(obj objImage[N_LINHAS][N_COLUNAS]){
    int i,j;
    int nearbySum = 0;
    for(i=0;i<N_COLUNAS;i++){
        for(j=0;j<N_LINHAS;j++){
          nearbySum = 0;
          if(i-1 >= 0){
            //printf("\nCélula:%d",objImage[j][i-1].isAlive);
            if(objImage[j][i-1].isAlive){
              nearbySum++;
            }
          }
          if(j-1 >= 0){
            //printf("\nCélula:%d",objImage[j-1][i].isAlive);
            if(objImage[j-1][i].isAlive){
              nearbySum++;
            }
          }
          if(i+1 < N_COLUNAS){
            //printf("\nCélula:%d",objImage[j][i+1].isAlive);
            if(objImage[j][i+1].isAlive){
              nearbySum++;
            }
          }
          if(j+1 < N_LINHAS){
            //printf("\nCélula:%d",objImage[j+1][i].isAlive);
            if(objImage[j+1][i].isAlive){
              nearbySum++;
            }
          }

          if((i-1 >= 0) && (i-1 >= 0)){
            //printf("\nCélula:%d",objImage[j][i-1].isAlive);
            if(objImage[j-1][i-1].isAlive){
              nearbySum++;
            }
          }
          if((i+1 < N_COLUNAS) && (j-1 >= 0)){
            //printf("\nCélula:%d",objImage[j-1][i].isAlive);
            if(objImage[j-1][i+1].isAlive){
              nearbySum++;
            }
          }
          if((j+1 < N_LINHAS) && (i-1 >= 0)){
            //printf("\nCélula:%d",objImage[j][i+1].isAlive);
            if(objImage[j+1][i-1].isAlive){
              nearbySum++;
            }
          }
          if((j+1 < N_LINHAS) && (i+1 < N_COLUNAS)){
            //printf("\nCélula:%d",objImage[j+1][i].isAlive);
            if(objImage[j+1][i+1].isAlive){
              nearbySum++;
            }
          }

          //printf("\nSoma:%d",nearbySum);

          if(objImage[j][i].isAlive){
            if((nearbySum == 2) || (nearbySum == 3)){
              objImage[j][i].isAlive = 1;
            }else if(nearbySum < 2){
              objImage[j][i].isAlive = 0;
            }else if(nearbySum > 3){
              objImage[j][i].isAlive = 0;
            }
          }else{
            if(nearbySum == 3){
              objImage[j][i].isAlive = 1;
            }
          }
        }
    }
}

void drawMap(obj objImage[N_LINHAS][N_COLUNAS])//Função drawMap, na verdade, é um apanhado dos recursos visuais da Allegro. Em geral, estão aqui todos os possíveis. Ou seja, os outros desenhos da Allegro não foram possíveis de ser retirado da main.
{
    int i,j;

    for(i=0;i<N_COLUNAS;i++){
        for(j=0;j<N_LINHAS;j++){
            if(objImage[j][i].isAlive){
                al_draw_filled_rectangle(i*ESCALA, j*ESCALA, i*ESCALA + ESCALA-1 , j*ESCALA + ESCALA-1 , al_map_rgb(255,255,255));
            }else{
                al_draw_filled_rectangle(i*ESCALA, j*ESCALA, i*ESCALA + ESCALA-1 , j*ESCALA + ESCALA-1 , al_map_rgb(0, 0, 0));
            }//Esses códigos comentados são, na verdade, a versão sem sprites.

        }
    }
}
