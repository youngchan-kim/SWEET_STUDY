#include <iostream>
using namespace std;
typedef int INT;
typedef int* PINT;

void main() 
{
	INT a = 10;
	cout << "a = " << a << endl;
	PINT pA = &a;
	cout << "a ÁÖ¼Ò : " << pA << "a °ª : " << *pA << endl;
}