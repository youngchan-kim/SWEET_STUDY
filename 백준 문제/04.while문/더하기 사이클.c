#include<stdio.h>

int main(){
	int N, a, b, X, i = 0;
	scanf("%d", &N);
	X = N;
	if (X < 10)
		X*10;
	do
	{
		a = (X - (X % 10)) / 10;
		b = (X % 10);
		X = a + b;
		a = b * 10;
		b = X % 10;
		X = a + b;
		i++;
	} while (X != N);
	printf("%d", i);
	return 0;
}