#include <iostream>
using namespace std;

class Add
{
public:
	void AddNum1(int Num = 10);
	void AddNum2(int Num1 = 10, int Num2);
};
void Add::AddNum1(int Num)
{
	cout << Num << "+" << "1=" << Num + 1 << endl;
}
void Add::AddNum2(int Num1, int Num2)
{
	cout << Num1 << "+" << Num2 << "=" << Num1 + Num2 << endl;
}
void main()
{
	Add add;
	add.AddNum1();
	add.AddNum1(20);
	add.AddNum2();
	add.AddNum2(20); //여기서 문제가 일어남 
	//매개변수의 왼쪽부터 값이 들어가기 때문에 문제가 생김
	add.AddNum2(10, 20);
}