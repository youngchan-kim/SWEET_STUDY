#include <iostream>
#include<Windows.h>
using namespace std;

#define MAX 5

void Print(int* num, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	system("pause");
}

void Swap(int *num, int low, int right)
{
	int tmp;
	tmp = num[low];
	num[low] = num[right];
	num[right] = tmp;
}

void Asce(int *num, int left, int right)
{
	int tmp;
	if (left > right)
		return;

	int pivot = num[right];
	int low = left;
	int high = right - 1;

	while (low <= high)
	{
		while (num[low] < pivot) low++;
		while (num[high] > pivot) high--;
		if (low < high)	Swap(num, low, high);
	}
	Swap(num, right, low);
	Asce(num, left, low - 1);
	Asce(num, low + 1, right);
}

void main()
{
	int* num = new int[MAX];

	for (int i = 0; i < MAX; i++)
	{
		cout << i + 1 << "번째 정수 : ";
		cin >> num[i];
	}

	Asce(num, 0, MAX - 1);
	Print(num, MAX);

	delete[] num;
}