#include<stdio.h>

void main()
{
	int arr[5][5] = { 0 };
	arr[2][-1] = 1;
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
			printf("%d", arr[y][x]);
		printf("\n");
	}
}