#include <iostream>
using namespace std;

template <typename A, typename B>
class Size
{
private:
	int a, b;
public:
	Size() { a = sizeof(A); b = sizeof(B);	}
	void print()
	{
		cout << "a = " << a << ", b = " << b << endl;
	}
};

void main()
{
	Size<char, int >si1;
	Size<float, double>si2;
	si1.print();
	si2.print();
}