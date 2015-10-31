#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/* Заповнює масив випадковими цілими числами в діапазоні [1..99] (включно) */
void fillRand1(int arr[], int size)
{
	int i;
	for (i = 1; i < size; ++i)
	{
		arr[i] = (rand()&99 + 1);
	}
}

/* Перевіряє чи всі елементи масиву знаходяться у діапазоні [1..99] (включно). Повертає 1, якщо умова задовольняється і 0 - якщо не задовольняється */
int checkRand1(int arr[], int size)
{
	int i;
	for(i = 0; i < size; ++i)
	{
		if(arr[i] >= 1 && arr[i] <= 99)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

/* Знаходить середнє значення серед елементів масиву */
float meanValue(int arr[], int size)
{
	int i;
	double sum = 0, meanValue;
	for(i = 0; i < size; ++i)
	{
		 sum += arr[i];
		 meanValue = sum / size;
	}
	return meanValue;
}

/* Знаходить мінімальний серед елементів масиву */
int minValue(int arr[], int size)
{
	int i;
	int minValue;

	minValue = arr[0];
	for(i = 0; i < size; ++i)
	{
		if (arr[i] < minValue )
		{
			minValue = arr[i];
		}
	}
	return minValue;
}

/* Знаходить індекс першого елементу, значення якого найближче до середнього значення серед елементів масиву */
int meanIndex(int arr[], int size)
{
	int i,j;
	double sum = 0, meanValue;
	int meanIndex;

	for(i = 0; i < size; ++i)
	{
		 sum += arr[i];
	}
	meanValue = sum / size;
	printf("%f\n", meanValue);
	for(i = 0; i < size; ++i)
	{
		if((arr[i] > arr[meanIndex] && arr[i] <= meanValue) || (arr[i] < arr[meanIndex] && arr[i] >= meanValue))
		{
			meanIndex = i;
		}
	}
	return meanIndex;
}

/* Знаходить індекс першого мінімального елемента масиву */
int minIndex(int arr[], int size)
{
	
	int i;
	int minValue;
	int minIndex = 0;

	minValue = arr[0];
	for(i = 0; i < size; ++i)
	{
		if (arr[i] < minValue )
		{
			minValue = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int maxIndex(int arr[], int size)
{
	
	int i;
	int maxValue;
	int maxIndex = 0;

	maxValue = arr[0];
	for(i = 0; i < size; ++i)
	{
		if (arr[i] > maxValue )
		{
			maxValue = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

/* Знаходить значення, яке найчастіше зустрічається у масиві. Якщо таких декілька, повертає більше з них*/
int maxOccurance(int arr[], int size)
{
	int i,j,maxIndex1;
	//int	maxOccurance;
	int* countArr = (int*) calloc(size - 1, sizeof(int));

	for(i = 0; i < size - 1; ++i)
	{
	//	int current = arr[i];
	//	int count = 1;
		for(j = i + 1; j < size; ++j)
		{
			
			if(arr[i] == arr[j])
			{
				++countArr[i];
			}
		}
	}
	maxIndex1 = maxIndex(countArr,size-1);
	free(countArr);
	return arr[maxIndex1];
}

/* ділення */
void div(int arr1[], int arr2[], int res[], int size)
{
	int i;

	for(i = 0; i < size; ++i)
	{
		if(arr2[i] == 0)
		{
			printf("ERROR arr2[%i] = 0\n", i );
			return;
		}
		res[i] = arr1[i]/arr2[i];
	}
}

/* lteq - less than or equals */
int lteq(int arr1[], int arr2[], int size)
{
	int i;

	for(i = 0; i < size; ++i)
	{
		if(arr1[i] > arr2[i])
		{
			return 0;
		}
	}
	return 1;
}
// !(a<=b) = a>b 

/* lxor - logical XOR */
void lxor(int arr1[], int arr2[], int res[], int size)
{
	int i;

	for(i = 0; i < size; ++i)
	{
		res[i] = arr1[i]^arr2[i];
	}
}
int main()
{
	int arr[5];
	int i;
	/*for(i = 0; i < 5; ++i)
	{
		scanf("%d", &arr[i]);
	}
	printf("%i\n", function(arr,5));
	*/
	srand(time(NULL));
	getchar();
	return 0;
}