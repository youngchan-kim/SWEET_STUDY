#include<iostream>
#include<functional>
using namespace std;
//맴버 함수에서 함수 포인터로 보냈을 때 문제가 생길 수 있다.
//함수포인터 입장에서는 누구의 맴버함수 인지 모른다.
//객체의 정보까지 묶어서 정보를 전달하기 위해 사용한다.

void Addfunc(int x, int y)
{
	cout << x << " + " << y << " = " << x + y << endl;
}

void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(function<void(int)>p)
{
	p(20);
}
void main()
{
	func2(bind(Addfunc, 10, placeholders::_1));
	func2(bind(Subfunc, 10, placeholders::_1));
	return;
}