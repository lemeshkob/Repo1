#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <time.h>


void Pos(int X,int Y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X=X;
    pos.Y=Y;
    SetConsoleCursorPosition(hConsole, pos);
}

void Eror()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    Pos(3,16);
    SetConsoleTextAttribute(hConsole,7);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
    printf("Invalid !!! Enter help!");
    SetConsoleTextAttribute(hConsole,7);
}

void Clear()
{
    int i;
    for(i=0; i<=12; i++)
    {
        Pos(3,15+i);
        puts("                                                                                           ");
    }
}

void fRandom(float *mas,int N, int M,int F,int S)
{
    int i,j;
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)

            *(mas+i*(N)+j)=pow((rand()%127+1),-1)+rand()%(S-F)+F;
}

void PrintMatrix(float *mas,int N, int M)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i,j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
            Pos(35-N*3+j*6+j,6-M/2+i);
            printf("%.2lf\t",*(mas+i*(N)+j));
        }
        printf("\n");
    }
}

void Dark(float *mas,int N, int M)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i,j;
    for(i=0; i<M; i++)
    {
        for(j=0; j<N; j++)
        {
            SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
            Pos(35-N*3+j*6+j,6-M/2+i);
            printf("%.4lf\t",*(mas+i*(N)+j));
        }
        printf("\n");
    }
}
void PrintConsole(int N,int M)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    int i,j;
    for(i=0; i<80; i++)
        for(j=0; j<=12; j++)
        {
            Pos(i,j);
            SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE | BACKGROUND_RED );
            printf(" ");
        }
}

void fClean(float *mas,int N,int M)
{
    int i,j;
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            *(mas+i*(N)+j)=0;
}

void fHflip(float *mas,int N,int M)
{
    int i,j;
    float c;
    for(i=0; i<M/2; i++)
        for(j=0; j<N; j++)
        {
            c=*(mas+i*N+j);
            *(mas+i*N+j)=*(mas+(M-i-1)*N+j);
            *(mas+(M-i-1)*N+j)=c;
        }
}

float fSum(float *mas,int N,int M)
{
    int i,j;
    float sum=0;
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            sum+=*(mas+i*(N)+j);
    return sum;
}
float fSumColum(float*mas,int N,int M,int R)
{
    int i,j;
    float sum=0;
    for(j=0; j<M; j++)
    {
        sum+=*(mas+j*N+R);

    }
    return sum;
}

void fChanFmaxLmin (float * mas,int N,int M)
{
    int i,j;
    float c;
    float Fmax=*mas,Lmin=*mas;
    int z=0,x=0,q=0,w=0;
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            if(Fmax<=*(mas+i*(N)+j))
            {
                Fmax=*(mas+i*(N)+j);
                z=i;
                x=j;
            }
            else if(Lmin>*(mas+i*(N)+j))
            {
                Lmin=*(mas+i*(N)+j);
                q=i;
                w=j;
            }
    c=*(mas+z*(N)+x);
    *(mas+z*(N)+x)=*(mas+q*(N)+w);
    *(mas+q*(N)+w)=c;
}

void fChanLmaxLmin (float*mas,int N,int M)
{
    int i,j;
    float c;
    float Fmax=*mas,Lmin=*mas;
    int z=0,x=0,q=0,w=0;
    for(i=0; i<M; i++)
        for(j=0; j<N; j++)
            if(Fmax<=*(mas+i*(N)+j))
            {
                Fmax=*(mas+i*(N)+j);
                z=i;
                x=j;
            }
            else if(Lmin>=*(mas+i*(N)+j))
            {
                Lmin=*(mas+i*(N)+j);
                q=i;
                w=j;
            }
    c=*(mas+z*(N)+x);
    *(mas+z*(N)+x)=*(mas+q*(N)+w);
    *(mas+q*(N)+w)=c;

}

void fChanMaxAndMinCol(float*mas,int N,int M)
{
    int i,j;
    float c;
    float SumCol[N];
    float MaxC,MinC;
    int q=0,b=0,v=0;
    for(q=0; q<N; q++)
        SumCol[q]=0;
    q=0;
    for(j=0; j<N; j++)
    {
        for(i=0; i<M; i++)
            SumCol[q]=SumCol[q]+*(mas+N*i+j);
        q++;
    }
    MaxC=SumCol[0];
    MinC=SumCol[0];
    for(q=1; q<N; q++)
        if(MaxC<SumCol[q])
        {
            MaxC=SumCol[q];
            b=q;
        }
        else if(MinC>SumCol[q])
        {
            MinC=SumCol[q];
            v=q;
        }
    for (i=0; i<M; i++)
    {
        c=*(mas+i*N+b);
        *(mas+i*N+b)=*(mas+i*N+v);
        *(mas+i*N+v)=c;
    }

}

void DeletSpace(char text[78])
{
    int a;
    while(text[0]==' ')
    {
        for(a=0; a<=77; a++)
            text[a]=text[a+1];
    }
    text[78]=' ';
}
char * DelSp(char text[78])
{
    int i,j;
    static char test[78];
    for(i = j = 0; i<78; i++)
        if(text[i] != ' ')
            test[j++] = text[i];
    test[j] = '\0';
    return test;
}

void Exit(void)
{
    int i;
    int j;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    for(i=0; i<80; i++)
        for(j=0; j<35; j++)
        {
            Pos(i,j);
            SetConsoleTextAttribute(hConsole,7);
            printf(" ");
        }
}

int main(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
     const char *comand[]= {" ",
                           "exit                                \t\texit from programm",
                           "clean                               \t\tset all elements to 0",
                           "random bdiap ediap                \t\tfill matrix in diapazone from bdiap to ediap( ediap > bdiap && ediap > 0!!! if not result is not correct)",
                           "change_num x y num             \t\twill change number on coordinates x y",
                           "hflip                                   \twill flip your matrix horizontaly",
                           "sumall                                  \twill calculate sum of all elements in matrix",
                           "sumcol N                           \t\twill find sum of colum N",
                           "changefmaxfmin                               Change(swap) first max and first min elements",
                           "changelmaxlmin             \t\t\twill chane(swap) last max and min elements",
                           "changemaxmincol            \t\t\twill change max and min collum "
                          };

    int N=0,M=0;
    int A,B,chek=0;
    int R;
    int i;
    int D;
    float C;
    int r=0;
    int F=0,S=1;
    char text[78];
    char * text1;
    text1=NULL;
    srand(time(NULL));
    for(pos.Y=7; pos.Y<=13; pos.Y++)
    {

        for(pos.X=24; pos.X<=56; pos.X++)
        {
            Pos(pos.X,pos.Y);
            SetConsoleTextAttribute(hConsole,BACKGROUND_BLUE | BACKGROUND_RED );
            printf(" ");
        }
        printf(" \n");
    }
    while(chek==0)
    {

        Pos(33,10);
        puts("                         ");
        Pos(27,8);
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
        printf("Enter columns (1..10)");
        Pos(33,10);
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
        gets(text);
        N=atoi(text);
        if (N<1||N>10)
        {
            Pos(34,12);
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
            printf("Invalid range");
            chek=0;
        }
        else chek=1;
    }
    chek=0;
    while(chek==0)
    {
        Pos(33,10);
        puts("                         ");
        Pos(27,8);
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
        printf("    Enter rows   (1..11)");
        Pos(33,10);
        SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
        gets(text);
        M=atoi(text);
        if (M<1||M>11)
        {
            Pos(34,12);
            SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
            printf("Invalid range");
            chek=0;
        }
        else
        {
            chek=1;
            SetConsoleTextAttribute(hConsole, 7);
            system("cls");
        }
    }
    float mas[N][M];
    fRandom((float *)mas,N,M,F,S);
    PrintConsole(N,M);
    PrintMatrix((float *)mas,N,M);
    do
    {
        Pos(0,0);
        SetConsoleTextAttribute(hConsole, 7);
        Pos(0,14);
        printf(">>                                                                                                  ");
        Pos(2,14);
        gets(text);
        DeletSpace(text);
        text1 = DelSp(text);
        if(strncmp(text1,"exit",78)==0)
        {

            Exit();
            break;
        }
        else if(strncmp(text1,"clean",78)==0)
        {
            Clear();
            fClean((float *)mas,N,M);
            PrintMatrix((float *)mas,N,M);
        }
        else if(strncmp(text,"random ",7)==0)
        {
            for(i=0; i<=12; i++)
            {
                Pos(3,15+i);
                puts("                                                                                           ");
            }
            Pos(3,16);
            printf("                  ");
            if(NULL!=strpbrk(text,"-0123456789"))
            {
                F=atoi(strpbrk(text,"-0123456789"));
                R=F;
                r=0;
                if(F>0)
                    while(abs(F)>0)
                    {

                        *(strpbrk(text,"-0123456789")+r)=' ';
                        r++;
                        F=F/10;
                    }
                else
                    *strpbrk(text,"-0123456789")=' ';
                F=R;
            }
            else
            {
                Eror();
            }
            if(NULL!=strpbrk(text,"-0123456789"))
            {
                S=atoi(strpbrk(text,"-0123456789"));
                if(S>F)
                {
                    fRandom((float *)mas,N,M,F,S);
                    PrintMatrix((float *)mas,N,M);
                }
                else
                {
                    Eror();
                }
            }
            else
            {
                Eror();
            }
        }
        else if(strncmp(text,"changenum ",9)==0)
        {
            Clear();
            Pos(3,16);
            printf("                  ");
            while(text[0]!=' ')
            {
                int a;
                for(a=0; a<=77; a++)
                    text[a]=text[a+1];
            }
            Dark((float*)mas,N,M);
            if(NULL!=strpbrk(text,"-0123456789"))
            {
                A=atoi(strpbrk(text,"-0123456789"));
                if(A<=M-1&&A>=0)
                {
                R=A;
                r=0;
                if(A>0)
                    while(A>0)
                    {

                        *(strpbrk(text,"-0123456789")+r)=' ';
                        r++;
                        A=A/10;
                    }
                else
                    *strpbrk(text,"-0123456789")=' ';
                A=R;
                }else
                Eror();
            }
            else
            {
                Eror();
            }
            if(NULL!=strpbrk(text,"-0123456789"))
            {
                B=atoi(strpbrk(text,"-0123456789"));
                if(B<=N-1&&B>=0)
                {
                R=B;
                r=0;
                if(B>0)
                    while(B>0)
                    {

                        *(strpbrk(text,"-0123456789")+r)=' ';
                        r++;
                        B=B/10;
                    }
                else
                    *strpbrk(text,"-0123456789")=' ';
                B=R;
                C=strtod(text,&text1);
                }
                else
                    Eror();
            }
            else
            {
                Eror();
            }

            if((B<=N-1&&B>=0) && (A<=M-1&&A>=0))
            if(text!=text1)
            {
                mas[A][B]=C;
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_RED );
                Pos(35-N*3+B*6+B,6-M/2+A);
                printf("%.4lf ",mas[A][B]);
            }
            else
            {
                Eror();
            }
        }
        else if(strncmp(text1,"hflip",78)==0)
        {
            Clear();
            fHflip((float*)mas, N,M);
            PrintMatrix((float *)mas,N,M);
        }
        else if(strncmp(text1,"help",78)==0)
        {
            Clear();
            for(i=1; i<=10; i++)
            {
                SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_INTENSITY  );
                Pos(3,17+i);
                puts(comand[i]);
            }
            SetConsoleTextAttribute(hConsole,7 );
        }
        else if(strncmp(text1,"sumall",78)==0)
        {
            Clear();
            float sumall;
            sumall=fSum((float*)mas,N,M);
            Pos(3,17);
            printf("Sum of all elements: %.4lf",sumall);
        }
        else if(strncmp(text,"sumcol ",7)==0)
        {
            Clear();
            if(NULL!=strpbrk(text,"-0123456789"))
            {
                D=atoi(strpbrk(text,"-0123456789"));
                if(D<=N-1&&D>=0)
                {
                    float sumcol;
                    sumcol= fSumColum((float*)mas,N,M,D);
                    Pos(3,17);
                    printf("Sum of column : %.2lf ",sumcol);
                }
                else
                {
                    Eror();
                }
            }
            else
            {
                Eror();
            }
        }
        else if(strncmp(text1,"changefmaxfmin",14)==0)
        {
            Clear();
            fChanFmaxLmin ((float *) mas,N,M);
            PrintMatrix((float *) mas,N,M);
        }
        else if(strncmp(text1,"changelmaxlmin",14)==0)
        {
            Clear();
            fChanLmaxLmin ((float *) mas,N,M);
            PrintMatrix((float *) mas,N,M);
        }
        else if(strncmp(text1,"changemaxmincol",15)==0)
        {
            Clear();
            fChanMaxAndMinCol((float *) mas,N,M);
            PrintMatrix((float *) mas,N,M);
        }
        else
        {
            Eror();
        }
    }
    while(1);
    SetConsoleTextAttribute(hConsole, 7);
    Pos(0,25);
    system("pause");
    return 0;
}
