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

	void SetValue();
	void ShowSquare();
};

void Square::SetValue()
{
	do
	{
		cout << "���� �Է� : ";
		cin >> width;
		cout << "���� �Է� : ";
		cin >> height;

		if (MIN > width || MIN > height)
		{
			cout << "���� �Ǵ� ���ΰ� 1���� �۽��ϴ�." << endl;
			system("pause");
		}
	} while (MIN > width || MIN > height);

	ShowSquare();

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
					cout << "��";
				else if (j > MIN && j < width)
					cout << "��";
				else if (j == width)
					cout << "��";
			}
			else if (i > MIN && i < height)
			{
				if (j == MIN || j == width)
					cout << "��";
				else if (j > MIN && j < width)
					cout << "  ";
			}
			else if (i == height)
			{
				if (j == MIN)
					cout << "��";
				else if (j > MIN && j < width)
					cout << "��";
				else if (j == width)
					cout << "��";
			}
		}
		cout << endl;
	}
}

void main()
{
	Square S1;

	S1.SetValue();
}