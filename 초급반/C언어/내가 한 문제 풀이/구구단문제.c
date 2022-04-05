#include<stdio.h>

void main()
{
	printf("구구단\n");
	for (int Num = 2; Num < 10; Num++)
	{
		printf("====%d단====\t", Num);
		if (Num == 9)
		{
			printf("\n");
		}
	}
	for (int i = 1; i < 10; i++)
	{
		for (int j = 2; j < 10; j++)
		{
			printf("%d x %d = %d\t", j, i, i * j);
			if (j == 9)
				printf("\n");
		}
	}
}