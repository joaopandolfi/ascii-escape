#include "structs.h"
#include "menus.h"
#include "color.h"

  //primeiro menu -----------------------------------------------------
Perso * menuInicial(Perso * p1){
    int mp,hf,cp,rst;
    char cg;
    char nick[20],nick2[25];
    FILE *nick_file;
    hf=cp=1;
    while(hf==1){
    printf("\t\t\tBem vindo ao ASCII Scape\n\t\t\t Selecione uma opcao:\n");
    printf("\t\t\t 1 - Carregar jogo.\n\t\t\t 2 - Novo Game.\n");
    printf("\t\t\t |__> ");
    scanf("%c",&cg);
    if(cg == '1')
    {
     system("cls");
     while(cp==1){
     printf("\n\t\t\t\t ++ Load ++\n");
     printf("\n\t\t  Digite seu nick: ");
     scanf("%s",nick);
     memset(nick2,'\0',25);    //limpa memoria
     strcat(nick2,"save/");    //define pasta
     strcat(nick2,nick);       //monta caminho completo
     strcat(nick2,".txt");     //concatena .txt
     nick_file = fopen(nick2,"r");  //abre arquivo
     if (nick_file == NULL){    //verifica se o arquivo existe
        system("cls");
        printf("Save nao encontrado (%s).\n",nick);
        }
     else {
          fscanf (nick_file, "%d,%d",&mp,&rst);
          fclose (nick_file);
          strcpy(p1->nome,nick);
          p1->reset = rst;
          hf = cp = 2; //quebra o laço
          }
     }
    }
    else if(cg == '2'){
    hf =2; //quebra o laço
    mp=0;  //define o primeiro mapa 0
     system("cls");
     printf("\n\t\t\t\t ++ New Game ++\n");
     printf("\n\t\t  Digite seu nick: ");
     scanf("%s",nick);
     strcpy(p1->nome,nick);
    }
    else if(cg != '2')
    system("cls");
   }
    system("cls");
    p1->fase->numero = mp+1;
    return p1;
}
    //------------------------------------------------------------------

 //Instuçoes -----------------------------------------------------
 void instrucao(){
     printf("\t\t\t\tInstrucoes \n");
     Sleep(1000);
     printf("\t\t Seu Objetivo e chegar ate o Portal (");
     //pinta pixel para mostrar o portal
     textcolor(BLACK);
     backcolor(WHITE);
     printf("?");
     //retorna as cores antigas
     textcolor(LIGHT_GRAY);
     backcolor(BLACK);
     printf(") ...\n\n");
     Sleep(3000);
     printf("\t\t Voce nao Atravessa Paredes (");
     //pinta pixel para mostrar a parede
     textcolor(DARK_GRAY);
     backcolor(DARK_GRAY);
     printf("#");
     //retorna as cores antigas
     textcolor(LIGHT_GRAY);
     backcolor(BLACK);
     printf(").... Ainda.....\n\n");
     Sleep(3000);
     printf("\t\t Colete as Chaves Certas (+)...\n\n");
     Sleep(3000);
     printf("\t\t E passe Pelas fendas temporais(0)...\n\n");
     Sleep(3000);
     printf("\t\t Lembre-se! Uma chave vale apenas para 1 passagem...\n\n");
     Sleep(4000);
     printf("\t\t\t Botoes de Controle: \n\n");
     Sleep(1000);
     printf("\t\t\t Movimento: Setas\n\n");
     Sleep(1000);
     printf("\t\t\t Salvar Fase: S\n\n");
     Sleep(1000);
     printf("\t\t\t Reiniciar Fase: R\n\n");
     Sleep(1000);
     printf("\t\t\t Sair do Jogo: Esc\n\n\t\t");
     Sleep(1000);
     system("pause");
     system("cls");
    }
 //------------------------------------------------------------------
