#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "engine.h"

void tela(char val,int ctl){
     //printa com efeito o mapa
     switch (val){
        case '#':
            textcolor(DARK_GRAY);
            backcolor(DARK_GRAY);
            printf("%c",val);
        break;

        case 'X':
            textcolor(WHITE);
            backcolor(BLACK);
            if(ctl == 1)
                printf("e");
            else
                printf(" ");
        break;

        case 'e':
            textcolor(WHITE);
            backcolor(BLACK);
            printf("e");
        break;

        case 'h':
            textcolor(BLACK);
            backcolor(WHITE);
            printf("h");
        break;

        case '@':
              textcolor(BLACK);
              backcolor(WHITE);
              printf("?");
        break;

        case '1':
              textcolor(LIGHT_RED);
              backcolor(BLACK);
              printf("+");
        break;

        case '2':
              textcolor(LIGHT_BLUE);
              backcolor(BLACK);
              printf("+");
        break;

        case '3':
              textcolor(MAGENTA);
              backcolor(BLACK);
              printf("+");
        break;

        case '4':
              textcolor(YELLOW);
              backcolor(BLACK);
              printf("+");
        break;

        case 'A':
              textcolor(LIGHT_RED);
              backcolor(BLACK);
              printf("0");
        break;

        case 'B':
              textcolor(LIGHT_BLUE);
              backcolor(BLACK);
              printf("0");
        break;

        case 'C':
              textcolor(MAGENTA);
              backcolor(BLACK);
              printf("0");
        break;

        case 'D':
              textcolor(YELLOW);
              backcolor(BLACK);
              printf("0");
        break;

        default:
            backcolor(BLACK);
            printf("%c",val);
        break;
     }
}

void escreve_pixel(int x,int y, char val){
     gotoxy(x,y);
     tela(val,0);
}

void save(Perso * p1){
     FILE * save;
     char nick2[25];
     memset(nick2,'\0',25);    //limpa memoria
     strcat(nick2,"save/");    //define pasta
     strcat(nick2,p1->nome);   //monta caminho completo
     strcat(nick2,".txt");     //concatena .txt
     save = fopen(nick2,"w");
     fprintf(save,"%d,%d",p1->fase->numero - 1,p1->reset); //salva -1 por é o indice do vetor e a quantidade de resets
     fclose(save);
     gotoxy(2,23);
     printf("Salvo");
}


void atualiza_tela(Mapa * origem,Perso * perso){
    int x,y,z,tam;
    int atmx,atmy,af,aix,aiy;
    char val;
    Mapa * auy;
    Mapa * aux;
    printf("\n");
    for(auy=origem;auy->linha != NULL;auy = auy->linha){
        backcolor(BLACK);
        printf(" ");
        for(aux=auy;aux->prox != NULL;aux = aux->prox)
            tela(aux->val,0);//printa mapa
        tela(aux->val,0);
        printf("\n");
    }
}

Perso * inventario(Perso * p1){
      int i;
      char val;
      backcolor(BLACK);
      textcolor(LIGHT_GRAY);
      printf("\n\t INVENTARIO: ");
      for(i=0;i<4;i++){
        textcolor(LIGHT_GRAY);
        printf("|");
       switch(p1->inv[i]){
            case 1:
                textcolor(LIGHT_RED);
                val = '+';
            break;

            case 2:
                textcolor(LIGHT_BLUE);
                val = '+';
            break;

            case 3:
                textcolor(MAGENTA);
                val = '+';
            break;

            case 4:
                textcolor(YELLOW);
                val = '+';
            break;

            default:
                val = ' ';
       }
      printf(" %c ",val);
    }

    textcolor(LIGHT_GRAY);
    printf("|");
    if(p1->bau[2] == 1){
        printf(" BAU: ");
        for(i=0;i<2;i++){
            textcolor(LIGHT_GRAY);
            printf("|");
            switch(p1->bau[i]){
                case 1:
                    textcolor(LIGHT_RED);
                    val = '+';
                break;

                case 2:
                    textcolor(LIGHT_BLUE);
                    val = '+';
                break;

                case 3:
                    textcolor(MAGENTA);
                    val = '+';
                break;

                case 4:
                    textcolor(YELLOW);
                    val = '+';
                break;

                default:
                    val = ' ';
            }
            printf(" %c ",val);
        }
      textcolor(LIGHT_GRAY);
      backcolor(BLACK);
      printf("|\n\t               1   2   3   4          8   9");
    }
    else if(p1->bau[2] == 2){
       //apaga o "bau"
       printf("               \n\t                                           ");
    }
}

void bau(Perso * p1,int com,Mapa * origem){

      switch(com){
      case 1:
           if(p1->bau[0] == 0){
                p1->bau[0] = p1->inv[0];
                p1->inv[0] = 0;
           }
           else if(p1->bau[1] == 0){
                p1->bau[1] = p1->inv[0];
                p1->inv[0] = 0;
           }
      break;

      case 2:
           if(p1->bau[0] == 0){
                p1->bau[0] = p1->inv[1];
                p1->inv[1] = 0;
           }
           else if(p1->bau[1] == 0){
                p1->bau[1] = p1->inv[1];
                p1->inv[1] = 0;
           }
      break;

      case 3:
           if(p1->bau[0] == 0){
                p1->bau[0] = p1->inv[2];
                p1->inv[2] = 0;
           }
           else if(p1->bau[1] == 0){
                p1->bau[1] = p1->inv[2];
                p1->inv[2] = 0;
           }
      break;

      case 4:
           if(p1->bau[0] == 0){
                p1->bau[0] = p1->inv[3];
                p1->inv[3] = 0;
           }
           else if(p1->bau[1] == 0){
                p1->bau[1] = p1->inv[3];
                p1->inv[3] = 0;
           }
      break;

      case 8:
           if(p1->inv[0] == 0){
                p1->inv[0] = p1->bau[0];
                p1->bau[0] = 0;
           }
           else if(p1->inv[1] == 0){
                p1->inv[1] = p1->bau[0];
                p1->bau[0] = 0;
           }
           else if(p1->inv[2] == 0){
                p1->inv[2] = p1->bau[0];
                p1->bau[0] = 0;
           }
           else if(p1->inv[3] == 0){
                p1->inv[3] = p1->bau[0];
                p1->bau[0] = 0;
           }
      break;
      case 9:
           if(p1->inv[0] == 0){
                p1->inv[0] = p1->bau[1];
                p1->bau[1] = 0;
           }
           else if(p1->inv[1] == 0){
                p1->inv[1] = p1->bau[1];
                p1->bau[1] = 0;
           }
           else if(p1->inv[2] == 0){
                p1->inv[2] = p1->bau[1];
                p1->bau[1] = 0;
           }
           else if(p1->inv[3] == 0){
                p1->inv[3] = p1->bau[1];
                p1->bau[1] = 0;
           }
       break;
      }
    //gotoxy(10,45);
    //atualiza_tela(origem,p1);
    //escreve_pixel(p1->x,p1->y,'e');
    gotoxy(10,22);
    inventario(p1);
}


Mapa * carrega_mapa(char arquivo[15],Perso * perso){
    int x,y,z,tam;
    int atmx,atmy,af,aix,aiy;
    char val;
   //leitura do arquivo do primeiro mapa  x,y,fase,ix,iy
    FILE * amapa;
    amapa = fopen (arquivo,"r");
    fscanf (amapa, "%d,%d,%d,%d,%d\n",&atmx,&atmy,&af,&aix,&aiy);

    //configurações do mapa
    perso->x =  aix;                                      //coordenada do ponto de partida
    perso->y =  aiy;
    perso->ant = ' ';                                     //define pixel anterior
    perso->inv[0] = perso->inv[1] = perso->inv[2] = perso->inv[3] = 0; //reseta inv
    perso->bau[0] = perso->bau[1] = 0;                    //reseta bau
    perso->fase->tmy = atmy;
    perso->fase->tmx = atmx;
    perso->fase->numero = af;                            //recebe o numero da fase
    Mapa * origem;
    Mapa * mapa = (Mapa *)malloc(sizeof(Mapa*));        //aloquei o primeiro valor
    Mapa * aux;
    printf("\n");
    for(y=0;y<perso->fase->tmy;y++){
    backcolor(BLACK);
    printf(" ");
     for(x=0;x<perso->fase->tmx;x++){
     fscanf (amapa, "%c",&val);                        //percorre o arquivo
      if(x==0 && y==0){
       mapa->x = mapa->y = 0;                           //define a coord 0,0
       mapa->val = val;
       mapa->prox = NULL;                               //proximo como NULL
       mapa->linha = NULL;                              //proxima linha como NULL
       origem = mapa;                                   //segurei o ponteiro 0,0
      }
       else if(x==0 && y!=0){
       mapa->val = val;
       }
       else{
       aux = (Mapa *)malloc(sizeof(Mapa));
       aux->x = x;
       aux->y = y;                                     //coloquei o valor da coordenada
       aux->prox = NULL;                               //proximo como NULL
       aux->linha = NULL;                              //proxima linha como NULL
       aux->val = val;
       mapa->prox = aux;
       mapa = aux;
      }
      //printa mapa
      tela(val,1);
     }
     fscanf (amapa, "\n");                            //quebra linha de leitura
     printf("\n");                                     //quebra linha da tela
     if(origem->linha != NULL)
     for(aux = origem;aux->linha != NULL;aux=aux->linha) //percorri ate achar o valor livre
     {}
     else
     aux=origem;
     mapa = (Mapa *)malloc(sizeof(Mapa));
     aux->linha = mapa;
     mapa->x = 0;
     mapa->y = z;
     mapa->prox = NULL;                               //proximo como NULL
     mapa->linha = NULL;                              //proxima linha como NULL
    }
 fclose (amapa);
 return origem;
     }

void descarrega_mapa(Mapa * origem,Perso * perso){
    //configurações do mapa (struct personagem)
    perso->x =  0;                                      //coordenada do ponto de partida
    perso->y =  0;
    perso->ant = ' ';                                    //define pixel anterior
    perso->fase->numero = 0;                            //recebe o numero da fase

    //liberando memoria
     Mapa * auxl;
     Mapa * auxl2;
     Mapa * auxc;
     Mapa * auxc2;
     auxl2 = origem;

     int vx,vy,y,x;
     vx = perso->fase->tmx;
     vy = perso->fase->tmy;
     perso->fase->tmy = 0;
     perso->fase->tmx = 0;
     Mapa * linha,* coluna1,* coluna2,* aux;
     coluna1 = origem->prox;
     aux = linha = origem;       //fiz uma copia da origem

     //limpa somente da segunda coluna p frente --- ok
      for(y=0;y<(vy-1);y++){     //percorro por colunas
      for(x=0;x<(vx-1);x++){
      coluna2 = coluna1;
      coluna1 = coluna1->prox;
      free(coluna2);
      }
      linha = linha->linha;
      coluna1 = linha->prox;
    }
    //limpa a primeira coluna toda
     coluna1 = origem;
     for(y=0;y<vy;y++){
      coluna2 = coluna1;
      coluna1 = coluna1->linha;
      free(coluna2);
      }
/* NÃO FUNCIONOU
    for(auxl = origem->linha;auxl->linha != NULL;auxl = auxl->linha){ //percorro por linhas
     auxc2 = auxl2;
      for(auxc = origem->prox;auxc->prox != NULL;auxc = auxc->prox){     //percorro por colunas
      free(auxc2);
      auxc2 = auxc; //pega a prox coluna
      }
      free(auxc);   //libera as 2 ultimas
      free(auxc2);
      auxl2 = auxl; //pega a prox linha
     }*/
    }


char retorna_pixel(int vx,int vy,Mapa * origem){
     int x,y;
     Mapa * aux;
     aux = origem;       //fiz uma copia da origem
     if(vy!=0){           //percorro por linhas
      for(y=1;y<vy;y++)
      aux = aux->linha;
      }
     if(vx!=0){         //percorro por colunas
      for(x=1;x<vx;x++)
      aux = aux->prox;
      }
      return aux->val;
     }

void atualiza_pixel(int vx,int vy,Mapa * origem,char pix){
     int x,y;
     Mapa * aux;
     aux = origem;       //fiz uma copia da origem
     if(vy!=0){           //percorro por linhas
      for(y=1;y<vy;y++)
      aux = aux->linha;
      }
     if(vx!=0){         //percorro por colunas
      for(x=1;x<vx;x++)
      aux = aux->prox;
      }
      aux->val = pix;   //atualiza pixel
      escreve_pixel(vx,vy,pix);
     }

Perso * cordenada(Perso * p1,Mapa * origem,int cd){
      // cd = 1 botao direito -- cd = 2 botao esquerdo
      // cd = 3 botao baixo   -- cd = 4 botao cima
      int aux=0;
      char pixel,apixel;
     if(cd==1 && (p1->x < p1->fase->tmx)){
      p1->x ++;
      pixel = retorna_pixel(p1->x,p1->y,origem); //printf("[%d]=[%d]=[%d]=[%c]",p1->x,cd,p1->y,pixel);

       if(p1->ant == 'A')
       atualiza_pixel((p1->x-1),p1->y,origem,'A');
       else if(p1->ant == 'B')
       atualiza_pixel((p1->x-1),p1->y,origem,'B');
       else if(p1->ant == 'C')
       atualiza_pixel((p1->x-1),p1->y,origem,'C');
       else if(p1->ant == 'D')
       atualiza_pixel((p1->x-1),p1->y,origem,'D');
       else if(p1->ant == 'h')
       atualiza_pixel((p1->x-1),p1->y,origem,'h'),backcolor(BLACK);
       if((p1->bau[2] == 1) && (pixel != 'h') && (pixel != '#')){
       p1->bau[2] = 2;
       gotoxy(10,22);
       inventario(p1);
       p1->bau[2] = 0;
      // system("cls");
      // atualiza_tela(origem,p1);
       }

      switch(pixel){
      case '#':
       aux=1;
       p1->x--;
       apixel = retorna_pixel(p1->x,p1->y,origem); //printf("[%d]=[%d]=[%d]=[%c]",p1->x,cd,p1->y,pixel);
       if(apixel == 'X')
       atualiza_pixel(p1->x,p1->y,origem,'e');
       break;
       case '1':
       if(p1->inv[0] == 0)
       p1->inv[0] = 1;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 1;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 1;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 1;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case '2':
       if(p1->inv[0] == 0)
       p1->inv[0] = 2;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 2;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 2;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 2;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case '3':
       if(p1->inv[0] == 0)
       p1->inv[0] = 3;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 3;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 3;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 3;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case '4':
       if(p1->inv[0] == 0)
       p1->inv[0] = 4;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 4;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 4;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 4;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case 'A':
       if(p1->inv[0] == 1){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 1){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 1){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 1){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x--;
       break;
       case 'B':
        if(p1->inv[0] == 2){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 2){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 2){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 2){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x--;
       break;
       case 'C':
        if(p1->inv[0] == 3){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 3){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 3){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 3){
       p1->inv[3] = 0;
      atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
         }
        else
       p1->x--;
       break;
       case 'D':
        if(p1->inv[0] == 4){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 4){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 4){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 4){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x--;
       break;
       case 'h':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       p1->bau[2] = 1; //ativa o uso do bau
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = 'h';
       break;
       case '@':
            p1->fase->numero ++;
       break;
       case ' ':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x-1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       }

       }
       // cd = 2
     else if(cd==2 && (p1->x >=1)){
      p1->x --;
      pixel = retorna_pixel(p1->x,p1->y,origem);  //printf("[%c]=[%c]=[%d]=[%d]",p1->ant,pixel,p1->x,p1->y);
       if(p1->ant == 'A')
       atualiza_pixel((p1->x+1),p1->y,origem,'A');
       else if(p1->ant == 'B')
       atualiza_pixel((p1->x+1),p1->y,origem,'B');
       else if(p1->ant == 'C')
       atualiza_pixel((p1->x+1),p1->y,origem,'C');
       else if(p1->ant == 'D')
       atualiza_pixel((p1->x+1),p1->y,origem,'D');
       else if(p1->ant == 'h')
       atualiza_pixel((p1->x+1),p1->y,origem,'h') ,backcolor(BLACK);
       if((p1->bau[2] == 1) && (pixel != 'h') && (pixel != '#')){
       p1->bau[2] = 2;
       gotoxy(10,22);
       inventario(p1);
       p1->bau[2] = 0;
       /*system("cls");
       atualiza_tela(origem,p1);*/
       }

      switch(pixel){
       case '#':
       aux=1;
       p1->x++;
       apixel = retorna_pixel(p1->x,p1->y,origem); //printf("[%d]=[%d]=[%d]=[%c]",p1->x,cd,p1->y,pixel);
       if(apixel == 'X')
       atualiza_pixel(p1->x,p1->y,origem,'e');
       break;
       case '1':
       if(p1->inv[0] == 0)
       p1->inv[0] = 1;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 1;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 1;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 1;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case '2':
       if(p1->inv[0] == 0)
       p1->inv[0] = 2;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 2;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 2;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 2;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case '3':
       if(p1->inv[0] == 0)
       p1->inv[0] = 3;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 3;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 3;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 3;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case '4':
       if(p1->inv[0] == 0)
       p1->inv[0] = 4;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 4;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 4;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 4;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       case 'A':
        if(p1->inv[0] == 1){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 1){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 1){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 1){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x++;
       break;
       case 'B':
        if(p1->inv[0] == 2){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 2){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 2){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 2){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x++;
       break;
       case 'C':
        if(p1->inv[0] == 3){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 3){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 3){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 3){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x++;
       break;
       case 'D':
        if(p1->inv[0] == 4){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 4){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 4){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 4){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
        }
        else
       p1->x++;
       break;
       case 'h':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       p1->bau[2] = 1;
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h')){
       atualiza_pixel((p1->x+1),p1->y,origem,' ');}
       p1->ant = pixel;
       break;
       case '@':
            p1->fase->numero ++;
       break;
       case ' ':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel((p1->x+1),p1->y,origem,' ');
       p1->ant = pixel;
       break;
       }
      }
       // cd = 3
     else if(cd==3 && (p1->y < p1->fase->tmy)){
      p1->y ++;
      pixel = retorna_pixel(p1->x,p1->y,origem);

       if(p1->ant == 'A')
       atualiza_pixel(p1->x,(p1->y-1),origem,'A');
       else if(p1->ant == 'B')
       atualiza_pixel(p1->x,(p1->y-1),origem,'B');
       else if(p1->ant == 'C')
       atualiza_pixel(p1->x,(p1->y-1),origem,'C');
       else if(p1->ant == 'D')
       atualiza_pixel(p1->x,(p1->y-1),origem,'D');
       else if(p1->ant == 'h')
       atualiza_pixel(p1->x,(p1->y-1),origem,'h') ,backcolor(BLACK);
       if((p1->bau[2] == 1) && (pixel != 'h') && (pixel != '#')){
       p1->bau[2] = 2;
       gotoxy(10,22);
       inventario(p1);
       p1->bau[2] = 0;
       /*system("cls");
       atualiza_tela(origem,p1);*/
       }

      switch(pixel){
       case '#':
       aux=1;
       p1->y--;
       apixel = retorna_pixel(p1->x,p1->y,origem); //printf("[%d]=[%d]=[%d]=[%c]",p1->x,cd,p1->y,pixel);
       if(apixel == 'X')
       atualiza_pixel(p1->x,p1->y,origem,'e');
       break;
       case '1':
       if(p1->inv[0] == 0)
       p1->inv[0] = 1;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 1;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 1;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 1;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        break;
       case '2':
       if(p1->inv[0] == 0)
       p1->inv[0] = 2;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 2;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 2;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 2;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       break;
       case '3':
       if(p1->inv[0] == 0)
       p1->inv[0] = 3;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 3;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 3;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 3;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       break;
       case '4':
       if(p1->inv[0] == 0)
       p1->inv[0] = 4;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 4;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 4;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 4;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       break;
       case 'A':                                                       //A
        if(p1->inv[0] == 1){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 1){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 1){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 1){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y--;
       break;
       case 'B':                                  //B
        if(p1->inv[0] == 2){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 2){
       p1->inv[1] = 0;
       p1->ant = pixel;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       }
       else if(p1->inv[2] == 2){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 2){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y--;
       break;
       case 'C':                                  //C
        if(p1->inv[0] == 3){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 3){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 3){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 3){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y--;
       break;
       case 'D':
        if(p1->inv[0] == 4){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 4){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 4){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 4){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y--;
       break;
       case 'h':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       p1->bau[2] = 1;
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h')){
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');}
       p1->ant = pixel;
       break;
       case '@':
            p1->fase->numero ++;
       break;
       case ' ':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       escreve_pixel(p1->x,p1->y,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y-1),origem,' ');
       p1->ant = pixel;
       break;
       }
        }
        //cd = 4
     else if(cd==4 && (p1->y >= 1)){
      p1->y --;
      pixel = retorna_pixel(p1->x,p1->y,origem); //printf("[%d]=[%d]=[%d]=[%c]",p1->x,cd,p1->y,pixel);
       if(p1->ant == 'A')
       atualiza_pixel(p1->x,(p1->y+1),origem,'A');
       else if(p1->ant == 'B')
       atualiza_pixel(p1->x,(p1->y+1),origem,'B');
       else if(p1->ant == 'C')
       atualiza_pixel(p1->x,(p1->y+1),origem,'C');
       else if(p1->ant == 'D')
       atualiza_pixel(p1->x,(p1->y+1),origem,'D');
       else if(p1->ant == 'h')
       atualiza_pixel(p1->x,(p1->y+1),origem,'h') ,backcolor(BLACK);
       if((p1->bau[2] == 1) && (pixel != 'h') && (pixel != '#')){
       p1->bau[2] = 2;
       gotoxy(10,22);
       inventario(p1);
       p1->bau[2] = 0;
      /* system("cls");
       atualiza_tela(origem,p1);*/
       }

      switch(pixel){
       case '#':
       aux=1;
       p1->y++;
       apixel = retorna_pixel(p1->x,p1->y,origem); //printf("[%d]=[%d]=[%d]=[%c]",p1->x,cd,p1->y,pixel);
       if(apixel == 'X')
       atualiza_pixel(p1->x,p1->y,origem,'e');
       break;
       case '1':
       if(p1->inv[0] == 0)
       p1->inv[0] = 1;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 1;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 1;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 1;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       break;
       case '2':
       if(p1->inv[0] == 0)
       p1->inv[0] = 2;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 2;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 2;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 2;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       break;
       case '3':
       if(p1->inv[0] == 0)
       p1->inv[0] = 3;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 3;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 3;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 3;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       break;
       case '4':
       if(p1->inv[0] == 0)
       p1->inv[0] = 4;
       else if(p1->inv[1] == 0)
       p1->inv[1] = 4;
       else if(p1->inv[2] == 0)
       p1->inv[2] = 4;
       else if(p1->inv[3] == 0)
       p1->inv[3] = 4;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       break;
       case 'A':
        if(p1->inv[0] == 1){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 1){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 1){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 1){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y++;
       break;
       case 'B':
        if(p1->inv[0] == 2){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 2){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 2){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
        }
       else if(p1->inv[3] == 2){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y++;
       break;
       case 'C':
        if(p1->inv[0] == 3){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[1] == 3){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       }
       else if(p1->inv[2] == 3){
       p1->inv[2] = 0;
       p1->ant = pixel;
       atualiza_pixel(p1->x,p1->y,origem,'e');
     if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
          }
       else if(p1->inv[3] == 3){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
        }
        else
       p1->y++;
       break;
       case 'D':
        if(p1->inv[0] == 4){
       p1->inv[0] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
        if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
      }
       else if(p1->inv[1] == 4){
       p1->inv[1] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
      if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
         }
       else if(p1->inv[2] == 4){
       p1->inv[2] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
          }
       else if(p1->inv[3] == 4){
       p1->inv[3] = 0;
       atualiza_pixel(p1->x,p1->y,origem,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
          }
        else
       p1->y++;
       break;
       case 'h':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       p1->bau[2] = 1;
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h')){
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');}
       p1->ant = pixel;
       break;
       case '@':
            p1->fase->numero ++;
       break;
       case ' ':
       atualiza_pixel(p1->x,p1->y,origem,'e');
       escreve_pixel(p1->x,p1->y,'e');
       if ((p1->ant != 'A') && (p1->ant != 'B') && (p1->ant != 'C') && (p1->ant != 'D') && (p1->ant != 'h'))
       atualiza_pixel(p1->x,(p1->y+1),origem,' ');
       p1->ant = pixel;
       break;
       }

       }

      gotoxy(10,22);
     // atualiza_tela(origem,p1);
      inventario(p1);
      return p1;
      }
