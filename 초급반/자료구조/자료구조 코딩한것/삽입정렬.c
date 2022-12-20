#include<stdio.h>
#include<Windows.h>
#include<time.h>

#define ARR_MAX	10
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
	for (int i = 0; i < arr_MAX; i++)
	{
		RNum = (rand() % RNum_MAX) + 1;
		arr[i] = RNum;
	}
	Print(arr, len);
}

void Asce(int arr[], int len)
{
	int tmp;
	for (int i = 1; i < len; i++) {//흐름제어
		for (int j = 0; j < i; j++) {//흐름제어
			//왼쪽인덱스의 데이터가 오른쪽 인덱스의 데이터보다 크면 swap해줘야되
			if (arr[j] > arr[i])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	Print(arr, len);
}

void Desc(int arr[], int len)
{
	int tmp;
	for (int i = 1; i < len; i++) {//흐름제어
		for (int j = 0; j < i; j++) {//흐름제어
			//왼쪽인덱스의 데이터가 오른쪽 인덱스의 데이터보다 크면 swap해줘야되
			if (arr[j] < arr[i])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	Print(arr, len);
}

void main() {

	int arr[arr_MAX] = { NULL };
	int num;
	int len = sizeof(arr) / sizeof(int);
	srand(time(NULL));

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
			Asce(arr, len);
			break;
		case 3:
			Desc(arr, len);
			break;
		case 4:
			return;
		}
	}
}