#include <iostream>
#include <string>

using namespace std;

namespace A
{
	int score = 100;
	string name = "A��";
}

namespace B
{
	int score = 200;
	string name = "B��";
}

using namespace A;

void main()
{
	cout << name << "Score = " << score << endl;
	cout << B::name << "Score = " << B::score << endl;
}