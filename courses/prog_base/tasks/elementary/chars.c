#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "string.h"

int main(void)
{
    char ch;
    puts("enter your char");
    scanf("%c", &ch);
   if(isprint(ch))
    {
        puts("Symbol is printable");
    }
    else
        {
            puts("Symbol is not printable");
        }
    int N = 0;
    puts("How many times do you want to see it ?");
    scanf("%i", &N);
    int i;
    puts("\n");
    for (i = 0; i < N; ++i)
    {
        printf("%c ", ch);
    }
    if (isdigit(ch))
    {
        puts("\n is digit");
    }
    else
    {
        puts("\nnot a digit");

    }

    if(isalpha(ch))
    {
            puts("\n is alpha");

    }
    else
    {
        puts("not an alpha");
    }

    if(isupper(ch))
    {
        puts("is upper (2)");
    }
    else
        if(islower(ch) )
    {
        puts("is lower (1)");
    }
    else
    {
        puts("not a letter (0)");
    }

    char * array= (char*) malloc(50*sizeof(char));
    fflush(stdin);
    gets(array);

    int k;
    for(k = 0; k < strlen(array); ++k)
   // while(array[k] != '\0')
    {
        if(isdigit(array[k]))
        {
            array[k] = ' ';
        }
        printf("%c, ", array[k]);
    }

    puts("\n");
    char * mass = (char*) calloc(50,sizeof(char));
    fflush(stdin);
    gets(mass);
    int l;
    for(l = 0; l < strlen(mass); ++l)
    {
        if(islower(mass[l]))
        {
            mass[l] = toupper(mass[l]);
        }
        if(isdigit(mass[l]))
        {
            mass[l] = 57-mass[l]+48;
        }
        printf("%c ", mass[l]);
    }

    puts("\n");

    char * cat = (char*) calloc(50,sizeof(char));//just never mind. It`s only a name of array of chars
    fflush(stdin);
    gets(cat);
    int count=0;
while(!isalpha(*cat))
{
    count++;
    cat+=1;
}

    printf("first index %i ", count);

/* it doesn`t work (((
 char * noname = (char*) calloc(50,sizeof(char));
    fflush(stdin);
    gets(noname);
    char count1=0;
    char count2=0;
    char swap;
while(!isalpha(*noname))
{
    count1++;
    noname+=1;
}
while(!isdigit(*noname))
{
    count2++;
    noname+=1;
}
    swap = count1;
    count1 = count2;
    count2 = swap;

    printf("%s", noname);

    free(noname);
    free(cat);
   // free(array);
   // free(mass);
    return 0;
}
