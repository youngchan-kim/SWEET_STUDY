#include<stack>
#include<stdio.h>
#include<Windows.h>

#define TURE 1

void main()
{
	int num;
	std::stack<int> iStack;
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
			iStack.push(num);
			system("pause");
			break;
		case 2:
			if (!iStack.empty())
			{
				printf("Pop : %d\n", iStack.top());
				iStack.pop();
			}
			else
				printf("삭제할 데이터가 없습니다.\n");
			system("pause");
			break;
		case 3:
			while (!iStack.empty())
			{
				printf("Top : %d\n", iStack.top());
				iStack.pop();
			}
			break;
		}
	} while (num != 3);
}