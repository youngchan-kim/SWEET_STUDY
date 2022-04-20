#include <iostream>

class count
{
	int cnt1;
	int cnt2;
public:
	count() { cnt1 = 0; cnt2 = 0; }
	count(int n1, int n2) { cnt1 = n1; cnt2 = n2; }
	int GetCnt1() { return cnt1; }
	int GetCnt2() { return cnt2; }
	void operator++() { ++cnt1; ++cnt2; }
	void operator--() { --cnt1; --cnt2; }
	void operator++(int) { cnt1++; cnt2++; }
	void operator--(int) { cnt1--; cnt2--; }
};


void main()
{
	count a;
	std::cout << a.GetCnt1() << std::endl;
	std::cout << a.GetCnt1() << std::endl;
	//Point ov1(10, 20), ov2(10, 20);
	//if (ov1 == ov2)
	//	cout << "°°´Ù." << "\n";
}