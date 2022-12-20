#include<stdio.h>

int main()
{
	int input, inputA, inputB;
	
	scanf("%d", &input);

	for (int i = 0; i < input; i++)
	{
		scanf("%d %d", &inputA, &inputB);
		printf("%d\n", inputA + inputB);
	}
	return 0;
}
