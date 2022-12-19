#include<stdio.h>

int main()
{
	int t, inputA, inputB;

	scanf("%d", &t);

	for (int i = 0; i <= t; i++)
	{
		scanf("%d %d", &inputA, &inputB);
		printf("Case #%d : %d\n", i+1, inputA + inputB);
	}
	return 0;
}
