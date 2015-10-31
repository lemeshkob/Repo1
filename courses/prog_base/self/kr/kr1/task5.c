#include "stdlib.h"
#include "stdio.h"
#include "math.h"

const int size = 5;

int stringEquals(char firstString[], char secondString[])
{
	int i;
	int diff;
	for (int i = 0; i < size; ++i)
	{
		diff = firstString[i] - secondString[i];
		if (diff != 0)
		{
			return diff;
		} 
	}
	return 0;
}

int main()
{	
	int i;
	int diff;
	char firstString[size];
	char secondString[size];

	
		scanf("%s", &firstString);
		scanf("%s", &secondString);

	diff = stringEquals(firstString,secondString);

	if (diff < 0)
	{
		printf("%s\n", "firstString < secondString");
	}
	else if (diff > 0)
	{
		printf("%s\n", "firstString > secondString");
	}
	else if (diff == 0)
	{
		printf("%s\n", "firstString = secondString");
	}

	return diff;
}
