//---------------------------------------------------------------------------
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>      // printf
#include <conio.h>      // kbhit, getch

using namespace std;
#pragma hdrstop
#pragma argsused

//---------------------------------------------------------------------------
#include "engine.h"
#include "menus.h"
//---------------------------------------------------------------------------
 /* caracter especial para carinha  printf("%c",1); //carinha printf("%c",176);   //exibe a grama
 ~~> comandos color.h
 textcolor(BLUE);
 backcolor(LIGHT_RED);
 gotoxy(10,20);
    BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
	LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
	LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE */

int main()
{
    int keycode, normalkey, ctl,nfase;
    int tam,z,v;
    ctl = 0;
    Perso * perso = (Perso *)malloc(sizeof(Perso));
    Fase * fase = (Fase *)malloc(sizeof(Fase));
    Mapa * origem;
    perso->fase = fase;
    perso->inv[0] = perso->inv[1] = perso->inv[2] = perso->inv[3] = perso->reset =0;
    system("title ASCII Scape");
    //leitura do arquivo de mapas (lista)
    FILE * lmapas;
    lmapas = fopen ("lmapas.txt","r");
    fscanf (lmapas, "%d\n",&tam);
    Lmapa  listmapas[tam];
    for (z=0;z<tam;z++)
    fscanf (lmapas, "%d,%s\n", &listmapas[z].n,&listmapas[z].arquivo);
    fclose (lmapas);
    //gotoxy(10,45);

    //primeiro menú
    perso = menuInicial(perso);
    //instrucoes somete na primeira faze
    if(perso->fase->numero == 1)
    instrucao();

    //retorna origem e carrega o mapa para a memoria
    nfase = listmapas[(perso->fase->numero -1)].n;
    printf(" Fase: %d\tNick: %s\tResets: %d",nfase,perso->nome,perso->reset);
    origem = carrega_mapa(listmapas[(perso->fase->numero -1)].arquivo,perso);
    gotoxy(10,22);
    inventario(perso);

    //retorna as cores antigas
    textcolor(LIGHT_GRAY);
    backcolor(BLACK);

    while ( keycode != 27 ){         // ESCAPE
        if (perso->fase->numero > nfase){
            printf("\n Carregando... \n");
            nfase = perso->fase->numero;
            descarrega_mapa(origem,perso);
            system("cls");
            //gotoxy(10,45);
            printf(" Fase: %d\tNick: %s\tResets: %d",nfase,perso->nome,perso->reset);
            free(origem);
            origem = carrega_mapa(listmapas[nfase-1].arquivo,perso);
            gotoxy(10,22);
            inventario(perso);
            textcolor(LIGHT_GRAY);
            backcolor(BLACK);
           }
        if(ctl == 2){
            descarrega_mapa(origem,perso);
            printf("\n Reiniciando...\n");
            system("cls");
            perso->reset = perso->reset +1;
            //gotoxy(10,45);
            printf(" Fase: %d\tNick: %s\tResets: %d",nfase,perso->nome,perso->reset);
            free(origem);
            origem = carrega_mapa(listmapas[nfase-1].arquivo,perso);
            gotoxy(10,22);
            inventario(perso);
            textcolor(LIGHT_GRAY);
            backcolor(BLACK);
            ctl = 0;
        }
        // aguardar uma tecla ser pressionada
        while ( ! kbhit() ) ;
        // ler o código da tecla pressionada
        keycode = getch();
        // keycode = 0 se for tecla especial
        normalkey = keycode;
        if (normalkey == 224)
        ctl = 1;
        if ( !normalkey )
            keycode = getch();

       if ( (ctl == 1) && keycode == 80 ){
           cordenada(perso,origem,3);
            ctl = 0 ;
            }
      else if ( (ctl == 1) && keycode == 75 ){
            cordenada(perso,origem,2);
            ctl = 0 ;
            }
        else if ( (ctl == 1) && keycode == 77 ){
            cordenada(perso,origem,1);
            ctl = 0 ;
            }
        else if ( (ctl == 1) && keycode == 72 ){
            cordenada(perso,origem,4);
            ctl = 0 ;
            }
        else if ( keycode == 114 ){//r
             ctl = 2;
            }
        else if ( keycode == 115 ){//s
             save(perso);
            }
       if(perso->bau[2] == 1){
            if ( keycode == 49 ){//1
                 bau(perso,1,origem);
                }
            else if ( keycode == 50 ){//2
                 bau(perso,2,origem);
                }
            else if ( keycode == 51 ){//3
                 bau(perso,3,origem);
                }
            else if ( keycode == 52 ){//4
                 bau(perso,4,origem);
                }
            else if ( keycode == 56 ){//8
                 bau(perso,8,origem);
                }
            else if ( keycode == 57 ){//9
                 bau(perso,9,origem);
                }
        }
   }

    return 0;
}
//---
