#include<stdio.h>
#include<conio.h>
#define TRUE 1


void main()
{
	int i = 0, j = 1, sum = 0, Num = 1, flag = 0;
	while (TRUE)
	{
		printf("10 ~ 20 사이 정수 입력 : ");
		scanf("%d", &i);
		if (i >= 10 && i <= 20)
			break;
		printf("잘못 다시 입력\n");
	}
	while (j <= i)
	{
		sum += j;
		j++;
	}
	printf("1 ~ %d 누적합계 : %d\n", i, sum);

	printf("2. Hello 출력\n");
	while (Num <= 5)
	{
		printf("Hello\n");
		Num++;
	}

	printf("3.정수 반복 입력(0입력 시 종료)\n");
	printf("정수 입력 : ");
	sum = 0; //초기화를 위해 사용
	while (TRUE)
	{
		scanf("%d", &i);
		if (i == 0)
		{
			printf("최종합계 : %d\n", sum);
			break;
		}
		else
			printf("정수 입력 : ");
		sum += i;
	}

	printf("4.소수 판별\n");
	printf("정수 입력 : ");
	scanf("%d", &i);
	Num = 2;
	flag = 0;
	while (Num < i)
	{
		if (i % Num == 0)
		{
			flag = 1;
			break;
		}
		Num++;
	}
	if (flag == 0)
		printf("%d은(는) 소수입니다.\n", i);
	else
		printf("%d은(는) 소수가 아닙니다.\n", i);

	printf("5.입력된 정수 거꾸로 출력\n");
	printf("정수 입력 : ");
	scanf("%d", &i);
	while (i != 0)
	{
		printf("%d", i % 10);
		i /= 10;
	}
	/*i = 123456789
	i % 10 = 9
	i = i / 10 = 12345678
	i = 12345678
	i % 10 = 8
	i = i / 10 = 1234567
	i = 1234567
	i % 10 = 7
	i = i / 10 = 123456
	i = 123456*/

	printf("6.입력된 정수 각자리 수 합계\n");
	printf("정수 입력 : ");
	scanf("%d", &i);
	sum = 0;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	printf("최종합계 : %d", sum);
}

