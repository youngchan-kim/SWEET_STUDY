#include<iostream>
#include<functional>
using namespace std;

void Addfunc(int x, int y)
{
	cout << x << " + " << y << " = " << x+y << endl;
}

void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(function<void(int, int)>p)
{
	p(15, 10);
}
void main()
{
	func2(Addfunc);
	func2(Subfunc);
	return;
}