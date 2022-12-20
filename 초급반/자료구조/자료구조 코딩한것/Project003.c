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
	printf("1.Enqueue(�Է�)\n");
	printf("2.Dequeue(���)\n");
	printf("3.Exit\n");
	printf("====================\n");
	printf("�Է� : ");
}

int Enqueue(Queue* queue, int num)
{
	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	tmp->data = num;
	tmp->link = NULL;
	tmp->link = queue;
	queue = tmp;

	return queue;
}
int Dequeue(Queue* queue)
{
	if (queue->link != NULL)
	{
		Queue* tmp = queue;

		printf("%d\n\n", tmp->data);
		printf("=====================\n\n");

		queue = tmp->link;
		free(tmp);
		tmp = NULL;
	}
	else
	{
		printf("������ �����Ͱ� �����ϴ�.\n");
	}
	return queue;
}

void main()
{

	int selectmenu, num;
	Queue* front = NULL, * Rear = NULL;

	while (TRUE)
	{
		system("cls");
		Menu();
		scanf("%d", &selectmenu);
		switch (selectmenu)
		{
		case 1:
			printf("������ �Է� : ");
			scanf("%d", &num);
			if (front == NULL)
			{
				front = Enqueue(front, num);
				Rear = front;
			}
			else
				Rear = Enqueue(Rear, num);
			break;
		case 2:
			Rear = Dequeue(Rear, front);
			system("pause");
			break;
		case 3:

			return;
		}
	}
}