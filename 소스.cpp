
//�Լ� ������

#include<iostream>

void func(int value)
{
	std::cout << "func : " << value << std::endl;
}
void func_print(void(*fp)(int), int value)
{
	//int���� �Ű� ������ �޴� fp�̸��� �Լ��� ����Ű�� ���� ��, �Լ��� �Ű������� ���� ����
	//fp�� ���� func�� �⸮Ű�� ����
	//fp(value) �� func(value)��
	fp(value);
}
//int main()
//{
//	func_print(func, 1);
//}

int main()
{
	//func�� ����Ű�� funcp��� ������ ����
	void(*funcp)(int) = func;
	//���� funcp�� func�Լ� �̹Ƿ� �����δ� 
	func_print(funcp, 1);
}

