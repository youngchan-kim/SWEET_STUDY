#include <iostream>
using namespace std;

void func(int n = 10)//  = 10 �� �⺻ ���̴�.
{
	int Sum = 0;
	for (int i = 1; i <= n; i++)
		Sum += i;
	cout << "1~" << n << "������ �� �� : " << Sum << endl;
}
void main()
{
	func(100);
	func();
}