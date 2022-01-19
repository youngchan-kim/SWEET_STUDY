#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

#define TRUE 1
#define MIN 1

class Square
{
private:
	int width, height;
public:

	bool SetValue(int _width, int _height);
	void ShowSquare();
};

bool Square::SetValue(int _width, int _height)
{
	if (MIN > _width || MIN > _height)
	{
		cout << "가로 또는 세로가 1보다 작습니다." << endl;
		system("pause");
		return false;
	}
	else 
	{
		width = _width;
		height = _height;
		return true;
	}
}

void Square::ShowSquare()
{
	for (int i = MIN; i <= height; i++)
	{
		for (int j = MIN; j <= width; j++)
		{
			if (i == MIN)
			{
				if (j == MIN)
					cout << "┌";
				else if (j > MIN && j < width)
					cout << "─";
				else if (j == width)
					cout << "┐";
			}
			else if (i > MIN && i < height)
			{
				if (j == MIN || j == width)
					cout << "│";
				else if (j > MIN && j < width)
					cout << "  ";
			}
			else if (i == height)
			{
				if (j == MIN)
					cout << "└";
				else if (j > MIN && j < width)
					cout << "─";
				else if (j == width)
					cout << "┘";
			}
		}
		cout << endl;
	}
}

void main()
{
	int width, height;
	bool overvalue;
	Square S1;
	while (TRUE)
	{
		cout << "가로 입력 : ";
		cin >> width;
		cout << "세로 입력 : ";
		cin >> height;
		overvalue = S1.SetValue(width, height);
		if (overvalue == true)
		{
			S1.ShowSquare();
			return;
		}
	}
}


