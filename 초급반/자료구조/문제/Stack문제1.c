#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

#define TRUE 1

typedef struct Stack
{
	int data;
	struct Stack* link;
}Stack;

void Menu()
{
	printf("====Stack System====\n");
	printf("1. Push\n");
	printf("2. Pop\n");
	printf("3. Exit\n");
	printf("====================\n");
	printf("�Է� : ");
}

void Push(Stack** top, int pushnum)
{
	Stack* add = NULL;
	add = (Stack*)malloc(sizeof(Stack));
	add->data = pushnum; /// ������ �켱 ������ ����ü�� ����Ű�� ->�� �켱�� �Ǿ� ���� ������
							/// (*top)�� ���ָ� ������ �ذ�ȴ�.
	add->link = *top;
	*top = add;

}

void Pop(Stack **top)
{
	Stack* tmp;
	if ((*top) != NULL)
	{
		tmp = *top;

		printf("data = %d\n", (*top)->data);
		printf("===============================\n\n");
		*top = (tmp)->link;
		free(tmp);
		tmp = NULL;

	}
	else
	{
		printf("������ �����Ͱ� �����ϴ�.\n");
	}
	system("pause");
}
void Release(Stack* top)
{
	if (top == NULL)
		return;
	else if(top != NULL)
	{
		Release(top->link);
		free(top);
		top = NULL;
	}
}

void main()
{

	int Num, pushnum;
	Stack* top = NULL;


	while (TRUE)
	{
		system("cls");
		Menu();
		scanf("%d", &Num);
		switch (Num)
		{
		case 1:
			printf("������ �Է� : ");
			scanf("%d", &pushnum);
			Push(&top, pushnum);
			break;
		case 2:
			Pop(&top);

			break;
		case 3:
			Release(top);
			return;
		}
	}
}