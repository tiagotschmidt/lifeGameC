// Trabalho Final ERE - Gabriel Castelo Branco Gomes e Tiago Torres Schmidt.

#include <stdio.h> //Bibliotecas utilizadas no projeto. Projeto desenvolvido utilizando Allegro.
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "engine.h"

#define KEY_SEEN     1//Constantes utilizadas no projeto.
#define KEY_RELEASED 2
#define N_LINHAS 200
#define N_COLUNAS 200
#define ESCALA 5

int main()//Função main, executa o projeto.
{
    srand(time(NULL));//Variáveis principais do projeto.
    int i,j;
    bool done = false;
    bool redraw = true;
    float x, y;
    unsigned char tecla[ALLEGRO_KEY_MAX];
    ALLEGRO_EVENT event;
    char map[N_LINHAS][N_COLUNAS];
    obj objImage[N_LINHAS][N_COLUNAS];

    inicializa(al_init(), "Allegro.");//Inicialização da Allegro...
    inicializa(al_install_keyboard(), "Teclado.");
    ALLEGRO_TIMER* timer = al_create_timer(1.0 / 60.0);//Framerate e velocidade do jogo.
    inicializa(timer, "Temporizador.");
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
    inicializa(queue, "Fila de eventos");

    al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
    al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
    al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

    ALLEGRO_DISPLAY* disp = al_create_display(ESCALA*N_COLUNAS , N_LINHAS*ESCALA);//Tamanho do display.
    inicializa(disp, "Tela.");
    ALLEGRO_FONT* font = al_create_builtin_font();
    inicializa(font, "Fonte.");
    inicializa(al_init_primitives_addon(), "Adicionais primitivos.");
    inicializa(al_init_image_addon(), "Adicional de imagem.");

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_set_window_title(disp,"Conway's game of life.");

    memset(tecla, 0, sizeof(tecla));

    loadMap(objImage);

    /*for(i=0;i<N_COLUNAS;i++)
    {
        for(j=0;j<N_LINHAS;j++)
        {
          printf("%d\t",objImage[j][i].isAlive);
        }
        printf("\n");
    }*/

    //updateCell(objImage);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    drawMap(objImage);
    al_flip_display();

    al_start_timer(timer);
    while(1) //Loop do game.
    {
            al_wait_for_event(queue, &event);

            updateCell(objImage);

            /*puts("Nova versão -----------------------------------------------------\n");
            for(i=0;i<N_COLUNAS;i++)
            {
                for(j=0;j<N_LINHAS;j++)
                {
                  printf("%d\t",objImage[j][i].isAlive);
                }
                printf("\n");
            }*/

            redraw = true;

            if(redraw && al_is_event_queue_empty(queue))//Sistema para projeção dos gráficos.
            {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                drawMap(objImage);
                //al_draw_textf(font, al_map_rgb(255, 255, 255), 0, 0, 0, "X: %.1f Y: %.1f", x, y);
                al_flip_display();

                redraw = false;
            }

    }

    al_destroy_font(font);//Encerra os addons quando o while é quebrado.
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
}
