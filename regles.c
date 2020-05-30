#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

int** creemat(int cases, int ligne) /* crée le plateau de jeu */
{
	int** Mat;
	int i;

	Mat = (int**)malloc(cases*sizeof(int*));
	for(i=0; i<ligne; i++)
		{
			Mat[i] = malloc(cases*sizeof(int*));
		}

	return (Mat);
}

void initmat(int** Mat, int cases, int ligne) /* initialisation des valeurs */
{
	int i,j,m = 0,n = 0,o = 0,p = 0;

	for(i=0; i<ligne; i++)
		{
			for(j=0; j<cases; j++)
				{
					Mat[j][i] = 0;

				}
		}
	while(m== o || n == p)
		{
			m = rand()%cases;
			o = rand()%ligne;
			n = rand()%cases;
			p = rand()%ligne;
		}

	Mat[m][o] = 2;
	Mat[n][p] = 2;

}

void affichemat(int** Mat, int cases, int ligne) /* affiche le plateau */
{
	int i;
	int j;
	for(i=0; i<ligne; i++)
		{
			for(j=0; j<cases; j++)
				{
					printf("%d  ",Mat[j][i]);
				}
			printf("\n\n");
		}
}

void appeartwo(int** Mat, int cases, int ligne) /* fais apparaitre un deux sur une case zéro aléatoirement */
{
	int i, j;

	i = rand()%ligne;
	j = rand()%cases;

    while(Mat[j][i] != 0)
        {
            i = rand()%ligne;
            j = rand()%cases;
        }

    Mat[j][i] = 2;

}

void leftmove(int** Mat, int cases, int ligne) /* déplacement vers la gauche */
{
    int i, j, conteur;

    for(i = 0; i < ligne; i++)
    {
        do
        {   conteur = 0;
            for(j = 0; j < cases - 1; j++)
            {
                if(Mat[j][i] == 0 && Mat[j+1][i] != 0)
                {
                    Mat[j][i] = Mat[j+1][i];
                    Mat[j+1][i] = 0;
                    conteur = conteur + 1;
                }
            }
        }while(conteur != 0);
    }
}

void leftfusion(int** Mat, int ligne, int* score) /* fusion à gauche */
{
    int i, dec;

    for(i = 0; i < ligne; i++)
    {
        dec = 0;

        if(Mat[dec][i] == Mat[dec+1][i]) /* cases cote à cote */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec+1][i] = 0;
            *score = *score + Mat[dec][i];
        }
        else if(Mat[dec][i] == Mat[dec+2][i] && Mat[dec+1][i] == 0) /* avec une case à 0 d'écart */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec+2][i] = 0;
            *score = *score + Mat[dec][i];
        }
        else if((Mat[dec][i]) == (Mat[dec+3][i]) && (Mat[dec+1][i]) == 0 && Mat[dec+2][i] == 0) /* avec 2 cases à 0 d'écart */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec+3][i] = 0;
            *score = *score + Mat[dec][i];
        }

        dec = dec + 1;

        if(Mat[dec][i] == Mat[dec+1][i]) /* cases cote à cote */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec+1][i] = 0;
            *score = *score + Mat[dec][i];
        }
        else if(Mat[dec][i] == Mat[dec+2][i] && Mat[dec+1][i] == 0) /* avec une case à 0 d'écart */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec+2][i] = 0;
            *score = *score + Mat[dec][i];
        }

        dec = dec + 1;

         if(Mat[dec][i] == Mat[dec+1][i]) /* cases cote à cote */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec+1][i] = 0;
            *score = *score + Mat[dec][i];
        }
    }

}

void rightfusion(int** Mat, int cases, int ligne, int* score) /* fusion à droite */
{
    int i, dec;

    for(i = 0; i < ligne; i++)
    {
        dec = cases - 1;

        if(Mat[dec][i] == Mat[dec-1][i]) /* cases cote à cote */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec-1][i] = 0;
            *score = *score + Mat[dec][i];
        }
        else if(Mat[dec][i] == Mat[dec-2][i] && Mat[dec-1][i] == 0) /* avec une case à 0 d'écart */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec-2][i] = 0;
            *score = *score + Mat[dec][i];
        }
        else if((Mat[dec][i]) == (Mat[dec-3][i]) && (Mat[dec-1][i]) == 0 && Mat[dec-2][i] == 0) /* avec 2 cases à 0 d'écart */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec-3][i] = 0;
            *score = *score + Mat[dec][i];
        }

        dec = dec - 1;

        if(Mat[dec][i] == Mat[dec-1][i]) /* cases cote à cote */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec-1][i] = 0;
            *score = *score + Mat[dec][i];
        }
        else if(Mat[dec][i] == Mat[dec-2][i] && Mat[dec-1][i] == 0) /* avec une case à 0 d'écart */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec-2][i] = 0;
            *score = *score + Mat[dec][i];
        }

        dec = dec - 1;

        if(Mat[dec][i] == Mat[dec-1][i]) /* cases cote à cote */
        {
            Mat[dec][i] = 2 * Mat[dec][i];
            Mat[dec-1][i] = 0;
            *score = *score + Mat[dec][i];
        }
    }

}

void rightmove(int** Mat, int cases, int ligne) /* déplacement vers la droite */
{
    int i, j, conteur;

    for(i = 0; i < ligne; i++)
    {
        do
        {
            conteur = 0;
            for(j = cases - 1; j > 0; j--)
            {
                if(Mat[j][i] == 0 && Mat[j-1][i])
                {
                    Mat[j][i] = Mat[j-1][i];
                    Mat[j-1][i] = 0;
                    conteur = conteur + 1;
                }
            }
        }while(conteur != 0);
    }
}

void upfusion(int** Mat, int cases, int* score) /* fusion en haut */
{
    int j, dec;

    for(j = 0; j < cases; j++)
    {
        dec = 0;

        if(Mat[j][dec] == Mat[j][dec+1]) /* cases cote à cote */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+1] = 0;
            *score = *score + Mat[j][dec];
        }
        else if(Mat[j][dec] == Mat[j][dec+2] && Mat[j][dec+1] == 0) /* avec une case à 0 d'écart */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+2] = 0;
            *score = *score + Mat[j][dec];
        }
        else if((Mat[j][dec]) == (Mat[j][dec+3]) && (Mat[j][dec+1]) == 0 && Mat[j][dec+2] == 0) /* avec 2 cases à 0 d'écart */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+3] = 0;
            *score = *score + Mat[j][dec];
        }

        dec = dec + 1;

        if(Mat[j][dec] == Mat[j][dec+1]) /* cases cote à cote */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+1] = 0;
            *score = *score + Mat[j][dec];
        }
        else if(Mat[j][dec] == Mat[j][dec+2] && Mat[j][dec+1] == 0) /* avec une case à 0 d'écart */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+2] = 0;
            *score = *score + Mat[j][dec];
        }

        dec = dec + 1;

        if(Mat[j][dec] == Mat[j][dec+1]) /* cases cote à cote */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+1] = 0;
            *score = *score + Mat[j][dec];
        }
    }

}

void upmove(int** Mat, int cases, int ligne) /* déplacement vers le haut */
{
    int i, j, conteur;

    for(j = 0; j < cases; j++)
    {
        do
        {   conteur = 0;
            for(i = 0; i < ligne - 1; i++)
            {
                if(Mat[j][i] == 0 && Mat[j][i+1] != 0)
                {
                    Mat[j][i] = Mat[j][i+1];
                    Mat[j][i+1] = 0;
                }
            }
        }while(conteur != 0);
    }
}

void downfusion(int** Mat, int cases, int ligne, int* score) /* fusion en haut */
{
    int j, dec;

    for(j = 0; j < cases; j++)
    {
        dec = ligne - 1;

        if(Mat[j][dec] == Mat[j][dec-1]) /* cases cote à cote */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec-1] = 0;
            *score = *score + Mat[j][dec];
        }
        else if(Mat[j][dec] == Mat[j][dec-2] && Mat[j][dec-1] == 0) /* avec une case à 0 d'écart */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec-2] = 0;
            *score = *score + Mat[j][dec];
        }
        else if((Mat[j][dec]) == (Mat[j][dec-3]) && (Mat[j][dec-1]) == 0 && Mat[j][dec-2] == 0) /* avec 2 cases à 0 d'écart */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec-3] = 0;
            *score = *score + Mat[j][dec];
        }

        dec = dec - 1;

        if(Mat[j][dec] == Mat[j][dec+1]) /* cases cote à cote */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+1] = 0;
            *score = *score + Mat[j][dec];
        }
        else if(Mat[j][dec] == Mat[j][dec+2] && Mat[j][dec+1] == 0) /* avec une case à 0 d'écart */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+2] = 0;
            *score = *score + Mat[j][dec];
        }

        dec = dec - 1;

        if(Mat[j][dec] == Mat[j][dec+1]) /* cases cote à cote */
        {
            Mat[j][dec] = 2 * Mat[j][dec];
            Mat[j][dec+1] = 0;
            *score = *score + Mat[j][dec];
        }
    }

}

void downmove(int** Mat, int cases, int ligne) /* déplacement vers le haut */
{
    int i, j, conteur;

    for(j = 0; j < cases; j++)
    {
        do
        {   conteur = 0;
            for(i = ligne - 1; i > 0; i--)
            {
                if(Mat[j][i] == 0 && Mat[j][i-1] != 0)
                {
                    Mat[j][i] = Mat[j][i-1];
                    Mat[j][i-1] = 0;
                    conteur = conteur + 1;
                }
            }
        }while(conteur != 0);
    }
}



