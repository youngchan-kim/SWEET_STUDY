#include<stdio.h>
void main()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++) 
		{
			if (j + i== 6)
				printf("¡Ú");
			else
				printf("  ");
		}
		printf("\n");
	}
}