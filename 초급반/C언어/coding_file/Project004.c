#include<stdio.h>
#define STAR 1
#define NULL 0

void main()
{
	int arr[5][5] = {
		{1,1,1,1,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,0,0,0,1},
		{1,1,1,1,1}, };

		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				if (arr[y][x] == STAR)
					printf("¡Ú");
				else if (arr[y][x] == NULL)
					printf("  ");
			}
			printf("\n");
		}
}