#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void newgame(int** Mat, int cases, int ligne)
{
    int choix, win, lose;
    int* score = 0;
    int** M;

    initmat(M, cases, ligne);
    affichemat(M, cases, ligne);
    printf("\n\n");
    printf("score : %d", score);
    printf("\n\n");
    printf("1: haut    2 : bas     3 : droite      4 : gauche\n\n");

    while( (win == 0 || lose == 0) || (choix != 1 && choix != 2 && choix != 3 && choix != 4))
    {
        scanf("%d", &choix);

        switch(choix)
        {
            case 1 :
                system("cls");
                upfusion(M, cases, &score);
                upmove(M, cases, ligne);
                affichemat(M, cases, ligne);
                printf("\n\n");
                printf("score : %d", score);
                printf("\n\n");
                printf("1: haut    2 : bas     3 : droite      4 : gauche\n\n");
            break;

            case 2 :
                system("cls");
                downfusion(M, cases, ligne, &score);
                downmove(M, cases, ligne);
                affichemat(M, cases, ligne);
                printf("\n\n");
                printf("score : %d", score);
                printf("\n\n");
                printf("1: haut    2 : bas     3 : droite      4 : gauche\n\n");
             break;

             case 3 :
                system("cls");
                rightfusion(M, cases, ligne, &score);
                rightmove(M, cases, ligne);
                affichemat(M, cases, ligne);
                printf("\n\n");
                printf("score : %d", score);
                printf("\n\n");
                printf("1: haut    2 : bas     3 : droite      4 : gauche\n\n");
             break;

             case 4 :
                system("cls");
                leftfusion(M, ligne, &score);
                leftmove(M, cases, ligne);
                affichemat(M, cases, ligne);
                printf("\n\n");
                printf("score : %d", score);
                printf("\n\n");
                printf("1: haut    2 : bas     3 : droite      4 : gauche\n\n");

             break;
        }
    }
}

int lose(int** Mat, int cases, int ligne) /* fonction qui determine la condition de défaite */
{
    int lose = 0, i, j, conteur = 0;

    for(i = 0; i < ligne; i++)
    {
        for(j = 0; j < cases - 1; j++)
        {
            if(Mat[j][i] == Mat[j+1][i])
            {
                conteur = conteur + 1;
            }
        }
    }

    for(j = 0; j < cases; j++)
    {
        for(i = 0; i < ligne - 1; i++)
        {
            if(Mat[j][i] == Mat[j][i+1])
            {
                conteur = conteur + 1;
            }
        }
    }

    if(conteur == 0)
    {
        lose = 1;
    }
    return(lose);
}

int win(int** Mat, int cases, int ligne) /* détermine la condition de victoire */
{
    int win = 0, i, j;
    for(i = 0; i < ligne; i++)
    {
        for(j =0; j < cases; j++)
        {
            if(Mat[j][i] == 2048)
            {
                win = 1;
            }
        }
    }
    return(win);
}

void save()
{

}
