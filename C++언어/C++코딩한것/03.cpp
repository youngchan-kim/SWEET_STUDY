#include <iostream>
using namespace std;

class Test
{
public:
	void test(char ch);
	void test(int num);
};
void Test::test(char ch)
{
	cout << "test(char ch) 함수를 호출" << endl;
}

void Test::test(int num)
{
	cout << "test(int num) 함수를 호출" << endl;
}

void main()
{
	Test t;
	t.test(10);
	t.test('a');

}