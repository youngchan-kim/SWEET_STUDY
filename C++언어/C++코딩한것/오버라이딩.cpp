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
	Mammal dongmul;
	Dog jindo;
	dongmul.speak();
	dongmul.speak(3);
	jindo.speak();
	//jindo.speak(5);

}