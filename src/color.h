
typedef enum DOS_COLOR {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
	LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
	LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE } DOS_COLORS;

void gotoxy(int coluna, int linha);
//---------------------------------------------------
void textcolor (DOS_COLORS iColor);
// -------------------------------------------------------------------------
void backcolor (DOS_COLORS iColor);
