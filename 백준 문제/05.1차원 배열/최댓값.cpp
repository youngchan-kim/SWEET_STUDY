#include<stdio.h>

int main()
{
	int num;
	int max= 0, maxnum;
	for (int i = 1; i <= 9; i++)
	{
		scanf("%d", &num);
		if (max < num)
		{
			max = num;
			maxnum = i;
		}
	}
	printf("%d\n%d", max, maxnum);
	return 0;
}