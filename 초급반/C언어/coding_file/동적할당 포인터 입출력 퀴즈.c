#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<string.h>

#define MAX 50
#define TMPNUM 1

#define Gradeone 1
#define Gradethree 3

#define TRUE 1

#define NAMEMAX 10
typedef struct student
{
	char Name[NAMEMAX];
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
	printf("���� �Է� : (��~��)");
	scanf("%s", St->Gender);
	printf("�г� �Է�(1~3) : ");
	scanf("%d", &St->Class);
	if (St->Class < Gradeone || St->Class > Gradethree)
	{
		do
		{
			printf("�г� �߸� �Է�(���� 1~3�г�)\n");
			system("pause");
			printf("�г� �Է�(1~3) : ");
			scanf("%d", &St->Class);
		} while (St->Class < Gradeone || St->Class > Gradethree);
	}
}

void FullLoop(Student* St[MAX], int StudentCount)
{
	system("cls");
	for (int i = 0; i < StudentCount; i++)
		ShowStudent(St[i]);
}

void ClassSort(Student* St[MAX], int StudentCount, int searchclass)
{
	printf("��������������������%d �г⦡������������������\n", searchclass);
	for (int i = 0; i < StudentCount; i++)
	{
		if (St[i]->Class == searchclass)
		{
			ShowStudent(St[i]);
		}
	}
	printf("����������������������������������������������\n");
}

void ClassSearch(Student* St[MAX], int StudentCount)
{
	system("cls");
	int searchclass;
	printf("�˻��� �г� �Է�(1~3) : ");
	scanf("%d", &searchclass);
	ClassSort(St, StudentCount, searchclass);
}

void NameSearch(Student* St[MAX], int StudentCount)
{
	system("cls");
	char searchname[NAMEMAX];
	printf("�˻��� �л� �Է� : ");
	scanf("%s", &searchname);

	for (int i = 0; i < StudentCount; i++)
	{
		if (strcmp(St[i]->Name, searchname) == 0)
		{
			ShowStudent(St[i]);
		}
	}
}
void LastStudentDelet(Student* St[MAX], int* StudentCount)
{
	free(St[*StudentCount - 1]);
	St[*StudentCount - 1] = NULL;
	--(*StudentCount);
}

void AllStudentDelet(Student* St[MAX], int* StudentCount)
{
	for (int i = 0; i < *StudentCount; i++)
	{
		free(St[i]);
		St[i] = NULL;
	}
	*StudentCount = 0;
}


void StudentSave(Student* St[MAX], int StudentCount)
{
	FILE* f = fopen("�л�����test.txt", "w");
	fprintf(f, "%d\n", StudentCount);
	for (int i = 0; i < StudentCount; i++)
	{
		fprintf(f, "%s %d %s %d\n", St[i]->Name, St[i]->Age, St[i]->Gender, St[i]->Class);
	}
	fclose(f);
	printf("���� �Ϸ�!!\n");
}

void StudentLoad(Student* St[MAX], int* StudentCount)
{
	int Count = 0;
	FILE* f = fopen("�л�����test.txt", "r");

	if (f == NULL)
		printf("�ش� �̸��� ������ �����ϴ�.");
	else
	{
		fscanf(f, "%d", Count);

		Count += *StudentCount;

		for (int i = *StudentCount; i < Count; i++)
		{
			if (i >= MAX)
			{
				printf("�� �̻� �л��� �ҷ��� �� �����ϴ�.\n");
				system("pause");
				break;
			}
			St[i] = (Student*)malloc(sizeof(Student));
			St[i]->Number = ++(*StudentCount);
			fscanf(f, "%s", St[i]->Name);
			fscanf(f, "%d", &St[i]->Age);
			fscanf(f, "%s", St[i]->Gender);
			fscanf(f, "%d", &St[i]->Class);
		}

		fclose(f);

	}
}

void main()
{
	Student* Student_List[MAX];
	int Select;
	int StudentCount = 0;
	while (TRUE)
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
		printf("8.�л����� ����\n");
		printf("9.�л����� �ҷ�����\n");
		printf("10.����\n");
		printf("�Է� : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
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
			FullLoop(Student_List, StudentCount);
			system("pause");
			break;
		case 3:
			system("cls");
			for (int searchclass = 1; searchclass < 4; searchclass++)
			{
				ClassSort(Student_List, StudentCount, searchclass);
			}
			system("pause");
			break;
		case 4:
			ClassSearch(Student_List, StudentCount);
			system("pause");
			break;
		case 5:
			NameSearch(Student_List, StudentCount);
			system("pause");
			break;
		case 6:
			LastStudentDelet(Student_List, &StudentCount);
			break;
		case 7:
			AllStudentDelet(Student_List, &StudentCount);
			break;
		case 8:
			StudentSave(Student_List, StudentCount);
			system("pause");
			break;
		case 9:
			StudentLoad(Student_List, &StudentCount);
			break;
		case 10:
			AllStudentDelet(Student_List, &StudentCount);
			return;
		}
	}
}