#include<iostream>
#include<functional>
using namespace std;

void func1()
{
	cout << "함수 포인터1 호출" << endl;
}

void func2()
{
	cout << "함수 포인터2 호출" << endl;
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