#include <iostream>
using namespace std;

void main()
{
	int i = 5, j = 0;
	try
	{
		if (j == 0)
			throw "j�� 0\n";
		cout << i / j << endl;
					
	}
	catch (int k)
	{
		cout << " 0���� ���� �� �����ϴ�." << endl;
	}
	catch (const char* k)
	{
		cout << k << endl;
	}
}