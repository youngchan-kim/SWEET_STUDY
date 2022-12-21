#include<iostream>
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
	void(*p)(); // 변수이고 p는 변수명
	p = &func1;
	p();

	p = &func2;
	p();
	return;
}