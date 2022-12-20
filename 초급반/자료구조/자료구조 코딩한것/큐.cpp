#include <queue>
#include<stdio.h>

void main()
{
	std::queue<int> iQueue;

	for (int i = 1; i <= 10; i++)
	{
		iQueue.push(i);
		printf("Front : %d\tRear : %d\n", iQueue.front(), iQueue.back());
	}
	iQueue.size();
	while (!iQueue.empty())
	{
		printf("Front : %d\tRear : %d\n", iQueue.front(), iQueue.back());
		iQueue.pop();
	}
}