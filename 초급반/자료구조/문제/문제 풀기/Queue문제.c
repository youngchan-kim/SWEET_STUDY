#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>

#define TRUE 1

typedef struct Queue
{
	int data;
	struct Queue* link;
}Queue;



void Menu()
{
	printf("====Queue System====\n");
	printf("1.Enqueue(입력)\n");
	printf("2.Dequeue(출력)\n");
	printf("3.Exit\n");
	printf("====================\n");
	printf("입력 : ");
}

int Enqueue(Queue* queue, int num)
{
	Queue* tmp = (Queue*)malloc(sizeof(Queue));

	if (queue != NULL)
		queue->link = queue;

	tmp->link = NULL;
	tmp->data = num;
	queue = tmp;

	return queue;
}
int Dequeue(Queue* Front, Queue* Rear)
{
	Queue* tmp = Front;
	if (tmp != NULL)
	{

		printf("%d\n\n", tmp->data);
		printf("=====================\n\n");

		Front = tmp->link;
		free(tmp);
		tmp = NULL;

	}
	else
	{
		printf("삭제할 데이터가 없습니다.\n");
	}
	return Front;
}

void Release(Queue* Front)
{
	if (Front == NULL)
		return;
	else if (Front != NULL)
	{
		Release(Front->link);
		free(Front);
		Front = NULL;
	}
}
void main()
{

	int selectmenu, num;
	Queue* Front = NULL, * Rear = NULL;

	while (TRUE)
	{
		system("cls");
		Menu();
		scanf("%d", &selectmenu);
		switch (selectmenu)
		{
		case 1:
			printf("데이터 입력 : ");
			scanf("%d", &num);
			if (Front == NULL)
			{
				Front = Enqueue(Front, num);
				Rear = Front;
			}
			else
				Rear = Enqueue(Rear, num);
			break;
		case 2:
			Front = Dequeue(Front, Rear);
			system("pause");
			break;
		case 3:
			Release(Front);
			return;
		}
	}
}