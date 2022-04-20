#include <iostream>

using namespace std;
class Point
{
private:
	int x, y;
public:
	Point(int a, int b) { x = a; y = b; }
	void Print() { cout << "x = " << x << ", y = " << y << "\n";}
	friend Point operator+ (Point tmp, int data);
};

Point operator+ (Point tmp, int date)
{
	cout << "°´Ã¼ + Á¤¼ö" << "\n";
	tmp.x = tmp.x + data;
	tmp.y = tmp.y + data;
	return tmp;
}

void main()
{
	Point ov1(10, 20), ov2(0, 0);
	ov2 = ov1 + 10;
	ov2.Print();
}