// WinApiEngine.cpp
#include "WinApiEngine.h"
#include "InputManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  // �ݹ��Լ��� ��� ���� ��� �Ǵ��� �ñ��� 
// �ݹ� �Լ��� WinApiEngineŬ������ ����ϸ� �����ؼ� WinApiEngine��
// �Ҹ��ڰ� ���� ���� ������� �ʰ� �����ִٰ� WM_DESTROY��� �޽����� ������ ���� ����ȳ�?

namespace ENGINE
{
	WinApiEngine::WinApiEngine(HINSTANCE hInstance, std::wstring title, INT32 per_x, INT32 per_y, UINT32 width, UINT32 height)
		: isInit(FALSE), title(title), x(0), y(0), width(width), height(height) // :�ڿ� �ִ� ������ WinApiEngine�� �Ű������� �ʱ�ȭ �ϱ� ���Ѱ��̴�
		// �̰��� �ݷ� �ʱ�ȭ��� �Ѵ�.
		// width, height ��????
	{
		WNDCLASSEXW wcex =
		{
			sizeof(WNDCLASSEX),			//�� ����ü�� ũ��.
			CS_HREDRAW | CS_VREDRAW,	//�������� ��� ����, (CS_HREDRAW | CS_VREDRAW : �������� ũ�Ⱑ ����Ǹ� �ٽ� �׸���.)
			WndProc,					//������ �޽��� ó���� ����� ���ν���,
			0,							//cbClsExtra : Ŭ������ ���� ���� �޸� �Ҵ�,
			0,							//cbWndExtra : �����츦 ���� ���� �޸� �Ҵ�. �Ϲ������� ��� X
			hInstance,					//�ش� ���ø����̼��� �ν��Ͻ� �ڵ�.
			0,0,0,						//������, Ŀ��, ������ ���� ����.
			NULL,						//�޴� �̸�, �޴��� ��� ���θ� ����.
			L"2DEngineWindowClass",		//������ Ŭ���� �̸�. ������ ������ �̿�.
			NULL						//���� ������ ����.
		};
		//wcex�� ���� �Ⱦ��� ���� �ִٸ� 0���� �ʱ�ȭ �������
		//wcex�� ������ ��� �ִ� ���� �̿��ؼ�
		//RegisterClassExW()�Լ��� ���� ������ Ŭ������ ����մϴ�.
		//������ ����ü�� ������ �����츦 �����Ͽ� ����Ѵ�.
		RegisterClassExW(&wcex);

		//�����쿡 �����ϱ� ���� ������ �ڵ鷯 hWnd��  CreateWindow�� ���� �����츦 ���� �Ѵ�.
		HWND hWnd = CreateWindow(
			//wcex���� ���� ������ Ŭ������ �̸��� 
			//������� �����Ͽ� ��ϵ� ������ ����ü�� ã�Ƽ� �������ش�.
			//���� �ʿ�!
			TEXT("2DEngineWindowClass"), title.c_str(), 
			WS_SYSMENU | WS_MINIMIZEBOX,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, //��ġ�� ���� �� x,y , �ʺ� , ����
			nullptr, nullptr, hInstance, nullptr);

		//hWnd �� �������� �ʾҴٸ� �����Ѵ�.
		if (!hWnd) return;
		//hWnd �� ������ ����� �Ǿ� ������� ���� ���

		//������ �簢���� Ŭ���̾�Ʈ�� �簢���� ����
		//������ rect : ������ ȭ�� ��ǥ ������ ��ġ ������ ��ȯ�ϱ� ����
		//Ŭ���̾�Ʈ rect : ������ Ŭ���̾�Ʈ �������� ��ǥ ���� ��ȯ�ϱ����� ����

		RECT rcWindow, rcClient;
		//������ ȭ�� ��ǥ ������ ��ġ ������ ��ȯ�ϱ� ���� �Լ�
		GetWindowRect(hWnd, &rcWindow);
		//������ Ŭ���̾�Ʈ �������� ��ǥ ������ ��ġ ������ ��ȯ�ϱ� ���� �Լ�
		GetClientRect(hWnd, &rcClient);
		//CreateWindow�� ���ڷ� ���� �ʺ� , ���� ���� ����ũ �� ����� ũ�⸦ ������ ���̱� ������,
		// �� ���� ���� ���Ͽ� ������ ����� ���ϴ� Ŭ���̾�Ʈ �������� �ٽ� �����.

		//cx : �������� �ʺ� - Ŭ���̾���� �ʺ�
		UINT32 cx = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		//cy : �������� ���� - Ŭ���̾���� ����
		UINT32 cy = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		int screenWidth = GetSystemMetrics(SM_CXFULLSCREEN); //SM_CXFULLSCREEN: ��üȭ���� �ʺ�
		int screenHeight = GetSystemMetrics(SM_CYFULLSCREEN); //SM_CYFULLSCREEN: ��üȭ���� ����

		per_x = clamp(per_x, 0, 100); //per_x, per_y �� ������ 0 ~ 100 ���̷� ����.
		per_y = clamp(per_y, 0, 100);

		//x(0)�� x = per_x * 0.01f * (screenWidth - width)���� �ʱ�ȭ��
		x = per_x * 0.01f * (screenWidth - width); // �����츦 ����� (Screen)������ Ư�� ��ġ�� ����.
		//y(0)�� y = per_y * 0.01f * (screenHeight - height)���� �ʱ�ȭ��
		y = per_y * 0.01f * (screenHeight - height);

		MoveWindow(hWnd, x, y, width + cx, height + cy, false); // Window�� ��ġ �� ũ�⸦ �缳��.
		
		//������ �� ��Ʈ���� ǥ��/ ���� ���θ� �����ϰ�, �ִ�ȭ �� �ּ�ȭ ���θ� �����ϴ� �Լ�
		ShowWindow(hWnd, SW_SHOWDEFAULT); 
		//������ ������ ������ �ý����� ���¿� ������� �ﰢ �����ϴ� �Լ�
		UpdateWindow(hWnd);

		srand((unsigned)time(NULL));
		//���� Init�Լ��� ������ ����
//******/* Scene Initialized */
		//SceneManager�߰�
		SceneMgr->Initialize(hWnd, width, height);

		//�� ���� initialized�� �� �Ǹ� isInit���� true�� �ٲپ��ش�.
		isInit = TRUE;
	}

	//�Ҹ��� : Release�Լ��� ȣ���Ѵ�.
	WinApiEngine::~WinApiEngine() { Release(); }

	INT WinApiEngine::Run()
	{
		//�� ���� Init�� ����ȣ�� ���� ������ -1�� �����Ѵ�.
		if (!isInit)return -1;

		
		MSG msg;
		//�޼��� ������ �޸𸮸� 0���� �ʱ�ȭ
		//&msg�� �ּҿ� msg�� �����ŭ  �޸𸮸� 0���� �ʱ�ȭ�Ѵ�.
		ZeroMemory(&msg, sizeof(msg));
		//ȭ���� ������ �޼����� �ƴϸ� ����.
		while (WM_QUIT != msg.message) //Game Loop
		{
			//PeekMessage Ư�� �޼����� ������ �������� false�� ����
			//PM_REMOVE�� ���� �޼����� false�� �����ϸ� msg�� ���� �ʱ�ȭ�Ѵ�.
			if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg); //���� Ű �ڵ带 WM_CHAR���� ��밡���� ���ڷ� ��ȯ.
				DispatchMessage(&msg); //�߻��� �޽����� WndProc()�� �߼�, WndProc()�� ȣ��.
			}
			else 
			{
				/* Scene Render */ 
				//SceneManager�߰�
				SceneMgr->Render();
			}
		}
		Release();

		//�޼����� ���� int������ ����
		return (int)msg.wParam;
	}

	VOID WinApiEngine::Release()
	{
		/* Scene Destroy */
		//SceneManager�߰�
		SceneMgr->Destroy();
	}
}//namespace ENGINE

//�ݹ��� ��� ����ϰ� �ִٰ� �ش� ������ �Ǹ� ȣ��ǳ�
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	ENGINE::InputMgr->InputProc(iMessage, wParam, lParam);

	switch (iMessage)
	{
	case WM_DESTROY: PostQuitMessage(0); break;
	default: return (DefWindowProc(hWnd, iMessage, wParam, lParam));
	}

	return 0;
}


//�ݹ� �Լ� ����
//CreateWindow�� ���� �� ����
//width, height�� �� ����
//per_x, per_y�� ���� 0���� ũ�� 100���� ���� ������ ���� ������?
