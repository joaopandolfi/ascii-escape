#include "structs.h"
#include "color.h"

void tela(char val,int ctl);
void escreve_pixel(int x,int y, char val);
void save(Perso * p1);
void atualiza_tela(Mapa * origem,Perso * perso);
Perso * inventario(Perso * p1);
void bau(Perso * p1,int com,Mapa * origem);
Mapa * carrega_mapa(char arquivo[15],Perso * perso);
void descarrega_mapa(Mapa * origem,Perso * perso);
char retorna_pixel(int vx,int vy,Mapa * origem);
void atualiza_pixel(int vx,int vy,Mapa * origem,char pix);
Perso * cordenada(Perso * p1,Mapa * origem,int cd);
