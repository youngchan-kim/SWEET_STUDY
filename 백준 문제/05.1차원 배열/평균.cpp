#include<stdio.h>

int main()
{
	int n;
	float test[1000], m = 0, avg = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%f", &test[i]);
		if (m < test[i])
			m = test[i];
	}

	for (int i = 0; i < n; i++)
	{
		test[i] = test[i] / m * 100.0;
		avg += test[i];
	}
	printf("%.2f", (avg / (float)n));
	return 0;
}