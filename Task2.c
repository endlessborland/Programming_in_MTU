#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
float number, result;
int power;
printf("Enter number and it's power\n");
scanf("%f%d", &number, &power);
if (power < 0) {
	printf("Stop being a dick!\n");
	return 0;
}
result = pow(number,power);
printf("Your result is %f\n", result);
return 0;
}
