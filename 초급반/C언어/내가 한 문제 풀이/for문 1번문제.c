﻿#include<stdio.h>

void main()
{
	printf("1번문제\n");
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 == 0)
			continue;
		printf("%d.Hello\n", i);
	}
	printf("2번문제\n");
	for (char ch = 'A'; ch <= 'Z'; ch++)
	{
		printf("%c", ch);
		if (ch == 'M' || ch == 'Z')
		{
			printf("\r\n");
			continue;
		}
		printf(",");
	}
	printf("3번문제\n");
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		if (i % 3 == 0)
		{
			printf("%d+", i);
			sum += i;
			if (i == 9)
			{
				printf("\b=");
			}


		}
	}
	printf("%d", sum);
}
