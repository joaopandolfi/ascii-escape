//---------------------------------------------------------------------------
typedef struct Faseatual{
        int numero;        //numero da fase ex: fase 2
        int tmx , tmy;     //tamanho do mapa
        char arquivo[15];  //arquivo do mapa
        }Fase;

typedef struct Personagem{
        int x , y;  //coordenada
        int inv[4]; //inventario
        int bau[3]; //bau
        int reset;  //quantidade de resets
        Fase * fase;//fase atual
        char nome[15];
        char ant;   //pixel anterior
        }Perso;

typedef struct Mapaatual{
        int x, y;   //coordenada
        char val;   //caracter
        struct Mapaatual * prox; //proxima coluna
        struct Mapaatual * linha;//proxima linha
        }Mapa;

typedef struct Lista_de_mapas{
        int n;
        char arquivo[15];
        }Lmapa;
