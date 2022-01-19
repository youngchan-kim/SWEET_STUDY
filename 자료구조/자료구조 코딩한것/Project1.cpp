#include<stack>
#include<stdio.h>

void main()
{
	//STL이다.
	std::stack<int> iStack; // 스택만들기

	for (int i = 1; i <= 10; i++)
	{
		iStack.push(i);
		
		printf("Top : %d\n", iStack.top());
	}
	iStack.size();//저장된 원소 갯수 반환.

	while (!iStack.empty())
	{
		printf("Top : %d\n", iStack.top());
		iStack.pop();
	}
}