#include<iostream>
#include<functional>
using namespace std;
//�ɹ� �Լ����� �Լ� �����ͷ� ������ �� ������ ���� �� �ִ�.
//�Լ������� ���忡���� ������ �ɹ��Լ� ���� �𸥴�.
//��ü�� �������� ��� ������ �����ϱ� ���� ����Ѵ�.

void Addfunc(int x, int y)
{
	cout << x << " + " << y << " = " << x + y << endl;
}

void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(function<void(int)>p)
{
	p(20);
}
void main()
{
	func2(bind(Addfunc, 10, placeholders::_1));
	func2(bind(Subfunc, 10, placeholders::_1));
	return;
}