#include<stdio.h>
#include<conio.h>
#define TRUE 1


void main()
{
	int i = 0, j = 1, sum = 0, Num = 1, flag = 0;
	while (TRUE)
	{
		printf("10 ~ 20 ���� ���� �Է� : ");
		scanf("%d", &i);
		if (i >= 10 && i <= 20)
			break;
		printf("�߸� �ٽ� �Է�\n");
	}
	while (j <= i)
	{
		sum += j;
		j++;
	}
	printf("1 ~ %d �����հ� : %d\n", i, sum);

	printf("2. Hello ���\n");
	while (Num <= 5)
	{
		printf("Hello\n");
		Num++;
	}

	printf("3.���� �ݺ� �Է�(0�Է� �� ����)\n");
	printf("���� �Է� : ");
	sum = 0; //�ʱ�ȭ�� ���� ���
	while (TRUE)
	{
		scanf("%d", &i);
		if (i == 0)
		{
			printf("�����հ� : %d\n", sum);
			break;
		}
		else
			printf("���� �Է� : ");
		sum += i;
	}

	printf("4.�Ҽ� �Ǻ�\n");
	printf("���� �Է� : ");
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
		printf("%d��(��) �Ҽ��Դϴ�.\n", i);
	else
		printf("%d��(��) �Ҽ��� �ƴմϴ�.\n", i);

	printf("5.�Էµ� ���� �Ųٷ� ���\n");
	printf("���� �Է� : ");
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

	printf("6.�Էµ� ���� ���ڸ� �� �հ�\n");
	printf("���� �Է� : ");
	scanf("%d", &i);
	sum = 0;
	while (i)
	{
		sum += i % 10;
		i /= 10;
	}
	printf("�����հ� : %d", sum);
}

