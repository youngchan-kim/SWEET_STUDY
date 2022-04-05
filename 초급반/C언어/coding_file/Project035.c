#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

void ShowStudent(Student* St)
{
	printf("======%s�л�(%d��)======\n", St->Name, St->Number);
	printf("���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}
void SetStudent(Student* St, int* StudentCount)
{
	system("cls");
	St->Number = ++(*StudentCount);
	printf("======%d�� �л�======\n", St->Number);
	printf("�̸� �Է� : ");
	scanf("%s", St->Name);
	printf("���� �Է� : ");
	scanf("%d", &St->Age);
	printf("���� �Է� : ");
	scanf("%s", St->Gender);
	printf("�г� �Է�(1~3) : ");
	scanf("%d", &St->Class);
	if ((*St).Class < 1 || &St->Class > 3)
	{
		do
		{
			printf("�г� �߸� �Է� (���� 1~3�г�)\n");
			system("pause");

			printf("�г� �Է�(1~3) : ");
			scanf("%d", &St->Class);
		} while (&St->Class < 1 || &St->Class > 3);
	}

}
void ShowStudentClass(Student* St, int* StudentCount)
{
	scanf("%d", St->Class);
	printf("��������������������1 �г⦡������������������");
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St->Class, St->Class))
		{
			St->Number = ++(*StudentCount);
			printf("======%s�л�(%d��)======\n", St->Name, St->Number);
			printf("���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
			printf("======================\n");
		}
	}
	printf("������������������������������������������������������");
}

void ShowStudentName(Student* St, int* StudentCount)
{
	scanf("%d", St->Name);
	printf("��������������������1 �г⦡������������������");
	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St->Name, St->Name))
		{
			St->Number = ++(*StudentCount);
			printf("======%s�л�(%d��)======\n", St->Name, St->Number);
			printf("���� : %d,  ���� : %s,  �г� : %d\n", St->Age, St->Gender, St->Class);
			printf("======================\n");
		}
	}
	printf("������������������������������������������������������");
}

void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;

	while (1)
	{
		system("cls");
		printf("=====�л��������α׷�=====(�� �ο� : %d)\n", StudentCount);
		printf("1.�л� ���\n");
		printf("2.�л� ���(��ȣ��)\n");
		printf("3.�л� ���(�г��)\n");
		printf("4.�г� �˻�\n");
		printf("5.�л� �˻�\n");
		printf("6.������ �л� ����\n");
		printf("7.�л� ��ü ����\n");
		printf("8.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			//StudentRegistration()
			if (StudentCount + 1 >= MAX)
			{
				printf("�л�����(50��)�� ��� á���ϴ�.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;
		case 2:

			for (int i = 0; i < StudentCount; i++)
				ShowStudent(Student_List[i]);
			system("pause");
			break;
		case 3:

		case 4:
			printf("�˻��� �г� �Է� : ");
			ShowStudentClass(Student_List, StudentCount);
			system("pause");
			break;
		case 5:
			printf("�˻��� �г� �Է� : ");
			ShowStudentName(Student_List, StudentCount);
			system("pause");
			break;
		case 6:

		case 7:

			return;
		}
	}
}