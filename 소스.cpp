
//함수 포인터

#include<iostream>

void func(int value)
{
	std::cout << "func : " << value << std::endl;
}
void func_print(void(*fp)(int), int value)
{
	//int형를 매개 변수로 받는 fp이름의 함수를 가리키는 변수 즉, 함수를 매개변수로 쓸때 사용됨
	//fp는 현재 func를 기리키고 있음
	//fp(value) 는 func(value)임
	fp(value);
}
//int main()
//{
//	func_print(func, 1);
//}

int main()
{
	//func를 가리키는 funcp라는 변수를 만듦
	void(*funcp)(int) = func;
	//변수 funcp는 func함수 이므로 실제로는 
	func_print(funcp, 1);
}

