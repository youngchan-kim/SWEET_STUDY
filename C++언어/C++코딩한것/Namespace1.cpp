#include <iostream>
#include <string>

using namespace std;

namespace A
{
	void printf(string a)
	{
		cout << "���� A���� printf �Դϴ�.";
		cout << endl << a;
	}
}

namespace B
{
	void printf(string a)
	{
		cout << "���� B���� printf �Դϴ�.";
		cout << endl << a;
	}
}
void main()
{
	A::printf("Hello");
	cout << endl << endl;
	B::printf("Hello");
}