#include<stdio.h>
#include<Windows.h>
#include<time.h>
void main() {
	/*
	�迭�� �̿��� ����
	���� ����(Selection sort)
	�� ���� �����ͺ��� ���������� �����ϴ� ���
	*/
	int arr[10] = {0};
	int tmp; //�ӽ����庯��
	int len = sizeof(arr) / sizeof(int);
	//swap : �����ͱ�ȯ
	/*
	tmp = arr[0];//tmp������ ������� �����͸� ���
	arr[0] = arr[2];
	arr[2] = tmp;
	*/

	
	int num, RNum, temp, i = 0;
	srand(time(NULL));

	while (TRUE)
	{
		system("cls");
		printf("1. ��ȣ ����\n");
		printf("2. �������� ����\n");
		printf("3. �������� ����\n");
		printf("4. ����\n");
		printf("���� : ");
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
			for (int i = 0; i < len - 1; i++) {//�帧����
				for (int j = i + 1; j < len; j++) {//�帧����
					//�����ε����� �����Ͱ� ������ �ε����� �����ͺ��� ũ�� swap����ߵ�
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
			for (int i = 0; i < len - 1; i++) {//�帧����
				for (int j = i + 1; j < len; j++) {//�帧����
					//�����ε����� �����Ͱ� ������ �ε����� �����ͺ��� ũ�� swap����ߵ�
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