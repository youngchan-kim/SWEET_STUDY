#include <iostream>
using namespace std;
class Test
{
public:
	void test();
	void test(int num);
};
void Test::test()
{
	cout << "test() �Լ��� ȣ��" << endl;
}

void Test::test(int num)
{
	cout << "test(int num) �Լ��� ȣ��" << endl;
}

void main()
{
	Test t;
	t.test();
	t.test(10);
}