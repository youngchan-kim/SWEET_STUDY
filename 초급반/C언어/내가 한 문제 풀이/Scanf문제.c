#include<stdio.h>

void main() 
{
	char str1, nstr;
	int num1;
	float Fnum, avg;
	int Kor, Math, Eng, sum;
	char Name[30];
	int Age;
	printf("====1�� ����====\n");
	printf("���Ϲ��ڸ� �Է��Ͻÿ� : ");
	scanf("%c", &str1);
	printf("������ �Է��Ͻÿ� : ");
	scanf("%d", &num1);
	nstr = str1 + num1;
	printf("%c + %d = %c\n", str1, num1, nstr);

	printf("====2�� ����====\n");
	printf("�Ҽ������� �Է��Ͻÿ� :");
	scanf("%f", &Fnum);
	printf("�Ҽ����� : %.2f\n", Fnum);

	printf("====3�� ����====\n");
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &Kor);
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &Math);
	printf("���������� �Է��Ͻÿ� : ");
	scanf("%d", &Eng);

	printf("�������� : %d\n", Kor);
	printf("�������� : %d\n", Math);
	printf("�������� : %d\n", Eng);
	sum = Kor + Math + Eng;
	avg = (float)sum / 3;
	printf("�հ����� : %d  ������� : %f\n", sum, avg);

	printf("====4�� ����====\n");
	printf("�̸��� �Է��Ͻÿ� : ");
	scanf("%s", Name);
	printf("%s���� ���̸� �Է��Ͻÿ� : ", Name);
	scanf("%d", &Age);
	printf("%s���� ���̴� %d�� �Դϴ�.", Name, Age);


}