#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int exec(int op, int a, int b);

int main() {
	int resultofNum = 2%3;
	printf("result = %i", resultofNum);
	return resultofNum;
}	
	//2.5%0.5
/*    int a = 0, b = 0, c = 0; 
    int result;
    result = exec(a, b, c);
    printf("%i", result);
    return 0;
}


int exec(int op, int a, int b) {
	int result;
	
	if(op < 0){
		int swap;
		swap = a;
		a = b;
		b = swap;		
	}

	switch (op)
	{
	case 0:
		result = -a;
		break;
	case 1:
		result = a + b;
		break;
	case 2:
		result = a - b;
		break;
	case 3:
		result = a*b;
		break;
	case 4:
		result = a / b;
		break;
	case 5:
		result = abs(a);	
		break;
	case 6:
		pow(a, b);		
		break;
	case 7:
	case 13:
	case 77:
		result = a%b;
		break;
	case 8:
		//max(a,b;
		if (a > b){
			result = a;
		}
		else if(b > a){
			result = b;
		}
		else {
			result = 0;
		}
		break;
	case 9:
		//min(a,b)
		if (a < b){
			result = a;
		}
		else if(b < a) {
			result = b;
		}
		else {
			result = 0;
		}
		break;
	case 10:
		switch (abs(b)%8)
		{
		case 0:
			result = abs(a)*sizeof(char);
			break;
		case 1:
			result = abs(a)*sizeof(signed char);
			break;
		case 2:
			result = abs(a)*sizeof(short);
			break;
		case 3:
			result = abs(a)*sizeof(unsigned int);
			break;
		case 4:
			result = abs(a)*sizeof(long);
			break;
		case 5:
			result = abs(a)*sizeof(unsigned long long);
			break;
		case 6:
			result = abs(a)*sizeof(float);
			break;
		case 7:
			result = abs(a)*sizeof(double);
			break;
		}
		break;
	case 11:
		result = (3+1)*cos(b*M_PI)/(a-2);
		break;
	
	default:
		if (op < 100) {
			result = (op%abs(a + 1)) + (op%abs(b + 1));
		}
		else if (op >= 100)
		{
			result = -1;
		}
		break;
	}

	return result;
}
*/
