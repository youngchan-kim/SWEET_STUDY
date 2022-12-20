#include <iostream>
using namespace std;

void main()
{
	try
	{
		throw'a';	
	}
	catch (int)
	{
		cout << "Exception int" << endl;
	}
	catch (char)
	{
		cout << "Exception unsigned char" << endl;
	}
}