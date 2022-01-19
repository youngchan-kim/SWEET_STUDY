#include<stdio.h>

int Cumulative_Total(int input)
{

	if (input <= 0)
		return 0;
	return 	Cumulative_Total(input - 1) + input;
}

void Conversion(int input)
{
	if (input <= 0)
		return;
	else
		Conversion(input / 2);
	printf("%d", input % 2);
}

void main()
{
	int input, sum = 0;
	printf("1.정수 입력 : ");
	scanf("%d", &input);

	printf("1 ~ %d : %d\n", input, Cumulative_Total(input));

	printf("2. 정수 입력 : ");
	scanf("%d", &input);
	printf("%d -> ", input);
	Conversion(input);
}
