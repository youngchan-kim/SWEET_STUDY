#include<stdio.h>

void main()
{
	int Num1, Kor, Math, Eng, Sum, Num2, Num3, Num4, Num5;
	float Evg;
	printf("1.������ �Է��Ͻÿ�. : ");
	scanf("%d", &Num1);
	(Num1 % 5 == 0) ? printf("%d ��(��) 5�� ����Դϴ�.\n", Num1) : printf("%d ��(��) 5�� ����� �ƴմϴ�.\n", Num1);

	printf("2. �������� ������ �Է��Ͻÿ�.\n");
	printf("���� ���� : ");
	scanf("%d\n", &Kor);

	printf("���� ���� : ");
	scanf("%d\n", &Math);

	printf("���� ���� : ");
	scanf("%d\n", &Eng);

	Sum = Kor + Math + Eng;
	Evg = (float)Sum / 3;

	(Evg >= 60) ? printf("��� %.2f �հ�\n", Evg) : printf("��� %.2f ���հ�\n", Evg);

	printf("3. �� ������ �Է��Ͻÿ�. : ");
	scanf("%d%d\n", &Num2, &Num3);

	(Num2 > Num3) ? printf("ū �� %d\n", Num2) : printf("ū �� %d\n", Num3);

	printf("4. ������ �Է��Ͻÿ�. : ");

	scanf("%d\n", &Num4);
	(Num4 % 3 == 0 && Num4 % 2 == 0) ? printf("%d�� ¦���̸� 3�� ��� �Դϴ�.\n", Num4) : printf("���� ����\n");
	
	printf("5. ������ �Է��Ͻÿ�. : ");

	scanf("%d\n", &Num5);
	(Num5 % 5 == 0 || Num5 % 7 == 0) ? printf("%d�� 5�� ��� �̰ų� 7�� ����Դϴ�.\n", Num5) : printf("���� ����\n");
	

	
	printf("���� ����\n");
	
	printf("%d & %d = %d\n", 12, 5, 12 & 5);
	printf("%d | %d = %d\n", 18, 3, 18 | 3);
	printf("%d ^ %d = %d\n", 14, 2, 14 ^ 2);
	printf("~20 = ~%d\n", ~20);
	printf("7 << 2 %d\n", 7 << 2);
	printf("40 >> 3 %d\n", 40 >> 3);

}