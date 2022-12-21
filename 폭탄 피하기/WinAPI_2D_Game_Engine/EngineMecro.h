//Engine에서 사용할 Mecro 모음
///
/// 엔진에서 전반적으로 사용될 메크로 함수 및 인터페이스 정의
/// FPS 및 Window 크기를 지정해 둔다.
///

#pragma comment(lib, "msimg32.lib")
#include <crtdbg.h>
#include<windows.h>
#include<time.h>
#include<string>
#include<vector>
#include <map>
#include<functional>
#include<algorithm>
#include"Component.h"
#include <stdlib.h>

// 식별자 ENGINE_MECRO_H 이 없다면  ENGINE_MECRO_H의 #endif 가 나오기 전의 모든 것을 만들어 준다.
#ifndef ENGINE_MECRO_H
#define ENGINE_MECRO_H

#ifndef DEL 
#define DEL(a) if(a) {delete a; a = nullptr;}//delete 매크로 함수
#endif // !DEL

#ifndef REL_DEL
#define REL_DEL(a) if(a) { a->Release(); delete a; a = nullptr; } // Release() 함수 호출 후 delete
#endif // !REL_DEL

//void 형을 객체화 한다.
// 객체화한 void 함수를 EventListener라는 별명을 붙인다.
typedef std::function<VOID()> EventListener;

typedef struct position
{
	float x;
	float y;
}Position;

namespace ENGINE //namespace를 쓰는 이유?
{
	enum // 무명(no name) enum, 게임 엔진에 사용되는 여러 기본 데이터 설정 값
	{
		ClientSize_Width = 800, // 클라이언트의 너비 800
		ClientSize_Height = 600, // 클라이언트의 높이 600
		Client_Per_X = 50, 
		Client_Per_Y = 50, /* 0 ~ 100% */ //클라이언트의 높이의 퍼센트?
		FPS = 120 /* 초당 프레임 */
	};

	__interface Scene // 씬이라는 인터페이스를 만든다.
	{
		VOID Initialize();	//초기화
		VOID Release();		//삭제
		VOID Update(CONST FLOAT& deltaTime);	//업데이트, 수정
		VOID Draw();		//그리기 
	};
}

#endif // !ENGINE_MECRO_H
