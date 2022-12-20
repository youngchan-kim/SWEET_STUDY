#include <iostream>
#include <string>

using namespace std;


string str = "Global Variable\n";

namespace Nsp
{
	string str = "Namespace Variable\n";
}

void main()
{
	string str = "Local Variable\n";
	cout << str;
	cout << Nsp::str;
	cout << ::str;
}