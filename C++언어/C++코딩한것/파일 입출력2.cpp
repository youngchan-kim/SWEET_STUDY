#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main()
{
	ofstream save;
	save.open("test.txt", ios::app);
	if (save.is_open())
	{
		save << "\n�̰� ���� ����� �߰����";
		save.close();
	}
}