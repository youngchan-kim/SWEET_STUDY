#include "Math.h"

namespace ENGINE
{
	int Repeat(int value, const int& max)
	{
		//Max���� value�� Ŀ���� value�� 0���� ����
		if (value > max) return Repeat(value - (max + 1), max);
		else if (0 > value) return Repeat(max + (value + 1), max);
		return value;
	}
}
//�̱��� �κ��� .h���Ͽ� ����

