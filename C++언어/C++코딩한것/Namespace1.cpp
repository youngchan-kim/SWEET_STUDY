#include <iostream>
#include <string>

using namespace std;

namespace A
{
	void printf(string a)
	{
		cout << "저는 A팀의 printf 입니다.";
		cout << endl << a;
	}
}

namespace B
{
	void printf(string a)
	{
		cout << "저는 B팀의 printf 입니다.";
		cout << endl << a;
	}
}
void main()
{
	A::printf("Hello");
	cout << endl << endl;
	B::printf("Hello");
}