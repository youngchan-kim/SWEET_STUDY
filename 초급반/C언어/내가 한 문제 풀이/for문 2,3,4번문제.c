#include<stdio.h>

void main()
{
	int date = 0, i = 1, sum = 0;
	printf("2번문제\n");
	printf("30일동안 저축한 금액 : ");
	for (date = 1; date <= 30; date++)
	{
		sum += i;
		i *= 2;
	}
	printf("%d\n", sum);


	sum = 0;
	printf("3번문제\n");
	printf("1 ~ 1000사이의 합 : ");
	for (i = 1; i <= 1000; i++)
	{
		if (i % 3 != 0)
		{
			sum += i;
		}
		else if (i % 3 == 0 && i % 5 == 0)
		{
			sum += i;
		}
	}
	printf("%d\n", sum);
	printf("(3의 배수는 제외하며 3과 5의 공배수는 제외하지 않는다)\n");

	printf("4번문제\n");
	printf("10000을 넘기 직전의 수\n");
	i = 0;
	int Psum = 0;
	sum = 0;
	for (i = 1; Psum < 10000; i += 2)
	{
		Psum += i;
		sum = Psum - i;
	}
	printf("i : %d   sum : %d\n", i - 2, sum);
}
