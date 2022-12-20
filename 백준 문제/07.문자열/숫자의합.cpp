#include <iostream>

int main()
{

	int a,c =0;
	std::cin >> a;
	char b[100];
	if (1 <= a && a <= 100)
	{
		for (int i = 0; i < a; i++)
		{
			std::cin >> b[i];
			c += (b[i]-48);
		}
		std::cout << c;
	}
	return 0;
}