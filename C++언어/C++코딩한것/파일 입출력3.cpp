#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void main()
{
	ofstream save;
	save.open("test.txt");
	if (save.is_open())
	{
		save << "�̰� ���� �����";
		save.close();
	}
	ifstream load;
	string str;
	string tmp;
	load.open("test.txt");
	while (!load.eof())
	{
		load >> tmp;
		str += tmp;
		str += " ";
	}
	cout << str;
}