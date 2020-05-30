#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include"header.h"

/* system("cls") */
int main()
{
	int** M;
	int cases = 4, ligne = 4;
	srand(time(NULL));

	M = creemat(cases,ligne);
	void newgame(M, cases, ligne);

	free(M);
	return 0;
}
