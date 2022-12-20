// WinApiEngine.h
//기본적인 설정을 하여 Window를 만들고 게임 루프를 작동한다.
//디폴트 생성자를 사용하지 않기 위하여 private에 선언 한다.
#include "EngineMecro.h"
//SceneManager 추가
#include "SceneManager.h"
// #ifndef ENGINE_MAIN_H 식별자 ENGINE_MAIN_H 가 없다면 실행
#ifndef ENGINE_MAIN_H
#define ENGINE_MAIN_H
namespace ENGINE
{
	class WinApiEngine
	{
	private:
		BOOL isInit;			// 초기화 했는지 안했는지
		INT32 x, y;				// int32의 32가 뭔지 : 32비트를 가진 int형 이라는 뜻
								// 사용 이유 : 모든 컴퓨터에서 정해진 int형의 크기만 쓰기 위함
		UINT32 width, height;	//unsignint : 정수만 있는 int 
		std::wstring title;		

		WinApiEngine(); // 생성자를 왜 두번 쓴거지
	public:
		WinApiEngine(HINSTANCE hInstance, std::wstring title, INT32 per_x, INT32 per_y, UINT32 width, UINT32 height);
		~WinApiEngine();

		INT Run(); //
		VOID Release();
	};
}

#endif // !ENGINE_MAIN_H
