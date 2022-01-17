#include<list> 
#include<stdio.h>
#include<Windows.h>
#include<time.h>

// 배열로 다시 할 것
#define TRUE 1

void PrintList(std::list<int> RanNum)
{
	int i = 0;
	for (std::list<int>::iterator iter = RanNum.begin(); iter != RanNum.end(); iter++)
	{
		printf("%d 번 수 : ", i++);
		printf("%d\n", *iter);
	}
	printf("\n");
}
void main()
{
	std::list<int> RanNum;

	int num, RNum, temp, i = 0;
	srand(time(NULL));
	
	while (TRUE)
	{
		system("cls");
		printf("1. 번호 생성\n");
		printf("2. 오름차순 정렬\n");
		printf("3. 내림차순 정렬\n");
		printf("4. 종료\n");
		printf("선택 : ");
		scanf("%d", &num);
		switch(num)
		{
		case 1:
			for (int i = 0; i < 10; i++)
			{
				RNum = (rand() % 99) + 1;
				RanNum.push_back(RNum);
			}
			PrintList(RanNum);
			system("pause");
			break;
		case 2:
			i = 0;
			for (std::list<int>::iterator iter = RanNum.begin(); iter != RanNum.end()-1; iter++)
			{
				printf("%d 번 수 : ", i++);
				for (std::list<int>::iterator asce_iter = iter+1; asce_iter != RanNum.end(); asce_iter++)
				{
					if (*iter > *asce_iter)
					{
						temp = *asce_iter;
						*asce_iter = *iter;
						*iter = temp;
					}
				}
				printf("%d\n", *iter);
			}
			printf("\n");
			system("pause");
			break;
		case 3:
			i = 0;
			for (std::list<int>::iterator iter = RanNum.begin(); iter != RanNum.end(); iter++)
			{
				printf("%d 번 수 : ", i++);
				for (std::list<int>::iterator asce_iter = iter; asce_iter != RanNum.end(); asce_iter++)
				{
					if (*iter < *asce_iter)
					{
						temp = *iter;
						*iter = *asce_iter;
						*asce_iter = temp;
					}
				}
				printf("%d\n", *iter);
			}
			printf("\n");
			system("pause");
			break;
		case 4:
			RanNum.clear();
			return;
		}
	}
}