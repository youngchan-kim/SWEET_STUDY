#include<stdio.h>

void main()
{
	int arr[5] = { 10, 20, 30, 40, 50 };
	for (int i = 0; i < 5; i++)
		printf("�迭����[%d]�� �ּ� = %p, �迭����[%d]�� �� = %d\n", i, &arr[i], i, arr[i]);
	printf("\n\n");
	for (int i = 0; i < 5; i++)
		printf("�迭����[%d]�� �ּ� = %p, �迭����[%d]�� �� = %d\n", i, arr + i, i, *(arr + i));
}