#include<map>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>

#define TRUE 1
#define NULL 0

typedef struct node
{
	char name[20];
	char add[20];
	int sum, kor, eng, mat, age;
	float abs;
	char grade;
}node;

void PrintList(std::map<int, node> StudentMap)
{
	if (StudentMap.empty())
	{
		printf("\n<�л� �������� ������ �˻��� �̿��ϼ��� !!>\n");
		return;
	}
	else
	{
		for (std::map<int, node> ::iterator iter = StudentMap.begin(); iter != StudentMap.end(); iter++)
			printf("%10d%10s%10d%10s\n", iter->first, iter->second.name, iter->second.age, iter->second.add);
		printf("\n");
	}
}

void SetGrade(node* head)
{
	head->sum = (head->eng) + (head->kor) + (head->mat);
	head->abs = head->sum / 3;
	if (head->abs > 90)
		head->grade = 'A';
	else if (head->abs > 80)
		head->grade = 'B';
	else if (head->abs > 70)
		head->grade = 'C';
	else if (head->abs > 60)
		head->grade = 'D';
	else
		head->grade = 'F';
}

node create()
{
	node head;
	printf("�л� �̸� �Է� : ");
	scanf("%s", head.name);
	printf("%s �л� ���� �Է� : ", head.name);
	scanf("%d", &head.age);
	printf("%s �л� �ּ� �Է� : ", head.name);
	scanf("%s", head.add);
	printf("%s �л� ���� �Է� : ", head.name);
	scanf("%d", &head.kor);
	printf("%s �л� ���� �Է� : ", head.name);
	scanf("%d", &head.eng);
	printf("%s �л� ���� �Է� : ", head.name);
	scanf("%d", &head.mat);
	SetGrade(&head);
	return head;
}

void ShowStudent(std::map<int, node>::iterator findIter)
{
	printf("< = = = = = information = = = = = = >\n");
	printf("�й� : %d\n", findIter->first);
	printf("�л� �̸� : %s\n", findIter->second.name);
	printf("�л� ���� : %d ��\n", findIter->second.age);
	printf("�л� �ּ� : %s\n", findIter->second.add);
	printf("���� ���� : %d\n", findIter->second.kor);
	printf("���� ���� : %d\n", findIter->second.eng);
	printf("���� ���� : %d\n", findIter->second.mat);
	printf("�հ� ���� : %d\n", findIter->second.sum);
	printf("��� ���� : %.2f\n", findIter->second.abs);
	printf("��� : %c\n", findIter->second.grade);
}

void SearchData(std::map<int, node> StudentMap, int num)
{
	std::map<int, node>::iterator findIter = StudentMap.find(num);
	if (findIter != StudentMap.end())
	{
		printf("�л� ���� �˻� �Ϸ�\n");
		ShowStudent(findIter);

	}
	else
		printf("%d ã�� �� �����ϴ�.\n", num);
}

void modify(std::map<int, node>* StudentMap, int num)
{
	int listnum, tempnum;
	char modifystring[20];
	node head;
	std::map<int, node>::iterator findIter = StudentMap->find(num);
	if (findIter != StudentMap->end())
	{
		while (TRUE)
		{
			system("cls");
			printf("�л� ���� �˻� �Ϸ�\n");
			ShowStudent(findIter);
			printf("\n\n");
			printf("������ �׸��� �����Ͻÿ�\n");
			printf("1.�̸�  2.����  3.�ּ�  4.����  5.��������\n");
			scanf("%d", &listnum);
			switch (listnum)
			{
			case 1:
				printf("�����̸� : %s\n", findIter->second.name);
				strcpy(modifystring, findIter->second.name);
				printf("������ �̸� : ");
				scanf("%s", findIter->second.name);
				printf("%s -> %s �� �̸� ���� �Ϸ�\n", modifystring, findIter->second.name);
				break;
			case 2:
				printf("���� ���� : %d\n", findIter->second.age);
				tempnum = findIter->second.age;
				printf("������ ���� : ");
				scanf("%d", &findIter->second.age);
				printf("%d -> %d �� �̸� ���� �Ϸ�\n", tempnum, findIter->second.age);
				break;
			case 3:
				printf("���� �ּ� : %s\n", findIter->second.add);
				strcpy(modifystring, findIter->second.add);
				printf("������ �ּ� : ");
				scanf("%s", findIter->second.add);
				printf("%s -> %s �� �ּ� ���� �Ϸ�\n", modifystring, findIter->second.add);
				break;
			case 4:
				printf("���� ����\n");
				printf("���� : %d\t���� : %d\t���� : %d\n", findIter->second.kor, findIter->second.eng, findIter->second.mat);
				printf("������ ���� ���� : ");
				scanf("%d", &head.kor);
				findIter->second.kor = head.kor;
				printf("������ ���� ���� : ");
				scanf("%d", &head.eng);
				findIter->second.eng = head.eng;
				printf("������ ���� ���� : ");
				scanf("%d", &head.mat);
				findIter->second.mat = head.mat;
				SetGrade(&head);
				findIter->second.sum = head.sum;
				findIter->second.abs = head.abs;
				findIter->second.grade = head.grade;
				printf("���� ���� �Ϸ�\n");
				break;
			case 5:
				printf("������ �����մϴ�\n");
				return;
			}
		}
	}
	else
		printf("%s ã�� �� �����ϴ�.\n", num);
}

void DeleteData(std::map<int, node>* StudentMap, int num)
{
	std::map<int, node>::iterator findIter = StudentMap->find(num);
	if (findIter != StudentMap->end())
		StudentMap->erase(findIter);

	else
		printf("Data %d Not Found!\n", num);
}

void main()
{
	int StudentNumber;
	std::map<int, node> StudentMap;
	std::map<int, node>::iterator findIter;
	int num;
	char name[20];
	while (TRUE)
	{
		system("cls");
		printf("< < < = = = = �޴� = = = = > > >\n\n");
		printf("1.�л� ���\n");
		printf("2.�л� �˻�\n");
		printf("3.�л� ���\n");
		printf("4.�л� ����\n");
		printf("5.�л� ����\n");
		printf("6.��     ��\n");
		printf("��  �� : ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("�й��� �Է����ּ���. : ");//�ߺ��� �й����� �ƴ���
			scanf("%d", &StudentNumber);
			findIter = StudentMap.find(StudentNumber);
			if (findIter != StudentMap.end())
				printf("�й��� �ߺ� �Ǿ����ϴ�.\n");
			else
			{
				printf("[ %d ] �ش� �й��� ��� �� �� �ֽ��ϴ�.\n", StudentNumber);
				StudentMap.insert(std::make_pair(StudentNumber, create()));
				printf("�л� ���� �Է� �Ϸ�\n");
			}
			system("pause");
			break;
		case 2:
			printf("�й� �Է� : ");
			scanf("%d", &num);
			SearchData(StudentMap, num);
			system("pause");
			break;
		case 3:
			printf("%10s%10s%10s%10s\n", "��    ��", "�л��̸�", "�л�����", "�л��ּ�");
			PrintList(StudentMap);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("������ ��     ��: ");
			scanf("%d", &num);
			modify(&StudentMap, num);
			break;
		case 5:
			printf("������ ��     �� �Է� : ");
			scanf("%d", &num);
			DeleteData(&StudentMap, num);
			break;
		case 6:
			StudentMap.clear();
			return;
		}
	}
}