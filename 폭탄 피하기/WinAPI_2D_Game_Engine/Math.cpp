#include "Math.h"

namespace ENGINE
{
	int Repeat(int value, const int& max)
	{
		//Max보다 value가 커지면 value를 0으로 만듬
		if (value > max) return Repeat(value - (max + 1), max);
		else if (0 > value) return Repeat(max + (value + 1), max);
		return value;
	}
}
//미구현 부분은 .h파일에 있음

