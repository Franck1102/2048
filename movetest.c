#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

void mathor(int** Mat, int cases, int ligne) /* test dep horizontal */
{
    int i, j;

    for(i = 0; i < ligne; i++)
    {
        for(j = 0; j < cases; j++)
        {
            if( i == 3)
            {
                Mat[0][i] = 4;
                Mat[1][i] = 4;
                Mat[2][i] = 2;
                Mat[3][i] = 2;
            }
            else
            {
                Mat[j][i] = 0;
            }
        }
    }
}

void matvert(int** Mat, int cases, int ligne) /* test dep vertical */
{
    int i, j;

    for(j = 0; j < cases; j++)
    {
        for(i = 0; i < ligne; i++)
        {
            if( j == 3)
            {
                Mat[j][0] = 4;
                Mat[j][1] = 2;
                Mat[j][2] = 0;
                Mat[j][3] = 2;
            }
            else
            {
                Mat[j][i] = 0;
            }
        }
    }
}
