#include<stdio.h>
#include<Windows.h>//system("cls"),system("pause")

void main()
{
	int Select, Kor, Math, Eng, Sum;
	float Avg;
	char Name[20];
	int Flag = 0, Check = 0;


	while (1)
	{
		system("cls");
		printf("===================\n");
		printf("    �л���������    \n");
		printf("===================\n");
		printf("  1.�л� �̸� ���\n");
		printf("  2.3���� �������\n");
		printf("  3.����Ȯ��\n");
		printf("  4.����\n");
		printf("===================\n");
		printf("�Է� : ");
		scanf("%d", &Select);

		switch (Select)
		{
			case 1:
				system("cls");
				printf("�̸� �Է� : ");
				scanf("%s", Name);
				Flag = 1;
				break;

			case 2:
				system("cls");
				printf("�������� ������ �Է��Ͻÿ�\n");
				printf("���� : ");
				scanf("%d\n", &Kor);
				printf("���� : ");
				scanf("%d\n", &Math);
				printf("���� : ");
				scanf("%d\n", &Eng);
				Sum = Kor + Math + Eng;
				Avg = (float)Sum / 3;
				Check = 1;
				break;


			case 3:
				system("cls");
				if (Flag == 0 && Check == 0) 
					printf("�̸��� �Է��ϼ���.\n������ �Է��ϼ���.\n");

				else if(Flag == 0 && Check == 1)
					printf("�̸��� �Է��ϼ���.\n");

				else if(Flag == 1 && Check == 0)
					printf("������ �Է��ϼ���.\n");

				else if (Flag == 1 && Check == 1)
				{
					printf("====================\n");
					printf("%s���� ����\n���� ���� : %d \n���� ���� : %d \n���� ���� %d \n�հ� ���� %d \n��� ���� %.2f\n", Name, Kor, Math, Eng, Sum, Avg);
					printf("====================\n");
				}
				system("pause");
				break;


			case 4:
				return;
		}
	}
}