#include<iostream>
#include<functional>
using namespace std;
//���ٽ�
//�ӽ÷� �Լ��� ����°�. (�Լ� ���� ���ٴ� ���� �͸��� �Լ�)
//��Ȱ��Ұ�
//���Ǵ°� ���ӿ����� ������ ��ſ� �ַ� ���ȴ�.
//ex)������ ������ �ָ鼭 ��Ŷ���޽�
void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(function<void(int, int)>p)
{
	p(15, 10);
}
void main()
{
	func2([](int x, int y) {
		cout << x << " + " << y << " = " << x + y << endl;
		});
	func2(Subfunc);
	return;
}