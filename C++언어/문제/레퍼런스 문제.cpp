#include <iostream>
using namespace std;

void MoreBig(int& num1, int num2)
{
	if (num2 > num1)
		 num1 = num2;
}

void Sum(int& num1)
{
	int tmpsum = 0;
	for (int i = 1; i <= 100; i++)
	{
		if (i % num1 == 0)
		{
			tmpsum += i;
		}
	}
	num1 = tmpsum;
}
void ReTurnNum(int& num1)
{
	int cout= 1;
	int tmpsum = 0;
	int tmpnum;
	while (1)
	{
		tmpnum = num1 % 10;
		num1 = num1 / 10;

		if (cout > 1)
			tmpsum *= 10; 
		tmpsum += tmpnum;
		cout++;
		if (num1 == 0)
		{
			num1 = tmpsum;
			break;
		}
	}
}
void main()
{
	int a, b;
	cout << "1�� ���� ���� 2���� �Է� : ";
	cin >> a >> b;
	cout << a << "�� " << b << "�� ū ���� : ";
	MoreBig(a, b);
	cout << a << endl;
	cout << "2�� ���� ���� �ϳ� �Է� : ";
	cin >> a;
	cout << "1 ~ 100 ���� " << a << "����� ���� : ";
	Sum(a);
	cout << a << endl;
	cout << "3�� ���� ���� �ϳ� �Է� : ";
	cin >> a;
	ReTurnNum(a);
	cout << "�� �Ųٷ� �� : " << a << endl;
}