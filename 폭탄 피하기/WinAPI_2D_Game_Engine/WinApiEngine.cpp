// WinApiEngine.cpp
#include "WinApiEngine.h"
#include "InputManager.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  // 콜백함수의 사용 언제 사용 되는지 궁금함 
// 콜백 함수를 WinApiEngine클래스를 사용하면 시작해서 WinApiEngine가
// 소멸자가 끝이 나도 종료되지 않고 남아있다가 WM_DESTROY라는 메시지가 들어오는 순간 실행된나?

namespace ENGINE
{
	WinApiEngine::WinApiEngine(HINSTANCE hInstance, std::wstring title, INT32 per_x, INT32 per_y, UINT32 width, UINT32 height)
		: isInit(FALSE), title(title), x(0), y(0), width(width), height(height) // :뒤에 있는 값들은 WinApiEngine의 매개변수를 초기화 하기 위한것이다
		// 이것을 콜론 초기화라고 한다.
		// width, height 값????
	{
		WNDCLASSEXW wcex =
		{
			sizeof(WNDCLASSEX),			//이 구조체의 크기.
			CS_HREDRAW | CS_VREDRAW,	//윈도우의 출력 형태, (CS_HREDRAW | CS_VREDRAW : 윈도우의 크기가 변경되면 다시 그린다.)
			WndProc,					//윈도우 메시지 처리에 사용할 프로시저,
			0,							//cbClsExtra : 클래스를 위한 여분 메모리 할당,
			0,							//cbWndExtra : 윈도우를 위한 여분 메모리 할당. 일반적으로 사용 X
			hInstance,					//해당 어플리케이션의 인스턴스 핸들.
			0,0,0,						//아이콘, 커서, 윈도우 배경색 설정.
			NULL,						//메뉴 이름, 메뉴의 사용 여부를 결정.
			L"2DEngineWindowClass",		//윈도우 클래스 이름. 윈도우 생성시 이용.
			NULL						//작은 아이콘 설정.
		};
		//wcex의 값중 안쓰는 값이 있다면 0으로 초기화 해줘야함
		//wcex의 변수에 들어 있는 값을 이용해서
		//RegisterClassExW()함수를 통해 원도우 클래스를 등록합니다.
		//윈도우 구조체로 생성할 윈도우를 정의하여 등록한다.
		RegisterClassExW(&wcex);

		//윈도우에 접근하기 위한 윈도우 핸들러 hWnd에  CreateWindow로 만든 윈도우를 연결 한다.
		HWND hWnd = CreateWindow(
			//wcex에서 정한 윈도우 클래스의 이름을 
			//적어줘야 참조하여 등록된 윈도우 구조체를 찾아서 생성해준다.
			//설명 필요!
			TEXT("2DEngineWindowClass"), title.c_str(), 
			WS_SYSMENU | WS_MINIMIZEBOX,
			CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, //위치에 대한 값 x,y , 너비 , 높이
			nullptr, nullptr, hInstance, nullptr);

		//hWnd 가 생성되지 않았다면 종료한다.
		if (!hWnd) return;
		//hWnd 가 생성이 제대로 되어 종료되지 않은 경우

		//윈도우 사각형과 클라이언트의 사각형을 만듦
		//윈도우 rect : 윈도우 화면 좌표 값으로 위치 정보를 반환하기 위함
		//클라이언트 rect : 윈도우 클라이언트 영역에서 좌표 값을 반환하기위해 만듦

		RECT rcWindow, rcClient;
		//윈도우 화면 좌표 값으로 위치 정보를 반환하기 위한 함수
		GetWindowRect(hWnd, &rcWindow);
		//윈도우 클라이언트 영역에서 좌표 값으로 위치 정보를 반환하기 위한 함수
		GetClientRect(hWnd, &rcClient);
		//CreateWindow의 인자로 들어가는 너비 , 높이 값은 데스크 방 등등의 크기를 포함한 값이기 때문에,
		// 그 차이 값을 구하여 윈도우 사이즈를 원하는 클라이언트 영역으로 다시 만든다.

		//cx : 윈도우의 너비 - 클라이언드의 너비
		UINT32 cx = (rcWindow.right - rcWindow.left) - (rcClient.right - rcClient.left);
		//cy : 윈도우의 높이 - 클라이언드의 높이
		UINT32 cy = (rcWindow.bottom - rcWindow.top) - (rcClient.bottom - rcClient.top);

		int screenWidth = GetSystemMetrics(SM_CXFULLSCREEN); //SM_CXFULLSCREEN: 전체화면의 너비
		int screenHeight = GetSystemMetrics(SM_CYFULLSCREEN); //SM_CYFULLSCREEN: 전체화면의 높이

		per_x = clamp(per_x, 0, 100); //per_x, per_y 값 범위를 0 ~ 100 사이로 제한.
		per_y = clamp(per_y, 0, 100);

		//x(0)을 x = per_x * 0.01f * (screenWidth - width)으로 초기화함
		x = per_x * 0.01f * (screenWidth - width); // 윈도우를 모니터 (Screen)범위를 특정 위치로 변경.
		//y(0)을 y = per_y * 0.01f * (screenHeight - height)으로 초기화함
		y = per_y * 0.01f * (screenHeight - height);

		MoveWindow(hWnd, x, y, width + cx, height + cy, false); // Window의 위치 및 크기를 재설정.
		
		//윈도우 및 컨트롤의 표시/ 숨김 여부를 성정하고, 최대화 및 최소화 여부를 설정하는 함수
		ShowWindow(hWnd, SW_SHOWDEFAULT); 
		//갱신할 영역이 있으면 시스템의 상태와 상관없이 즉각 생신하는 함수
		UpdateWindow(hWnd);

		srand((unsigned)time(NULL));
		//씬의 Init함수가 들어오는 구역
//******/* Scene Initialized */
		//SceneManager추가
		SceneMgr->Initialize(hWnd, width, height);

		//각 씬의 initialized이 다 되면 isInit값을 true로 바꾸어준다.
		isInit = TRUE;
	}

	//소멸자 : Release함수를 호출한다.
	WinApiEngine::~WinApiEngine() { Release(); }

	INT WinApiEngine::Run()
	{
		//각 씬의 Init이 정상호출 되지 않으면 -1을 리턴한다.
		if (!isInit)return -1;

		
		MSG msg;
		//메세지 변수의 메모리를 0으로 초기화
		//&msg의 주소에 msg의 사이즈만큼  메모리를 0으로 초기화한다.
		ZeroMemory(&msg, sizeof(msg));
		//화면이 꺼지는 메세지가 아니면 돈다.
		while (WM_QUIT != msg.message) //Game Loop
		{
			//PeekMessage 특정 메세지가 들어오기 전까지는 false를 리턴
			//PM_REMOVE는 들어온 메세지가 false를 리턴하면 msg의 값을 초기화한다.
			if (PeekMessage(&msg, nullptr, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg); //가상 키 코드를 WM_CHAR에서 사용가능한 문자로 변환.
				DispatchMessage(&msg); //발생한 메시지를 WndProc()에 발송, WndProc()가 호출.
			}
			else 
			{
				/* Scene Render */ 
				//SceneManager추가
				SceneMgr->Render();
			}
		}
		Release();

		//메세지의 값을 int형으로 리턴
		return (int)msg.wParam;
	}

	VOID WinApiEngine::Release()
	{
		/* Scene Destroy */
		//SceneManager추가
		SceneMgr->Destroy();
	}
}//namespace ENGINE

//콜백의 경우 대기하고 있다가 해당 조건이 되면 호출되나
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


//콜백 함수 질문
//CreateWindow에 들어가는 값 질문
//width, height의 값 질문
//per_x, per_y의 값은 0보다 크고 100보다 작은 임의의 수로 들어가는지?
