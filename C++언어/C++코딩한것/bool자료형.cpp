#include<iostream>
using namespace std;

bool func(int num)
{
	bool b;
	if (num == 10)
		b = true;
	else
		b = false;
	return b;
}

void main()
{
	int num;
	cout << "10�� �Է��Ͻÿ�";
	cin >> num;
	cout << func(num);
}