#include<stdio.h>

void main()
{
	FILE* f = fopen("GoGoDan.txt", "w");
	
	for (int i = 2; i < 10; i++)
	{
		fprintf(f, "========%d��========\n", i);
		for (int j = 1; j < 10; j++)
		{
			fprintf(f, "%d x %d = %d\n", i, j, i * j);
		}
		fprintf(f, "==================\n\n", i);
	}
	fclose(f);
}