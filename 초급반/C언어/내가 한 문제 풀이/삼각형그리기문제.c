#include<stdio.h>

void main()
{
	int i;
	printf("���� �Է� :");
	scanf("%d", &i);
	for (int k = 1; k <= i; k++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (j <= k)
				printf("��");
			else
				printf("  ");
		}
		printf("\n");
	}
}


