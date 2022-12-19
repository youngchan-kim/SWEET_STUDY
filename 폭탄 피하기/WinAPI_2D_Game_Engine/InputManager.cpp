#include "InputManager.h"
#include "SceneManager.h"
namespace ENGINE
{
	InputManager::~InputManager() { Release(); }

	VOID InputManager::Release()
	{
		//str 값으 초기화
		str = "";
		//keys,mouse 클리어
		keys.clear();
		mouse.clear();
		//클라이언트의 마우스 고정 영역 해제
		EndCapture();
	}

	//업데이트 매번 호출되는 함수 keys와 button을 수정해준다.
	VOID InputManager::Update()
	{
		//들어오는 str값 초기화
		str = " ";
		//keys의 정보를 key로 복사해서 keys에 영향이 안가게 사용?
		//key라는 레퍼런스를 만들어서 keys의 다른 이름으로 사용
		for (std::pair<CONST UINT, InputState>& key : keys)
		{
			//key.second는 InputState정보
			switch (key.second)
			{
			case InputState::DOWN: key.second = InputState::PRESSED; break;
			case InputState::UP: key.second = InputState::NONE; break;
			}
		}
		//mouse의 정보를 button로 복사해서 mouse에 영향이 안가게 사용?
		for (std::pair<CONST UINT, InputState>& button : mouse)
		{
			//button.second는 InputState정보
			switch (button.second)
			{
			case InputState::DOWN: button.second = InputState::PRESSED; break;
			case InputState::UP: button.second = InputState::NONE; break;
			}
		}
	}

	//
	VOID InputManager::InputProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
			// wParam는 InputState의 값
			//str값을 wParam으로 바꾼다.
			//왜?
		case WM_CHAR: str = wParam; break;
			//WM_KEYDOWN는 ALT를 누르지 않을때 누를 키
			//WM_SYSKEYDOWN는 ALT나 F10을 눌렀을때 누를 키
		case WM_KEYDOWN: case WM_SYSKEYDOWN: SetKeyDown(wParam); break;
			//WM_KEYUP는 ALT를 누르지 않은 상태에서 키를 뗀 경우
			//WM_SYSKEYUP는 ALT를 누른 상태에서 키를 뗀 경우
		case WM_KEYUP: case WM_SYSKEYUP: SetKeyUp(wParam); break;	
			//WM_LBUTTONDOWN 마우스 왼쪽 버튼을 누르는 상태
		case WM_LBUTTONDOWN: SetMouseButtonDown(VK_LBUTTON); break;
			//WM_RBUTTONDOWN 마우스 오른쪽 버튼을 누르는 상태
		case WM_RBUTTONDOWN: SetMouseButtonDown(VK_RBUTTON); break;
			//WM_MBUTTONDOWN 마우스 휠 버튼을 누르는 상태
		case WM_MBUTTONDOWN: SetMouseButtonDown(VK_MBUTTON); break;
			//WM_XBUTTONDOWN 마우스 엄지버튼을 누르는 상태
		case WM_XBUTTONDOWN:
		{
			switch (wParam)
			{
				//WM_XBUTTONDOWN 마우스 엄지버튼1을 누르는 상태
			case XBUTTON1:SetMouseButtonDown(VK_XBUTTON1); break;
				//WM_XBUTTONDOWN 마우스 엄지버튼2을 누르는 상태
			case XBUTTON2:SetMouseButtonDown(VK_XBUTTON2); break;
			}
		}
		break;
			//WM_LBUTTONUP 마우스 왼쪽 버튼을 뗀 상태
		case WM_LBUTTONUP: SetMouseButtonUp(VK_LBUTTON); break;
			//WM_LBUTTONUP 마우스 오른쪽 버튼을 뗀 상태
		case WM_RBUTTONUP: SetMouseButtonUp(VK_RBUTTON); break;
			//WM_LBUTTONUP 마우스 휠버튼 버튼을 뗀 상태
		case WM_MBUTTONUP: SetMouseButtonUp(VK_MBUTTON); break;
			//WM_LBUTTONUP 마우스 엄지 버튼을 뗀 상태
		case WM_XBUTTONUP:
		{
			switch (wParam)
			{
				//WM_LBUTTONUP 마우스 엄지 버튼1을 뗀 상태
			case XBUTTON1:SetMouseButtonUp(VK_XBUTTON1); break;
				//WM_LBUTTONUP 마우스 엄지 버튼2을 뗀 상태
			case XBUTTON2:SetMouseButtonUp(VK_XBUTTON2); break;
			}
		}
		break;
		//마우스가 움직일때 좌표
		case WM_MOUSEMOVE: SetMousePosition(lParam); break;
		}
	}

	//아무키나 키를 누르면 누르고 있는지 아닌지를 bool형으로 반환
	BOOL InputManager::PressedAnyKey()
	{
		for (std::pair<CONST UINT, InputState>& key : keys) 
		{
			//해당 키의 InputState에 따라 반환
			switch (key.second) 
			{
			case InputState::DOWN: case InputState::PRESSED:return TRUE;
			}
		}
		return FALSE;
	}

	VOID InputManager::StartCapture()
	{
		HWND hWnd = SceneMgr->GetHWND();
		//마우스가 윈도우 영역 밖으로 나갔을때도 WM_MOUSEMOVE를 받을 수 있게 해줌
		SetCapture(hWnd);
		//윈도우 안에서 클라이언트 영역은 0,0, 너비+1, 높이 +1의 스크린을 가진다.
		POINT leftTop = { 0, 0 };
		POINT rightBottom = { SceneMgr->GetWidth() + 1, SceneMgr->GetHeight() + 1 };
		//ClientToScreen : 클라이언트 윈도우 기준으로 설정한 커서의 좌표를 전체 화면 기준으로 좌표를 변환해주는 함수
		//클라이언트 윈도우의 왼쪽 위가 0,0이 기준
		ClientToScreen(hWnd, &leftTop);
		//클라이언트 윈도우의 오른쪽 아래가 너비+1, 높이 +1이 기준
		ClientToScreen(hWnd, &rightBottom);

		//마우스를 고정할 영역
		RECT clip = { leftTop.x, leftTop.y,rightBottom.x,rightBottom.y };
		//마우스 포인터를 영역 밖으로 나가지 못하게 한다.
		ClipCursor(&clip);
	}

	VOID InputManager::EndCapture()
	{
		//클라이언트 영역에 고정해 놓은 마우스포인터를 해제
		ClipCursor(NULL);
		//클라이언트 영역을 해제
		ReleaseCapture();
	}

	//마우스를 누르고 있으면 클라이언트 영역 밖으로 못나간다.
	VOID InputManager::SetMouseButtonDown(UINT keyID)
	{
		//마우스 포인터를 클라이언트 영역에 묶어 놓는다.
		StartCapture();
		//마우스의 keyID의 InputState를 대입연산
		mouse[keyID] = InputState::DOWN;
	}

	VOID InputManager::SetMouseButtonUp(UINT keyID)
	{
		//마우스의 keyID의 InputState를 대입연산
		mouse[keyID] = InputState::UP;
		//마우스 포인터 고정을 해제해줌
		EndCapture();
	}

	// 눌러진 keyID를 찾으면 TRUE 반환 못찾으면 FALSE를 반환.
	BOOL InputManager::KeyCheck(UINT keyID, CONST InputManager::InputState& state)
	{
		// 눌러진 keyID를 keys의 정보중에서 찾는다.
		std::unordered_map<UINT, InputState>::iterator iter = keys.find(keyID);
		//keys의 정보 중에 있고 key의 state가 keys의 정보와 맞다면 true
		if (keys.end() != iter) return (state == iter->second);
		//keys의 정보중에 keyID가 없으면 추가한다. keyID를 만들고 state값은 NONE로 한다.
		keys.insert(std::make_pair(keyID, InputState::NONE));

		return FALSE;
	}

	// 눌러진 keyID를 찾으면 TRUE 반환 못찾으면 FALSE를 반환.
	BOOL InputManager::ButtonCheck(UINT keyID, CONST InputManager::InputState& state)
	{
		// 눌러진 keyID를 mouse의 정보중에서 찾는다.
		std::map<UINT, InputState>::iterator iter = mouse.find(keyID);
		//mouse의 정보 중에 있고 key의 state가 mouse의 정보와 맞다면 true
		if (mouse.end() != iter) return (state == iter->second);
		//mouse의 정보중에 keyID가 없으면 추가한다. keyID를 만들고 state값은 NONE로 한다.
		mouse.insert(std::make_pair(keyID, InputState::NONE));

		return FALSE;
	}
} //namespace ENGINE