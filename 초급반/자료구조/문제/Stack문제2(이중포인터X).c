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
	printf("입력 : ");
}

int Push(Stack* top, int pushnum)
{
	Stack* add = NULL;
	add = (Stack*)malloc(sizeof(Stack));
	add->data = pushnum; 
	add->link = NULL;
	add->link = top;
	top = add;
	return top;
}

int Pop(Stack* top)
{
	Stack* tmp;
	if (top != NULL)
	{
		tmp = top;

		printf("data = %d\n", top->data);
		printf("===============================\n\n");

		top = tmp->link;
		free(tmp);
		tmp = NULL;

	}
	else
	{
		printf("삭제할 데이터가 없습니다.\n");
	}
	return top;
	system("pause");
}

void Release(Stack* top)
{
	if (top == NULL)
		return;
	else if (top != NULL)
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
			printf("데이터 입력 : ");
			scanf("%d", &pushnum);
			top = Push(top, pushnum);
			break;
		case 2:
			top = Pop(top);
			break;
		case 3:
			Release(top);
			return;
		}
	}
}