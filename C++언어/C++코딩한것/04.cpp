#include <iostream>
using namespace std;

class Test
{
public:
	void test(char ch);
	void test(char*str);
};
void Test::test(char ch)
{
	cout << "test(char ch) �Լ��� ȣ��" << endl;
}

void Test::test(char* str)
{
	cout << "test(char*str) �Լ��� ȣ��" << endl;
}

void main()
{
	Test t;
	
	t.test('a');
	t.test((char*)"Hello");

}