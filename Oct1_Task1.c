#include <stdio.h>
#define HOUR 3600
#define MINUTE 60

int main()
{
	int second;
	int hour;
	int minute;
	printf("Enter current second\n");
	scanf("%d", &second);
	hour = second / HOUR;
	minute = second / MINUTE;
	printf("Hours passed: %d\n", hour);
	printf("Minutes passed: %d\n", minute);
	return 0;
}
