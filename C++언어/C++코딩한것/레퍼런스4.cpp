#include <iostream>
using namespace std;

void func(int& ref)
{
	cout << "ref = " << ref << endl << endl;
	int b = 20;
	ref = b;
	b = 25;
	cout << "b = " << b << endl;
	cout << "ref = " << ref << endl;
}
void main()
{
	int a = 10;
	cout << "a = " << a << endl;
	func(a);
	cout << "a = " << a << endl;
}