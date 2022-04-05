#include<list> 
#include<stdio.h>
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
	struct node* link;
}node;

void PrintList(std::list<node> iList)
{
	if (iList.empty())
	{
		printf("\n<�л� �������� ������ �˻��� �̿��ϼ��� !!>\n");
		return;
	}
	else
	{
		for (std::list<node>::iterator iter = iList.begin(); iter != iList.end(); iter++)
			printf("%10s%10d%10s\n", iter->name, iter->age, iter->add);
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

void ShowStudent(std::list<node>::iterator findIter)
{
	printf("< = = = = = information = = = = = = >\n");
	printf("�л� �̸� : %s\n", findIter->name);
	printf("�л� ���� : %d ��\n", findIter->age);
	printf("�л� �ּ� : %s\n", findIter->add);
	printf("���� ���� : %d\n", findIter->kor);
	printf("���� ���� : %d\n", findIter->mat);
	printf("�հ� ���� : %d\n", findIter->sum);
	printf("��� ���� : %.2f\n", findIter->abs);
	printf("��� : %c\n", findIter->grade);
}
//��� �ִ� ���� ���� ���� �����ؼ� �����ؾ��Ѵ�.
std::list<node>::iterator Search(std::list<node>* iList, char* name)
{
	for (std::list<node>::iterator iter = iList->begin(); iter != iList->end(); iter++)
	{
		if (strcmp(iter->name, name) == 0)
			return iter;
	}
	return iList->end();
}

void SearchData(std::list<node>* iList, char* name)
{
	std::list<node>::iterator findIter = Search(iList, name);
	if (findIter != iList->end())
	{
		printf("�л� ���� �˻� �Ϸ�\n");
		ShowStudent(findIter);
	}
	else
		printf("%s ã�� �� �����ϴ�.\n", name);
}
void modify(std::list<node>* iList, char* name)
{
	int num;
	char modifystring[20];
	node head;
	std::list<node>::iterator findIter = Search(iList, name);
	if (findIter != iList->end())
	{
		while (TRUE)
		{
			system("cls");
			printf("�л� ���� �˻� �Ϸ�\n");
			ShowStudent(findIter);
			printf("\n\n");
			printf("������ �׸��� �����Ͻÿ�\n");
			printf("1.�̸�  2.����  3.�ּ�  4.����  5.��������\n");
			scanf("%d", &num);
			switch (num)
			{
			case 1:
				printf("�����̸� : %s\n", findIter->name);
				strcpy(modifystring, findIter->name);
				printf("������ �̸� : ");
				scanf("%s", findIter->name);
				printf("%s -> %s �� �̸� ���� �Ϸ�\n", modifystring, findIter->name);
				break;
			case 2:
				printf("���� ���� : %d\n", findIter->age);
				num = findIter->age;
				printf("������ ���� : ");
				scanf("%d", &findIter->age);
				printf("%d -> %d �� �̸� ���� �Ϸ�\n", num, findIter->age);
				break;
			case 3:
				printf("���� �ּ� : %s\n", findIter->add);
				strcpy(modifystring, findIter->add);
				printf("������ �ּ� : ");
				scanf("%s", findIter->add);
				printf("%s -> %s �� �ּ� ���� �Ϸ�\n", modifystring, findIter->add);
				break;
			case 4:
				printf("���� ����\n");
				printf("���� : %d\t���� : %d\t���� : %d\n", findIter->kor, findIter->eng, findIter->mat);
				printf("������ ���� ���� : ");
				scanf("%d", head.kor);
				findIter->kor = head.kor;
				printf("������ ���� ���� : ");
				scanf("%d", head.eng);
				findIter->eng = head.eng;
				printf("������ ���� ���� : ");
				scanf("%d", head.mat);
				findIter->mat = head.mat;
				SetGrade(&head);

				printf("���� ���� �Ϸ�\n");
				break;
			case 5:
				printf("������ �����մϴ�\n");
				return;
			}
		}
	}
	else
		printf("%s ã�� �� �����ϴ�.\n", name);
}

void DeleteData(std::list<node>* iList, char* name)
{
	std::list<node>::iterator findIter = Search(iList, name);
	if (findIter != iList->end())
		iList->erase(findIter);

	else
		printf("Data %d Not Found!\n", name);
}
void Release(std::list<node>* iList)
{
	while (!iList->empty())
	{
		iList->pop_back();
	}
}

void main()
{
	std::list<node> iList;
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
			iList.push_back(create());
			printf("�л� ���� �Է� �Ϸ�\n");
			system("pause");
			break;
		case 2:
			printf("�л� �̸� �Է� : ");
			scanf("%s", name);
			SearchData(&iList, name);
			system("pause");
			break;
		case 3:
			printf("%10s%10s%10s\n", "�л��̸�", "�л�����", "�л��ּ�");
			PrintList(iList);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("������ �л� �̸� : ");
			scanf("%s", name);
			modify(&iList, name);
			break;

		case 5:
			printf("�л� �̸� �Է� : ");
			scanf("%s", name);
			DeleteData(&iList, name);
			break;
		case 6:
			Release(&iList);
			return;
		}
	}
}