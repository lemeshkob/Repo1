#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int main()
{
    srand(time(NULL));
    int M = 0,N = 0,L = 0;
    int i,j,k;
    int bdiap = 0;//begin of diapazone
    int ediap = 0;//end of diapazone
    puts("Enter size of your parallelepiped (NxMxN)");
    scanf("%i %i %i", &N, &M, &L);
    puts("Enter a diapazone of integer numbers that will fill your parallelepiped ");
    scanf("%i %i", &bdiap, &ediap);
    int array[N][M][L];

    for (i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            for (k = 0; k < L; ++k)
            {
                array[i][j][k] = rand()%(ediap - bdiap) + bdiap;
                printf("%i ", array[i][j][k]);

            }
            puts("\n");
        }
        puts("\n");
    }

    //char array[N][M][L];


   /*
   puts("Here you have parallelepiped filled with random symbols");
   for (i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            for (k = 0; k < L; ++k)
            {
                array[i][j][k] = rand() + 1;
                printf("%c ", array[i][j][k]);
            }
            puts("\n");
        }
        puts("\n");
    }*/
    //int array[3][3][3];only for cube =(^_^)=
    /*int sum = 0;
    for (i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            for (k = 0; k < L; ++k)
            {
                array[i][j][k] = rand()%(ediap - bdiap) + bdiap;
                printf("%i ", array[i][j][k]);
                sum += array[i][j][k];
            }
            puts("\n");
        }
        puts("\n");
    }
    printf("\nSum = %i", sum);*/
    /*int sumMain = 0;

    for (i = 0; i < 3; ++i)
    {
        for(j = 0; j < 3; ++j)
        {
            for (k = 0; k < 3; ++k)
            {
                array[i][j][k] = rand()%(ediap - bdiap) + bdiap;
                printf("%i ", array[i][j][k]);
                if(j==k)
                {

                    sumMain +=array[i][j][k];
                }
            }
            puts("\n");
        }
        puts("\n");
    }
    printf("\n Sum of main diag = %i ", sumMain);
*/
   /* int maxIndexI = 0;
    int maxIndexJ = 0;
    int maxIndexK = 0;

    for (i = 0; i < N; ++i)
        {
            for(j = 0; j < M; ++j)
            {
                for (k = 0; k < L; ++k)
                {
                    array[i][j][k] = rand()%(ediap - bdiap) + bdiap;
                    printf("%i ", array[i][j][k]);

                }
                puts("\n");
            }
            puts("\n");
        }
*/
/*             int maxElement = 0;
     maxElement = array[0][0][0];

        for (i = 0; i < N; ++i)
        {
            for(j = 0; j < M; ++j)
            {
                for (k = 0; k < L; ++k)
                {
                    if(array[i][j][k] >= maxElement)
                    {
                        maxElement = array[i][j][k];
                        maxIndexI = i;
                        maxIndexJ = j;
                        maxIndexK = k;
                    }
                }

            }

        }
        printf("\n Max element = %i ", maxElement);
        printf("\n Max index (i,j,k) =  (%i, %i, %i) ", maxIndexI, maxIndexJ, maxIndexK);
*/

    puts("Here you have your swaped max & min elements");
    int minValue = array[0][0];
    int maxValue = array[0][0];
    int swap = 0;
    int x1=0,y1=0, z1 = 0,x2=0,y2=0, z2 = 0;
    for(i = 0; i < N; ++i)
    {
        for(j = 0; j < M; ++j)
        {
            for(k = 0; k < L; ++k)
            {
                if(array[i][j][k] > maxValue)
            {
                maxValue = array[i][j][k];
                x1 = i;
                y1 = j;
                z1 = k;
            }
            if (array[i][j][k] < minValue)
            {
                minValue = array[i][j][k];
                x2 = i;
                y2 = j;
                z2 = k;
            }
            }
        }
    }

    swap = array[x1][y1][z1];
    array[x1][y1][z1] = array[x2][y2][z2];
    array[x2][y2][z2] = swap;

     for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            for(k = 0; k < L; ++k)
            {
                printf("%i  ", array[i][j][k]);
            }
        puts("\n");
        }
    puts("\n");
    }

}
