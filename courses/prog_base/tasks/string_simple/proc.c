#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define ALLOCATE(A,B,C) ((A) calloc((B), sizeof(C)))
#define ENDL "\n"
#define ONELINE "%s\n"

const int LineLength = 64;
const int LineCount = 5;

char* process(char* resultStr, char* textLines[], int linesNum, const char* extraStr)
{
	int i;
	int sum = 0;
	for (i = 0; i < linesNum; ++i)
	{
		sum += strlen(textLines[i]) + strlen(ENDL);
	}
	resultStr = ALLOCATE(char*, sum, char);

	for (i = 0; i < linesNum; ++i)
	{
		strcat(resultStr, textLines[i]);
		strcat(resultStr, ENDL);
	}

	return resultStr;
}

void outputArray(char* arr[], int len)
{
	int i;
	for(i = 0; i < len; ++i)
	{
		printf(ONELINE, arr[i]);
	}
}

int main()
{
	int i;
	char* res;
	char** arr;
	res = ALLOCATE(char*, LineCount * LineLength, char);
	/*Array initialization*/
	arr = ALLOCATE(char**, LineCount, char*);
	for(i = 0; i < LineCount; ++i)
	{
		arr[i] = ALLOCATE(char*, LineLength, char);
		scanf("%s", (arr[i]));
	}

	printf(ENDL);
	process(res, arr, LineCount, 0);
	printf(ONELINE, process(res, arr, LineCount, 0));

	for(i = 0; i < LineCount; ++i)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}

