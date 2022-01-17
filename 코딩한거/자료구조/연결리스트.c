#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<Windows.h>
typedef struct node
{
	char name[20];
	char add[20];
	int sum, kor, eng, mat, age;
	float abs;
	char grade;
	struct node* link;
}node;

node* get_node()
{
	node* tmp;
	tmp = (node*)malloc(sizeof(node));
	tmp->link = 0;
	return tmp;
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

node* insert(node* head) {
	if (head == NULL)
	{
		head = get_node();
		printf("�л� �̸� �Է� : ");
		scanf("%s", head->name);
		printf("%s �л� ���� �Է� : ", head->name);
		scanf("%d", &head->age);
		printf("%s �л� �ּ� �Է� : ", head->name);
		scanf("%s", head->add);
		printf("%s �л� ���� �Է� : ", head->name);
		scanf("%d", &head->kor);
		printf("%s �л�  ���� �Է� : ", head->name);
		scanf("%d", &head->eng);
		printf("%s �л� ���� �Է� : ", head->name);
		scanf("%d", &head->mat);
		SetGrade(head);
		return head;
	}
	head->link = insert(head->link);
	return head;
}

void ShowStudent(node* head)
{
	printf("========================\n");
	printf("�л� �̸� : %s\n", head->name);
	printf("�л� ���� : %d ��\n", head->age);
	printf("�л� �ּ� : %s\n", head->add);
	printf("���� ���� : %d\n", head->kor);
	printf("���� ���� : %d\n", head->mat);
	printf("�հ� ���� : %d\n", head->sum);
	printf("��� ���� : %.2f\n", head->abs);
	printf("��� : %c\n", head->grade);
}

node* search(node* head, char* name)
{
	system("cls");
	if (head == NULL)
	{
		printf("ã���л� ���� \n");
		return 0;
	}
	if (strcmp(head->name, name) == 0)
	{
		printf("���� �˻� �Ϸ�\n");
		ShowStudent(head);
		return head;
	}
	return search(head->link, name);
}
void print(node* head)
{
	if (head == NULL)
	{
		printf("\n<�л� �������� ������ �˻��� �̿��ϼ��� !!>\n");
		return;
	}
	else
	{
		printf("%10s%10d%10s\n", head->name, head->age, head->add);
	}
	print(head->link);
}

void modify(node* head, char* name)
{
	int i, ag;
	char na[20], ad[20];
	head = search(head, name);
	if (head)
	{
		while (1)
		{
			system("cls");
			printf("������ �׸��� ���� �Ͻÿ� \n");
			printf("1.�̸�\t2.����\t3.�ּ�\t4.����\t5.��������\n���� : ");
			scanf("%d", &i);
			switch (i)
			{
			case 1:
				printf("���� �̸� : %s\n", head->name);
				strcpy(na, head->name);
				printf("������ �̸� : ");
				scanf("%s", head->name);
				printf("%s -> %s �� �̸� ���� �Ϸ�\n", na, head->name);
				break;
			case 2:
				printf("���� ���� : %d\n", head->age);
				ag = head->age;
				printf("������ ���� : ");
				scanf("%d", &head->age);
				printf("%d -> %d �� �̸� ���� �Ϸ�\n", ag, head->age);
				break;
			case 3:
				printf("���� �ּ� : %s\n", head->add);
				strcpy(ad, head->add);
				printf("������ �ּ� : ");
				scanf("%s", head->add);
				printf("%s -> %s �� �ּ� ���� �Ϸ�\n", ad, head->add);
				break;
			case 4:
				printf("���� ����\n");
				printf("���� : %d\t���� : %d\t���� : %d\n", head->kor, head->eng, head->mat);
				printf("������ ���� ���� : ");
				scanf("%d", &(head->kor));
				printf("������ ���� ���� : ");
				scanf("%d", &head->eng);
				printf("������ ���� ���� : ");
				scanf("%d", &head->mat);
				SetGrade(head);

				printf("���� ���� �Ϸ�\n");
				break;
			case 5:
				printf("������ �����մϴ�\n");
				return;
			}
			system("pause");
		}
	}
}
node* del(node* head, char* name)
{
	if (head == NULL)
	{
		printf("������ ��� ���� \n");
		return NULL;
	}
	if (strcmp(head->name, name) == 0)
	{
		node* tmp = head;
		head = head->link;
		free(tmp);
		printf("�����Ϸ�\n");
		return head;
	}
	head->link = del(head->link, name);
	return head;
}

void Release(node* Node)
{
	if (Node == NULL)
		return;
	Release(Node->link);
	free(Node);
}
void main() {
	node* head = 0;
	int i;
	char name[20];
	while (1) {
		system("cls");
		printf("< < < = = = = �޴� = = = = > > >\n\n");
		printf("1.�л� ���\n");
		printf("2.�л� �˻�\n");
		printf("3.�л� ���\n");
		printf("4.�л� ����\n");
		printf("5.�л� ����\n");
		printf("6.��     ��\n");
		printf("��  �� : "); 
		scanf("%d", &i);
		switch (i) {
		case 1:
			head = insert(head);
			break;
		case 2:printf("�л� �̸� �Է� : ");
			scanf("%s", name);
			search(head, name);
			break;
		case 3:
			printf("%10s%10s%10s\n", "�л��̸�", "�л�����", "�л��ּ�");
			print(head);
			break;
		case 4:
			printf("������ �л� �̸� : ");
			scanf("%s", name);
			modify(head, name);
			break;
		case 5:
			printf("�л� �̸� �Է� : ");
			scanf("%s", name);
			head = del(head, name);
			break;
		case 6:
			Release(head);
			return;
		}
		system("pause");
	}
}