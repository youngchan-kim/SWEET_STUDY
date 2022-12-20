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
	cout << "test(char ch) 함수를 호출" << endl;
}

void Test::test(char* str)
{
	cout << "test(char*str) 함수를 호출" << endl;
}

void main()
{
	Test t;
	
	t.test('a');
	t.test((char*)"Hello");

}