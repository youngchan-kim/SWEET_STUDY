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
		save << "이건 파일 입출력";
		save.close();
	}
	ifstream load;
	string str;
	string tmp;
	load.open("test.txt");
	while (!load.eof())
	{
		getline(load, str);
		cout << str << endl;
	}

}