#include<stdio.h>


void Number(int n)
{
	int i = 0;
	int a, b, c;

	while (n != 0)
	{
		int x = n;

		if (n < 100)
		{
			i++;
		}
		else if (100 <= n && n != 1000)
		{
			a = x % 10;
			x /= 10;
			b = x % 10;
			x /= 10;
			c = x % 10;
			if ((a - b) == (b - c))
			{
				i++;
			}
		}
		n--;
	}
	printf("%d", i);
}
int main()
{
	int n;
	scanf("%d", &n);

	Number(n);

	return 0;
}