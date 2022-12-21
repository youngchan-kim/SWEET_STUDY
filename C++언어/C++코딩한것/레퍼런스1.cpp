#include <iostream>
using namespace std;

void func(int& ref)
{
	cout << "ref = " << ref << endl;
	ref = 20;
}
void main()
{
	int Sum = 10;
	cout << "Sum = " << Sum << endl;
	func(Sum);
	cout << "Sum = " << Sum << endl;
}