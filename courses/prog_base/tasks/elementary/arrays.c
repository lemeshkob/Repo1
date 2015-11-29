#include "stdio.h"
#include "stdlib.h"

int main()
{
    int k;
    int i;
    int N = 0;
    int array[N];
    int sum = 0;
    int sumplus = 0;

    puts("Enter a quantity of numbers:");
    scanf("%i", &N);

    puts("Enter your numbers:");

    for(i = 0; i < N; ++i)
    {
         scanf("%i", &array[i]);
         printf("%i, ", array[i]);
         if( array[i] < 0)
         {
             sum+= array[i];
         }

    }

    for(i = 0; i < N; ++i)
    {
          if(array[i] < 0)
        {
            array[i] = 0;
        }
    }

    puts("\n");
    for(i = 0; i < N; ++i)
    {
        if(array[i] > 0)
        {
            printf("%i, ", array[i]);
        }
    }

    puts("\n");

    for(i = 0; i < N; ++i)
     {
         printf("%i, ", array[i]);
     }

    printf("\nSum of negative = %i", sum);
    puts("\n");

    puts("Next:");
    for(i = 0; i <N; ++i) // it is not correct
    {
        for(k = i + 1; k < N; ++k)
        {
            array[i] += array[k];
        }

        printf("%i, ", array[i]);
    } 

    puts("\n");

    /*for(i = 0; i < N; ++i )
    {


        array[i] = array[i]-array[i+1];
        array[(N-1)] = 0;
        printf("%i ", array[i]);
    }*/
    return 0;
}
