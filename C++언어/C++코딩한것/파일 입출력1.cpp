#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	ofstream save;
	save.open("test.txt");
	if (save.is_open())
	{
		save << "이건 파일 입출력" << endl << "입니다.";
		save.close();
	}
}