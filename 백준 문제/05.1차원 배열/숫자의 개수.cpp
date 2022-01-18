#include<stdio.h>

int main()
{
	int a, b, c, x, num, zero = 0, one = 0, two = 0, three = 0, four = 0, five = 0, six = 0, seven = 0, eight = 0, nine = 0;
	scanf("%d\n%d\n%d", &a, &b, &c);
	x = a * b * c;

	while(1)
	{
		num = x % 10;
		if (0 == num)
			zero++;
		else if (1 == num)
			one++;
		else if (2 == num)
			two++;
		else if (3 == num)
			three++;
		else if (4 == num)
			four++;
		else if (5 == num)
			five++;
		else if (6 == num)
			six++;
		else if (7 == num)
			seven++;
		else if (8 == num)
			eight++;
		else if (9 == num)
			nine++;
		x = x / 10;
		if (x == 0)
			break;
	}
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d", zero, one, two, three, four, five, six, seven, eight, nine);
	return 0;
}