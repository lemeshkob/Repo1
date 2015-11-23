#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "windows.h"

int main()
{
     srand(time(NULL));
    int i,j;
    int n = 0;
    int m = 0;
    int sum = 0, sum1=0, sum2=0;
    int bdiap = 0;
    int ediap = 0;
    puts("Enter n & m (sizes of matrix)");
    scanf("%i %i", &n, &m);
        int array[n][m];
    int sumNotMain = 0;
    puts("Enter diapazone of random nubers in your matrix");

    scanf("%i %i", &bdiap, &ediap);

   for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {

            array[i][j] = rand()% (ediap-bdiap) + bdiap;
            printf("%i     ", array[i][j]);
        }
        puts("\n");
    }
    for (i = 0; i < n; i++)
        {
        for (j = 0; j < m; j++)
        {
                sum += array[i][j];
        }
    }
    printf("Sum of all elements = %i \n", sum);
    int sumRows = 0;
    for(i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            sumRows += array[i][j];
        }
    printf("\n Sum elements row # %d = %d\n", i+1, sumRows);
    sumRows = 0;
    }
    puts("\n");
    int sumColums = 0;
    j = 0;
     for (j = 0; j < m; ++j)
    {
        for (i = 0; i  < n; ++i)
        {
            sumColums += array[i][j];
        }
    printf("\n Sum elements colum # %d = %d\n", j+1, sumColums);
    sumColums = 0;
    }
    int sumMain = 0;
    for(i = 0; i < n; ++i)
    {
        for (j = 0; j < m; ++j)
        {
            if ( i == j)
            {

            sumMain += array[i][j];

            }
        }

    }
 printf("\nSum of main diag = %i\n ", sumMain);



 for (i = n-1;  i >= 0 ; i--)
 {
    for(j = 0; j < m; j++)
       {
           if(i+j == m-1)
           {

            sumNotMain += array[i][j];

           }
        }
     }
     printf("Sum of elements 2nd diag = %i \n" , sumNotMain);


     int underSum;
      underSum= 0;
     m =1;
    for(i = 1; i < n; ++i )
    {
        for(j = 0; j < m; ++j)
        {
            underSum += array[i][j];
        }
        m++;
    }
    printf("Sum under main diag = %i", underSum);

    int maxEl = array[0][0];
    for(i = 0; i < n; ++i)
    {
        for(j = 0; j< m; ++j)
        {
            if(array[i][j] > maxEl)
                {
                    maxEl = array[i][j];
                }
            }
        }
    int minElement  = array[0][0];
    int minIndexI = 0;
    int minIndexJ = 0;
        for(i = 0; i < n; ++i)
        {
            for(j = 0; j< m; ++j)
            {
                if(array[i][j] < minElement)
                    {
                        minElement = array[i][j];
                        minIndexI = i;
                        minIndexJ = j;
                     }
            }
        }
    printf("\n Max element  = %i ", maxEl);
    printf("\nMin index is (%i, %i)", minIndexI, minIndexJ);
 }



