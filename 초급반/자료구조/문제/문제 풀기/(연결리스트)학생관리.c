#include <stdio.h>
#include<stdlib.h>
#include <Windows.h>
#include <string.h>

#define TURE 1
#define SUBJECT 3 

typedef struct Student
{
	char name[10];
	int age;
	char address[50];
	int kor;
	int eng;
	int math;
	struct Student* link;

}Student;

void Menu()
{
	printf("< < < = = = = �޴� = = = = > > >\n\n");
	printf("1.�л� ���\n");
	printf("2.�л� �˻�\n");
	printf("3.�л� ���\n");
	printf("4.�л� ����\n");
	printf("5.�л� ����\n");
	printf("6.����\n");
	printf("���� : ");
}

void Studyinput(Student* tmp)
{
	system("cls");
	printf("�л� �̸� �Է� : ");
	scanf("%s", tmp->name);
	//printf("%s �л� ���� �Է� : ", tmp->name);
	//scanf("%d", &tmp->age);
	//printf("%s �л� �ּ� �Է� : ", tmp->name);
	//scanf("%s", tmp->address);
	//printf("%s �л� ���� �Է� : ", tmp->name);
	//scanf("%d", &tmp->kor);
	//printf("%s �л� ���� �Է� : ", tmp->name);
	//scanf("%d", &tmp->eng);
	//printf("%s �л� ���� �Է� : ", tmp->name);
	//scanf("%d", &tmp->math);
}
Student* StudyInsert(Student* head)
{
	if (head == NULL)
	{
		head = (Student*)malloc(sizeof(Student));
		Studyinput(head);
		head->link = NULL;

		return head;
	}
	head->link = StudyInsert(head->link);
	return head;
}


Student* FindName(Student* head, Student* tmp)
{
	char searchname[10];

	scanf("%s", searchname);
	tmp = head;
	while (tmp != NULL && strcmp(tmp->name, searchname) != 0)
	{
		tmp = tmp->link;
	}
	return tmp;
}
Student* StudyInformation(Student* head)
{
	Student* tmp;
	tmp = FindName(head, tmp);

	if (tmp == NULL)
		printf("�Է��� �л��� �����ϴ�.\n");
	else
	{
		int sum = tmp->kor + tmp->eng + tmp->math;
		float avg = (float)sum / SUBJECT;
		char grade;
		if (avg > 90)
			grade = 'A';
		else if (avg > 80 || avg <= 90)
			grade = 'B';
		else if (avg > 70 || avg <= 80)
			grade = 'C';
		else if (avg > 60 || avg <= 70)
			grade = 'D';
		else if (avg > 50 || avg <= 60)
			grade = 'E';
		else if (avg <= 50)
			grade = 'F';

		printf("< < = = = = = information = = = = = = > >\n\n");

		printf("�л� �̸� : %s\n", tmp->name);
		printf("�л� ���� : %d ��\n", tmp->age);
		printf("�л� �ּ� : %s\n", tmp->address);
		printf("���� ���� : %d ��\n", tmp->kor);
		printf("���� ���� : %d ��\n", tmp->eng);
		printf("���� ���� : %d ��\n", tmp->math);
		printf("�հ� ���� : %d ��\n", sum);
		printf("�л� �̸� : %2f ��\n", avg);
		printf("�л� �̸� : %c ���\n\n\n", grade);
		printf("�л� ���� �˻� �Ϸ�\n");
		return tmp;
	}
}

void StudyList(Student* head)
{
	Student* tmp;
	tmp = head;
	system("cls");
	printf("< < = = = = = information = = = = = = > >\n\n");
	printf("\t�л� �̸�\t �л� ����\t �л� �ּ�\n");
	while (tmp != NULL)
	{
		printf("\t%s \t%d \t%s\n", tmp->name, tmp->age, tmp->address);
		tmp = tmp->link;
	}
	printf("�л� �������� ������ �˻��� �̿��ϼ��� !!\n");
	system("pause");
}

void StudyUpdateList(Student* tmp, int num)
{
	char updatename[10];
	char updateaddress[50];
	int updateage, updatekor, updateeng, updatemath;

	switch (num)
	{
	case 1:
		printf("���� �̸� : %s\n", tmp->name);
		printf("������ �̸� : ");
		scanf("%s", updatename);
		printf("%s->", tmp->name);
		strcpy(tmp->name, updatename);
		printf("%s �� ���� �Ϸ�\n", updatename);
		system("pause");
		break;
	case 2:
		printf("���� ���� : %d\n", tmp->age);
		printf("������ ���� : ");
		scanf("%d\n", &updateage);
		printf("%d->", tmp->age);
		tmp->age = updateage;
		printf("%d �� ���� ���� �Ϸ�", updateage);
		system("pause");
		break;
	case 3:
		printf("���� �ּ� : %s\n", tmp->address);
		printf("������ �ּ� : ");
		scanf("%s\n", updateaddress);
		printf("%s->", tmp->address);
		strcpy(tmp->address, updateaddress);
		printf("%s �� ���� �Ϸ�", updateaddress);
		system("pause");
		break;
	case 4:
		printf("���� ����\n ���� : %d ���� : %d ���� : %d\n", tmp->kor, tmp->eng, tmp->math);
		printf("������ ���� ���� : ");
		scanf("%d\n", &updatekor);
		tmp->kor = updatekor;
		printf("������ ���� ���� : ");
		scanf("%d\n", &updateeng);
		tmp->eng = updateeng;
		printf("������ ���� ���� : ");
		scanf("%d\n", &updatemath);
		tmp->math = updatemath;
		printf("���� ���� �Ϸ�");
		system("pause");
		break;
	case 5:
		printf("������ �����մϴ�.\n");
		system("pause");
		return;
	}
}
void StudyUpdate(Student* head)
{
	int num;
	Student* tmp;
	printf("������ �л� �̸���? ");
	tmp = StudyInformation(head);
	printf("������ �׸��� ���� �Ͻÿ�\n");
	printf("1. �̸�  2.����  3.�ּ�  4.����  5.��������\n");
	printf("���� : ");
	scanf("%d", &num);
	StudyUpdateList(tmp, num);
}
Student* StudyDelete(Student* head)
{
	Student* tmp;
	Student* savefront = NULL;
	Student* saveback;
	printf("������ �л� �̸� : ");
	char searchname[10];
	scanf("%s", searchname);

	tmp = head;
	while (tmp != NULL && strcmp(tmp->name, searchname) != 0)
	{
		savefront = tmp;
		tmp = tmp->link;
	}

	if (tmp == NULL)
		printf("�ش� �̸��� �л��� �����ϴ�.\n");
	else
	{
		saveback = tmp->link;
		free(tmp);
		tmp = NULL;
		if (savefront == NULL)
		{
			head = saveback;
		}
		else
			savefront->link = saveback;
		printf("���� �Ϸ�\n");
	}
	return head;
	system("pause");
}
void Relese(Student* head)
{
	if (head == NULL)
		return;
	Relese(head->link);
	free(head);
}

void main()
{
	int num;
	Student* head = NULL;
	//Student* tmp = NULL;

	while (TRUE)
	{
		system("cls");
		Menu();
		scanf("%d", &num);

		switch (num)
		{
		case 1:
			head = StudyInsert(head);
			break;
		case 2:
			system("cls");
			printf("�˻��� �̸� �Է� : ");
			StudyInformation(head);

			system("pause");
			break;
		case 3:
			StudyList(head);
			break;
		case 4:
			StudyUpdate(head);
			break;
		case 5:
			head = StudyDelete(head);
			break;
		case 6:
			Relese(head);
			return;
		}
	}
}
