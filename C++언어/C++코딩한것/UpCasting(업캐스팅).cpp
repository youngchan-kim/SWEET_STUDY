#include<iostream>
using namespace std;

class Mammal
{
public:
	void speak(int cnt)
	{
		cout << cnt << "�� ¢��" << endl;
	}
	void speak()
	{
		cout << "¢��" << endl;
	}
};
class Dog : public Mammal
{
public:
	void speak()
	{
		cout << "�۸�" << endl;
	}
};

void main()
{
	Mammal* ptr;
	Dog jindo;
	ptr = &jindo;
	ptr->speak();
	ptr->speak(5);
}