#include<stdio.h>

void main()
{
	int Kor, Eng, Math, Sum;
	float Avg;
	printf("1�� ����\n");
	printf("�������� ������ �Է��Ͻÿ� \n");
	printf("���� : ");
	scanf("%d", &Kor);
	printf("���� : ");
	scanf("%d", &Math);
	printf("���� : ");
	scanf("%d", &Eng);
	Sum = Eng + Kor + Math;
	Avg = (float)(Sum) / 3.0;

	printf("�������� : %d  �������� : %d  ���� ���� : %d\n", Kor, Math, Eng);
	printf("�������� : %d  ������� : %.2f  ", Sum, Avg);
	if (Avg >= 90)
		printf("��� : A");
	else if (Avg < 90 && Avg >= 80)
		printf("��� : B");
	else if (Avg < 80 && Avg >= 70)
		printf("��� : C");
	else if (Avg < 70 && Avg >= 60)
		printf("��� : D");
	else
		printf("��� : F");

	
}