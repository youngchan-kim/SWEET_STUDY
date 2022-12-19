#include <iostream>
using namespace std;

void swap(int& su1, int &su2)
{
	int tmp = su1;
	su1 = su2;
	su2 = tmp;
}
void main()
{
	int num1 = 10, num2 = 20;
	cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
	swap(num1, num2);
	cout << "num1 = " << num1 << ", num2 = " << num2 << endl;
}