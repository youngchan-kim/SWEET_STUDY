#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	ofstream save;
	save.open("test.txt");
	if (save.is_open())
	{
		save << "�̰� ���� �����" << endl << "�Դϴ�.";
		save.close();
	}
}