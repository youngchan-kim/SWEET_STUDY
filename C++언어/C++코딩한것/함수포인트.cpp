#include<iostream>
#include<functional>
using namespace std;

void func1()
{
	cout << "�Լ� ������1 ȣ��" << endl;
}

void func2()
{
	cout << "�Լ� ������2 ȣ��" << endl;
}

void main()
{
	function<void()>p;
	p = func1;
	p();
	p = func2;
	p();
	return;
}