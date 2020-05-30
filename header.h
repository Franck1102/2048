#define header
#ifdef header

/* 1 : création du  et des cases */

int** creemat(int cases, int ligne);
void remplirmat(int** Mat, int cases, int ligne);
void affichemat(int** Mat, int cases, int ligne);
void appeartwo(int** Mat, int cases, int ligne);

/* 2 : déplacements, tests et arbitrage */

/* 2-a : test */

void mathor(int** Mat, int cases, int ligne);
void matvert(int** Mat, int cases, int ligne);

/* 2-b : vraie version */

void leftfusion(int** Mat, int ligne, int* score);
void leftmove(int** Mat, int cases, int ligne);

void rightfusion(int** Mat, int cases, int ligne, int* score);
void rightmove(int** Mat, int cases, int ligne);

void upfusion(int** Mat, int cases);
void upmove(int** Mat, int cases, int ligne);

void downfusion(int** Mat, int cases, int ligne, int* score);
void downmove(int** Mat, int cases, int ligne);

/* 3 : le jeu lui-même */

int lose(int** Mat, int cases, int ligne);
int win(int** Mat, int cases, int ligne);
void newgame(int** Mat, int cases, int ligne);

#endif
