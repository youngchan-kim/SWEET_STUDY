#include <iostream>
using namespace std;

void main()
{
	int i = 5, j = 0;
	try
	{
		if (j == 0)
			throw j;
		cout << i / j << endl;
					
	}
	catch (int k)
	{
		cout << " 0���� ���� �� �����ϴ�." << endl;
	}
}