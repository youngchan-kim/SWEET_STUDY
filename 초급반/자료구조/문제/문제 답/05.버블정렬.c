#include <stdio.h>
void main() {
	// �迭 �ʱ�ȭ
	int arr[5] = { 2, 7, 1, 3, 4 };
	int len = sizeof(arr) / sizeof(int);
	// Bubble Sort�� �������� ����-1 ��ŭ �ٱ��� �ݺ����� �ݺ��Ѵ�.(����� 4��)
	for (int i = len - 1; i > 0; i--) {
		// j�� i���� �ݺ��Ѵ�.(4�� >> 3�� >> 2�� >> 1��)
		for (int j = 0; j < i; j++) {
			// j�� ������ �ڸ��� ���� �񱳸� �Ͽ� ������ �ڸ��� ���� ������ ��ȯ�Ѵ�.
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}