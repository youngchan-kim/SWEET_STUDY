#include<stack>
#include<stdio.h>

void main()
{
	//STL�̴�.
	std::stack<int> iStack; // ���ø����

	for (int i = 1; i <= 10; i++)
	{
		iStack.push(i);
		
		printf("Top : %d\n", iStack.top());
	}
	iStack.size();//����� ���� ���� ��ȯ.

	while (!iStack.empty())
	{
		printf("Top : %d\n", iStack.top());
		iStack.pop();
	}
}