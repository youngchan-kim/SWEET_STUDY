#include<stdio.h>

void main()
{
	int date = 0, i = 1, sum = 0;
	printf("2������\n");
	printf("30�ϵ��� ������ �ݾ� : ");
	for (date = 1; date <= 30; date++)
	{
		sum += i;
		i *= 2;
	}
	printf("%d\n", sum);


	sum = 0;
	printf("3������\n");
	printf("1 ~ 1000������ �� : ");
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
	printf("(3�� ����� �����ϸ� 3�� 5�� ������� �������� �ʴ´�)\n");

	printf("4������\n");
	printf("10000�� �ѱ� ������ ��\n");
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
