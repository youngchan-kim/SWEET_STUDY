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
		save << "\n이건 파일 입출력 추가모드";
		save.close();
	}
}