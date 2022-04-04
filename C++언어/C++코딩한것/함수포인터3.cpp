#include<iostream>
using namespace std;
typedef void(*FUNC)(int, int);

void Addfunc(int x, int y)
{
	cout << x << " + " << y << " = " << x + y << endl;
}

void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(FUNC p)
{
	p(15, 10);
}

void main()
{
	func2(&Addfunc);
	func2(&Subfunc);
	return;
}