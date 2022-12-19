#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

typedef struct Point
{
	int number;
	int x, y;
	struct Point* Next;
}Point;

void Menu(int icount)
{
	printf("��ǥ ���� = %d\n", icount);
	printf("1.��ǥ�߰�\n");
	printf("2.��ǥ����\n");
	printf("3.����\n");
	printf("�Է� = ");
}

void Release(Point* Node)
{
	if (Node == NULL)
		return;
	Release(Node->Next);
	free(Node);
}

void main()
{
	int icount = 0;
	int num;
	Point* pt = NULL, * tmp, * add;
	while (1)
	{
		system("cls");
		Menu(icount);
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			icount++;
			if (icount == 1)
			{
				pt = (Point*)malloc(sizeof(Point));
				printf("x = ");
				scanf("%d", &pt->x);
				printf("y = ");
				scanf("%d", &pt->y);
				pt->number = icount;
				pt->Next = NULL;
			}
			else
			{
				tmp = pt;
				while (tmp->Next != NULL)
				{
					tmp = tmp->Next;
				}
				add = (Point*)malloc(sizeof(Point));
				printf("x = ");
				scanf("%d", &add->x);
				printf("y = ");
				scanf("%d", &add->y);
				add->Next = NULL;
				add->number = icount;
				tmp->Next = add;
			}
			break;
		case 2:
			tmp = pt;
			while (tmp != NULL)
			{
				printf("%d���� ��ǥ\nx = %d\ny = %d\n", tmp->number, tmp->x, tmp->y);
				printf("===============================\n\n");
				tmp = tmp->Next;
			}
			system("pause");
			break;
		case 3:
			Release(pt);
			return;
		}
	}
	Release(pt);
}