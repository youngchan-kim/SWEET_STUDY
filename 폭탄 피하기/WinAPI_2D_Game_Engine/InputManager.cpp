#include "InputManager.h"
#include "SceneManager.h"
namespace ENGINE
{
	InputManager::~InputManager() { Release(); }

	VOID InputManager::Release()
	{
		//str ���� �ʱ�ȭ
		str = "";
		//keys,mouse Ŭ����
		keys.clear();
		mouse.clear();
		//Ŭ���̾�Ʈ�� ���콺 ���� ���� ����
		EndCapture();
	}

	//������Ʈ �Ź� ȣ��Ǵ� �Լ� keys�� button�� �������ش�.
	VOID InputManager::Update()
	{
		//������ str�� �ʱ�ȭ
		str = " ";
		//keys�� ������ key�� �����ؼ� keys�� ������ �Ȱ��� ���?
		//key��� ���۷����� ���� keys�� �ٸ� �̸����� ���
		for (std::pair<CONST UINT, InputState>& key : keys)
		{
			//key.second�� InputState����
			switch (key.second)
			{
			case InputState::DOWN: key.second = InputState::PRESSED; break;
			case InputState::UP: key.second = InputState::NONE; break;
			}
		}
		//mouse�� ������ button�� �����ؼ� mouse�� ������ �Ȱ��� ���?
		for (std::pair<CONST UINT, InputState>& button : mouse)
		{
			//button.second�� InputState����
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
			// wParam�� InputState�� ��
			//str���� wParam���� �ٲ۴�.
			//��?
		case WM_CHAR: str = wParam; break;
			//WM_KEYDOWN�� ALT�� ������ ������ ���� Ű
			//WM_SYSKEYDOWN�� ALT�� F10�� �������� ���� Ű
		case WM_KEYDOWN: case WM_SYSKEYDOWN: SetKeyDown(wParam); break;
			//WM_KEYUP�� ALT�� ������ ���� ���¿��� Ű�� �� ���
			//WM_SYSKEYUP�� ALT�� ���� ���¿��� Ű�� �� ���
		case WM_KEYUP: case WM_SYSKEYUP: SetKeyUp(wParam); break;	
			//WM_LBUTTONDOWN ���콺 ���� ��ư�� ������ ����
		case WM_LBUTTONDOWN: SetMouseButtonDown(VK_LBUTTON); break;
			//WM_RBUTTONDOWN ���콺 ������ ��ư�� ������ ����
		case WM_RBUTTONDOWN: SetMouseButtonDown(VK_RBUTTON); break;
			//WM_MBUTTONDOWN ���콺 �� ��ư�� ������ ����
		case WM_MBUTTONDOWN: SetMouseButtonDown(VK_MBUTTON); break;
			//WM_XBUTTONDOWN ���콺 ������ư�� ������ ����
		case WM_XBUTTONDOWN:
		{
			switch (wParam)
			{
				//WM_XBUTTONDOWN ���콺 ������ư1�� ������ ����
			case XBUTTON1:SetMouseButtonDown(VK_XBUTTON1); break;
				//WM_XBUTTONDOWN ���콺 ������ư2�� ������ ����
			case XBUTTON2:SetMouseButtonDown(VK_XBUTTON2); break;
			}
		}
		break;
			//WM_LBUTTONUP ���콺 ���� ��ư�� �� ����
		case WM_LBUTTONUP: SetMouseButtonUp(VK_LBUTTON); break;
			//WM_LBUTTONUP ���콺 ������ ��ư�� �� ����
		case WM_RBUTTONUP: SetMouseButtonUp(VK_RBUTTON); break;
			//WM_LBUTTONUP ���콺 �ٹ�ư ��ư�� �� ����
		case WM_MBUTTONUP: SetMouseButtonUp(VK_MBUTTON); break;
			//WM_LBUTTONUP ���콺 ���� ��ư�� �� ����
		case WM_XBUTTONUP:
		{
			switch (wParam)
			{
				//WM_LBUTTONUP ���콺 ���� ��ư1�� �� ����
			case XBUTTON1:SetMouseButtonUp(VK_XBUTTON1); break;
				//WM_LBUTTONUP ���콺 ���� ��ư2�� �� ����
			case XBUTTON2:SetMouseButtonUp(VK_XBUTTON2); break;
			}
		}
		break;
		//���콺�� �����϶� ��ǥ
		case WM_MOUSEMOVE: SetMousePosition(lParam); break;
		}
	}

	//�ƹ�Ű�� Ű�� ������ ������ �ִ��� �ƴ����� bool������ ��ȯ
	BOOL InputManager::PressedAnyKey()
	{
		for (std::pair<CONST UINT, InputState>& key : keys) 
		{
			//�ش� Ű�� InputState�� ���� ��ȯ
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
		//���콺�� ������ ���� ������ ���������� WM_MOUSEMOVE�� ���� �� �ְ� ����
		SetCapture(hWnd);
		//������ �ȿ��� Ŭ���̾�Ʈ ������ 0,0, �ʺ�+1, ���� +1�� ��ũ���� ������.
		POINT leftTop = { 0, 0 };
		POINT rightBottom = { SceneMgr->GetWidth() + 1, SceneMgr->GetHeight() + 1 };
		//ClientToScreen : Ŭ���̾�Ʈ ������ �������� ������ Ŀ���� ��ǥ�� ��ü ȭ�� �������� ��ǥ�� ��ȯ���ִ� �Լ�
		//Ŭ���̾�Ʈ �������� ���� ���� 0,0�� ����
		ClientToScreen(hWnd, &leftTop);
		//Ŭ���̾�Ʈ �������� ������ �Ʒ��� �ʺ�+1, ���� +1�� ����
		ClientToScreen(hWnd, &rightBottom);

		//���콺�� ������ ����
		RECT clip = { leftTop.x, leftTop.y,rightBottom.x,rightBottom.y };
		//���콺 �����͸� ���� ������ ������ ���ϰ� �Ѵ�.
		ClipCursor(&clip);
	}

	VOID InputManager::EndCapture()
	{
		//Ŭ���̾�Ʈ ������ ������ ���� ���콺�����͸� ����
		ClipCursor(NULL);
		//Ŭ���̾�Ʈ ������ ����
		ReleaseCapture();
	}

	//���콺�� ������ ������ Ŭ���̾�Ʈ ���� ������ ��������.
	VOID InputManager::SetMouseButtonDown(UINT keyID)
	{
		//���콺 �����͸� Ŭ���̾�Ʈ ������ ���� ���´�.
		StartCapture();
		//���콺�� keyID�� InputState�� ���Կ���
		mouse[keyID] = InputState::DOWN;
	}

	VOID InputManager::SetMouseButtonUp(UINT keyID)
	{
		//���콺�� keyID�� InputState�� ���Կ���
		mouse[keyID] = InputState::UP;
		//���콺 ������ ������ ��������
		EndCapture();
	}

	// ������ keyID�� ã���� TRUE ��ȯ ��ã���� FALSE�� ��ȯ.
	BOOL InputManager::KeyCheck(UINT keyID, CONST InputManager::InputState& state)
	{
		// ������ keyID�� keys�� �����߿��� ã�´�.
		std::unordered_map<UINT, InputState>::iterator iter = keys.find(keyID);
		//keys�� ���� �߿� �ְ� key�� state�� keys�� ������ �´ٸ� true
		if (keys.end() != iter) return (state == iter->second);
		//keys�� �����߿� keyID�� ������ �߰��Ѵ�. keyID�� ����� state���� NONE�� �Ѵ�.
		keys.insert(std::make_pair(keyID, InputState::NONE));

		return FALSE;
	}

	// ������ keyID�� ã���� TRUE ��ȯ ��ã���� FALSE�� ��ȯ.
	BOOL InputManager::ButtonCheck(UINT keyID, CONST InputManager::InputState& state)
	{
		// ������ keyID�� mouse�� �����߿��� ã�´�.
		std::map<UINT, InputState>::iterator iter = mouse.find(keyID);
		//mouse�� ���� �߿� �ְ� key�� state�� mouse�� ������ �´ٸ� true
		if (mouse.end() != iter) return (state == iter->second);
		//mouse�� �����߿� keyID�� ������ �߰��Ѵ�. keyID�� ����� state���� NONE�� �Ѵ�.
		mouse.insert(std::make_pair(keyID, InputState::NONE));

		return FALSE;
	}
} //namespace ENGINE