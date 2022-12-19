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

void Push(Stack** top, int pushnum)
{
	Stack* add = NULL;
	add = (Stack*)malloc(sizeof(Stack));
	add->data = pushnum; /// 연산자 우선 순위로 구조체를 가리키는 ->가 우선이 되어 생긴 오류로
							/// (*top)를 해주면 오류가 해결된다.
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
		printf("삭제할 데이터가 없습니다.\n");
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
			printf("데이터 입력 : ");
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