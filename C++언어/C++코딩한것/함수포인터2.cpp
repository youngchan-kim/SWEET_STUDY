#include<iostream>
using namespace std;

void Addfunc(int x, int y)
{
	cout << x << " + " << y << " = " << x+y << endl;
}

void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(void(*p)(int, int))
{
	p(15, 10);
}

void main()
{
	func2(&Addfunc);
	func2(&Subfunc);
	return;
}