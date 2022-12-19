#include <iostream>
int main()
{
	//char s[100];
	std::string s;
	std::cin >> s;
	bool flag = true;
	if (s.size() < 100)
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s.c_str()[i] >= 'a' && s.c_str()[i] <= 'z')flag = true;
			else { flag = false; break; }
		}
	}
	if (flag == true)
	{
		for (int j = 'a'; j <= 'z'; j++)
		{
			int c = -1;
			for (int i = 0; s[i] != NULL; i++)
			{
				if (s[i] == j) { c = i;  break; }
			}
			std::cout << c << " ";
		}
	}
	return 0;
}