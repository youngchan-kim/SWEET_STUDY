#include<stdio.h>

int main()
{
	int input, inputA, inputB;

	scanf("%d", &input);
	for (int i = 1; i <= input; i++)
	{
		scanf("%d %d", &inputA, & inputB);
		printf("Case #%d: %d + %d = %d\n", i, inputA, inputB, inputA + inputB);
	}
	return 0;
}
