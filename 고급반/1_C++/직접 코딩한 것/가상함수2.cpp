#include<iostream>
using namespace std;

class Bumo
{
public:
	virtual void func()
	{
		cout << "Bumo�Լ� �Դϴ�." << endl;
	}
};
class Jasic : public Bumo
{
public:
	void func()
	{
		cout << "Jasic�Լ� �Դϴ�." << endl;
	}
};
void main()
{
	Jasic ob;
	Bumo* mom = &ob;
	mom->func();
}