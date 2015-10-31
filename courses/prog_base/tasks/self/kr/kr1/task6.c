#include "stdlib.h"
#include "stdio.h"
#include "math.h"

int coordinates()
{
	float xa, ya, za, xb, yb, zb, xc, yc, zc;
	int AB,AC,BC;

	AB = sqrt(pow((xb-xa),2) + pow((yb-ya),2) + pow((zb-za),2));
	AC = sqrt(pow((xc-xa),2) + pow((yc-ya),2) + pow((zc-za),2));
	BC = sqrt(pow((xc-xb),2) + pow((yc-yb),2) + pow((zc-zb),2));

}

int main()
{
	float xa, ya, za, xb, yb, zb, xc, yc, zc;

	printf("%s\n","Enter x y z of A point" );
	scanf("%f %f %f", &xa, &ya, &za);
	printf("%s\n","Enter x y z of B point" );
	scanf("%f %f %f", &xb, &yb, &zb);
	printf("%s\n","Enter x y z of C point" );
	scanf("%f %f %f", &xc, &yc, &zc);

	struct points 
	{
		float pointA[3] = {xa, ya, za};
		float pointB[3] = {xb, yb, zb};
		float pointC[3] = {xc, yc, zc};
	}
}