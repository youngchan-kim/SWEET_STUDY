#include<stdio.h>

void main() {
	/*
	�迭�� �̿��� ����
	���� ����(Selection sort)
	�� ���� �����ͺ��� ���������� �����ϴ� ���
	*/
	int arr[5] = { 4, 8, 2, 7, 6 };
	int tmp; //�ӽ����庯��
	int len = sizeof(arr) / sizeof(int);
	//swap : �����ͱ�ȯ
	/*
	tmp = arr[0];//tmp������ ������� �����͸� ���
	arr[0] = arr[2];
	arr[2] = tmp;
	*/
	for (int i = 0; i < len -1; i++) {
		for (int j = i + 1; j < len; j++) {
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
}