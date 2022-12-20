#include<stdio.h>
#include<string.h>

int main()
{
	int n, sum, count;
	char oxchar[80];

	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		sum = 0, count = 1;
		scanf("%s", oxchar);
		for (int j = 0; j < strlen(oxchar); j++)
		{
			if(oxchar[j]=='O')
			{
				sum += count;
				count++;
			}
			if (oxchar[j] == 'X')
			{
				count = 1;
			}
		}			
		printf("%d\n", sum);
	}
	return 0;
}