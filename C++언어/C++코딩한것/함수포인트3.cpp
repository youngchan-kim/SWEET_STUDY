#include<iostream>
#include<functional>
using namespace std;
//람다식
//임시로 함수를 만드는것. (함수 명이 없다는 뜻의 익명의 함수)
//제활용불가
//사용되는곳 게임에서는 서버와 통신에 주로 사용된다.
//ex)던전의 보상을 주면서 패킷전달시
void Subfunc(int x, int y)
{
	cout << x << " - " << y << " = " << x - y << endl;
}

void func2(function<void(int, int)>p)
{
	p(15, 10);
}
void main()
{
	func2([](int x, int y) {
		cout << x << " + " << y << " = " << x + y << endl;
		});
	func2(Subfunc);
	return;
}