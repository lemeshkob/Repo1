
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

double calc(int n, int m)
{
int i, j;
double result = 0;
for (i = 1; i <= n; i++){
for (j = 1; j <= m; j++) {
result += (2 + i)*cos((j*M_PI) / 2);
}
}
return result;
}

int main()
{
int n, m;
puts("enter N");
scanf("%d", &n);
puts("enter M");
scanf("%d", &m);
double x = calc(n, m);
printf(" x = %f\n", x);
getchar();
return x;
}
