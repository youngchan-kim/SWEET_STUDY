#include <iostream>
using namespace std;

void func()
{
	cout << "func1() �Լ��� ȣ���Ͽ����ϴ�." << endl;
}
void func(int a)
{
	cout << "func1(int a) �Լ��� ȣ���Ͽ����ϴ�." << endl;
}
void main()
{
	func();
	func(10);
}