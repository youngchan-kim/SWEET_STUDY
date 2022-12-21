#include<stdio.h>
#include<Windows.h>
#include<time.h>
void main() {
	/*
	배열을 이용한 정렬
	선택 정렬(Selection sort)
	맨 앞의 데이터부터 순차적으로 정렬하는 방식
	*/
	int arr[10] = {0};
	int tmp; //임시저장변수
	int len = sizeof(arr) / sizeof(int);
	//swap : 데이터교환
	/*
	tmp = arr[0];//tmp변수에 덮어씌어질 데이터를 백업
	arr[0] = arr[2];
	arr[2] = tmp;
	*/

	
	int num, RNum, temp, i = 0;
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
			for (int i = 0; i < 10; i++)
			{
				RNum = (rand() % 99) + 1;
				arr[i] = RNum;
			}
			for (int i = 0; i < len; i++) {
				printf("%d ", arr[i]);
			}
			system("pause");
			break;
		case 2:
			for (int i = 0; i < len - 1; i++) {//흐름제어
				for (int j = i + 1; j < len; j++) {//흐름제어
					//왼쪽인덱스의 데이터가 오른쪽 인덱스의 데이터보다 크면 swap해줘야되
					if (arr[i] > arr[j]) {
						tmp = arr[i];
						arr[i] = arr[j];
						arr[j] = tmp;
					}
				}
			}
			for (int i = 0; i < len; i++) {
				printf("%d ", arr[i]);
			}
			system("pause");
			break;
		case 3:
			for (int i = 0; i < len - 1; i++) {//흐름제어
				for (int j = i + 1; j < len; j++) {//흐름제어
					//왼쪽인덱스의 데이터가 오른쪽 인덱스의 데이터보다 크면 swap해줘야되
					if (arr[i] < arr[j]) {
						tmp = arr[j];
						arr[j] = arr[i];
						arr[i] = tmp;
					}
				}
			}
			for (int i = 0; i < len; i++) {
				printf("%d ", arr[i]);
			}
			system("pause");
			break;
		case 4:
			return;
		}
	}
}