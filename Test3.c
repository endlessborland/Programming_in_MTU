#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
float a, b, c, d;
float x1, x2;
printf("Enter a, b and c\n");
scanf("%f%f%f", &a, &b, &c);
if (a==0 && c!=0) {
	x1 = -b/c;
	printf("x = %f\n", x1);
	return 0;
}
if (a==0 && c==0) {
	printf("x = 0\n");
	return 0;
}
d = pow(b,2) - 4*a*c;
if (d < 0) {
	printf("No real solution\n");
	return 0;
}
d = sqrt(d);
x1 = (-b-d)/(2*a);
x2 = (-b+d)/(2*a);
printf("x1 = %f\nx2 = %f\n", x1, x2);
return 0;
}
