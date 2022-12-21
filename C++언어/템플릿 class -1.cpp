#include <iostream>
using namespace std;

template <typename Type>
class Point
{
private:
	Type x, y;
public:
	Point(Type a, Type b){	x = a;	y = b;}
	void Display()
	{
		cout << "x : " << x << "\n";
		cout << "y : " << y << "\n";
	}
};

void main()
{
	Point <int> Pint(10, 20);
	Point <double> PDouble(10.4, 20.6);
	Pint.Display();
	PDouble.Display();
}