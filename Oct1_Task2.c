#include <stdio.h>

int main(void)
{
	float x = 1;
	float input, tmp = 1;
	printf("Enter x\n");
	scanf("%f", &input);
	//x^21 за 6 операций
	x=input*input; //2
	tmp=x*x; //4
	x=tmp*tmp; //8
	x*=x; //16
	x*=tmp; //20
	x*=input; //21
	printf("x^21 = %f\n", x);
	//x^4 за шесть операций
	x=input; //а это считается за  x=input*1?
	x*=x;
	x*=x;
	x*=1; //и что мне делать оставшиеся 3 операции?
	x*=1; //умножать на единицу - весело!
	x*=1;
	printf("x^4 = %f\n", x);
	//можно я не буду каждую букву расписывать? Это долго и скучно
	return 0;
}
