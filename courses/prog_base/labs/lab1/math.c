#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double checking(double x, double y, double z, int n0, int n1){
	// checkup a0;
	
	if (x==y){
		return 0;
	}	
	
	if (z==0){
		return 0;
	}
	
	 double poweredNumber = pow(x - y, 1 / z);
    if ((poweredNumber == 0) || isnan(poweredNumber)) {
        return 0;
    }

	// checkup a1;
	
	if (((n0 + 1) * fabs(x + y)) == 0){
		return 0;
	}
	
	// checkup a2;
	
	if (sin(x)==0){
		return 0;
	}
	
	//all is OK;
	
	return 1;
	}
	


	
	double calc (double x, double y, double z) {
    double a0, a1, a2;
        
    int n0 = 3;
    int n1 = 2;
    
    if (checking(x, y, z, n0, n1) == 0) {
        return NAN;
    }
    
    a0 = pow(x, y + 1) / pow(x - y, 1 / z);
    a1 = y / ((n0 + 1) * fabs(x + y));
    a2 = pow(n1 + sin(y),cos(x) / (z + fabs(x - y)));
    
    double a = a0 + a1 + a2;
    
    return a;
}
int main(){
	
	double x = 0;
	double y = 0;
	double z = 0;
	double result;
	
	result = calc(x,y,z);
	
	printf("%.12f", result);
    return 0;
}

