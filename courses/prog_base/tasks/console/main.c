#include "stdlib.h"
#include "stdio.h"
#include "math.h"

#include "windows.h"

int main()
{
	int x = 0,y = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;

    for (y = 25; y >= 0 ; --y )
    {	if(y%2 == 0 )
    	{
    		for(x = 79; x>=0; --x);
    			printf("*");
  		}
    	else if(y&2 == 1)
    	{
    		for(x = 0; x >= 0; ++x)
    		{
    			printf("*");
    		}
    	}
    }
    return 0;
}
