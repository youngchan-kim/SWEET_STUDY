#include<stdio.h>
#include<Windows.h>
#include<time.h>

#define ARR_MAX	8
#define RNum_MAX 100
#define NULL 0

void Print(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	system("pause");
}

void Create(int arr[], int len)
{
	int RNum;
	for (int i = 0; i < ARR_MAX; i++)
	{
		RNum = (rand() % RNum_MAX) + 1;
		arr[i] = RNum;
	}
	Print(arr, len);
}

void Swap(int arr[], int low, int right)
{
	int tmp;
	tmp = arr[low];
	arr[low] = arr[right];
	arr[right] = tmp;
}

void Asce(int arr[], int left, int right)
{
	int tmp;
	if (left > right)
		return;

	int pivot = arr[right];
	int low = left;
	int high = right - 1;

	while (low <= high)
	{
		while (arr[low] < pivot) low++;
		while (arr[high] > pivot) high--;
		if (low < high)	Swap(arr, low, high);
	}
	Swap(arr, right, low);
	Asce(arr, left, low - 1);
	Asce(arr, low + 1, right);
}

void Desc(int arr[], int left, int right)
{
	int tmp;
	if (left > right)
		return;

	int pivot = arr[right];
	int low = left;
	int high = right - 1;

	while (low <= high)
	{
		while (arr[low] > pivot)
			low++;
		while (arr[high] < pivot)
			high--;
		if (low < high)
			Swap(arr, low, high);
	}
	Swap(arr, right, low);
	Desc(arr, left, low - 1);
	Desc(arr, low + 1, right);
}

void main() {

	//int arr[ARR_MAX] = { 1, 2, 10, 11, 4, 12, 13, 8 };
	int arr[ARR_MAX] = { NULL };
	int num;
	int len = sizeof(arr) / sizeof(int);
	srand(time(NULL));
	int i = 0;
	while (TRUE)
	{
		system("cls");
		printf("1. 번호 생성\n");
		printf("2. 오름차순 정렬\n");
		printf("3. 내림차순 정렬\n");
		printf("4. 종료\n");
		printf("선택 : ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			Create(arr, len);
			break;
		case 2:
			Asce(arr, 0, ARR_MAX - 1);
			Print(arr, len);
			break;
		case 3:
			Desc(arr, 0, ARR_MAX - 1);
			Print(arr, len);
			break;
		case 4:
			return;
		}
	}
}