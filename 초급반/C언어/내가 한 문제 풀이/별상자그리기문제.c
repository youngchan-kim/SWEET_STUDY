#include<stdio.h>

void main()
{
	int i, j;
	printf("���ο� ���θ� �Է��Ͻÿ� :");
	scanf("%d%d", &i, &j);
	for (int y = 1; y <= i; y++)
	{
		for (int x = 1; x <= j; x++)
		{
			if (x == 1)
				printf("��");
			else if (y == 1)
				printf("��");
			else if (x == j)
				printf("��");
			else if (y == i)
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
}
