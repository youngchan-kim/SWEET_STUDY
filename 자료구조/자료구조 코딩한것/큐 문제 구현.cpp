#include <queue>
#include<stdio.h>

void main()
{
	int num;
	std::queue<int> iQueue;
	do
	{
		system("cls");
		printf("====Stack System====\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Exit\n");
		printf("====================\n");
		printf("입력 : ");

		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("데이터 입력 : ");
			scanf("%d", &num);
			iQueue.push(num);
			printf("Front : %d\tRear : %d\n", iQueue.front(), iQueue.back());
			system("pause");
			break;
		case 2:
			if (!iQueue.empty())
			{
				printf("Front : %d\tRear : %d\n", iQueue.front(), iQueue.back());
				iQueue.pop();
			}
			else
				printf("삭제할 데이터가 없습니다.\n");
			system("pause");
			break;
		case 3:
			while (!iQueue.empty())
			{
				printf("Front : %d\tRear : %d\n", iQueue.front(), iQueue.back());
				iQueue.pop();
			}
			break;
		}
	} while (num != 3);
}