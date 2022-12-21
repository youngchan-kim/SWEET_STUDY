#include "SceneManager.h"
//SceneManager.cpp
#include "TimeManager.h"
#include "InputManager.h"
#include "ResourceManager.h"
#include "UIManager.h"
#include "DemoScene.h"

namespace ENGINE
{
	SceneManager::~SceneManager() { Release(); }

	VOID SceneManager::Initialize(HWND hWnd, UINT32 width, UINT32 height)
	{
		if (!hWnd)return; //hWnd가 없는 경우가 있나?

		this->hWnd = hWnd;
		this->width = width;
		this->height = height;
		//hDC는 hWnd의 DC를 사용한다.
		hDC = GetDC(hWnd);
		//hBackDC는 hDC의 DC에 호환되도록 한다.
		//그림 출력이 목적이 아닌 비트맵에 그림을 그리는게 목적
		hBackDC = CreateCompatibleDC(hDC);
		////씬 초기화시
		// FPS : EngineMecro::ENGINE::enum::FPS
		TimeMgr->Initialize(FPS); 
		////씬 초기화시
		InputMgr->Initialize();
		//씬 초기화시 리소스 클리어
		ResourceMgr->Initialize();
		////씬 초기화시
		UIMgr->Initialize();
	}

	VOID SceneManager::Release()
	{
		//현재 씬을 NULL
		currScene = NULL;
		UIMgr->Destroy();
		InputMgr->Destroy();

		//시간매니저 삭제
		TimeMgr->Destroy();

		//scenes의 정보를 std::pair<std::string, Scene*>를 리턴하는 변수 scene에 복사
		//std::pair<std::string, Scene*>에서 Scene*는 포인터 이기 때문에
		//REL_DEL(scene.second)로 삭제해줘도 scenes의 Scene정보또한 같이 삭제됨
		//즉 scene의 Scene*는 scenes의 Scene*와 같은 주소를 가졌기 때문에 가능함

		//메모리 누수를 방지하기 위해 동적할당한 Scene*를 삭제하기 위해 Release하기위함
		//for문을 쓴 이유는 scenes의 처음부터 끝까지 돌기 위함
		//돌면서 Release()를 함
		for (std::pair<std::string, Scene*> scene : scenes) REL_DEL(scene.second);
		//Scene*의 동적 할당된 부분이 삭제 되었으니까
		//남은 정보를 가지고 있는 scenes을 clear 해준다.
		scenes.clear();

		//hBackDC를 사용이 끝났기 때문에 Object에서 해제
		DeleteObject(hBackDC);
		//hWnd에서 hDC의 사용이 끝났기 때문에 해제
		ReleaseDC(hWnd, hDC);
		ResourceMgr->Destroy();
	}

	VOID SceneManager::Render()
	{
		if (!TimeMgr->Update())return;

		//현재 씬이 있으면
		if (currScene)
		{
			Update();
			Draw();
			InputMgr->Update();
		}
		//초기화씬 
		SetScene();
	}

	VOID SceneManager::SetScene()
	{
		//다음 씬이 비어 있다면 리턴
		if (nextScene.empty()) return;
		//다음 씬이 있고 현재 씬이 있다면 현재씬을 제거
		if (currScene) 
		{ 
			currScene->Release(); 
			UIMgr->Clear();
			ResourceMgr->Clear();
		}

		currScene = scenes[nextScene];
		//현재 씬을 초기화
		currScene->Initialize();
		//다음 씬을 공백화
		nextScene = "";
	}

	VOID SceneManager::Update()
	{
		UIMgr->Update();
		//씬 업데이트 타임메니저의 델타타임 실행
		currScene->Update(TimeMgr->DeltaTime());
	}
	VOID SceneManager::Draw()
	{
		//백비트맵할당
		HBITMAP backBitmap = CreateDIBSectionRe();
		//hBackDC는 백비트맵을 사용
		SelectObject(hBackDC, backBitmap);
		//hBackDC에 currScene->Draw() 그림
		currScene->Draw();
		UIMgr->Draw();
		//원본 이미지를 변화하지 않고 그림
		BitBlt(hDC, 0, 0, width, height, hBackDC, 0, 0, SRCCOPY);
		//hBackDC에 backBitmap을 해제
		DeleteObject(backBitmap);
	}

	//씬이 맞는지 확인후 맞으면 씬을 추가
	BOOL SceneManager::RegisterScene(LPCSTR sceneName, Scene* scene)
	{
		if ("" == sceneName || !scene || scenes.find(sceneName) != scenes.end()) return FALSE;
		//씬 추가
		scenes.insert(std::make_pair(sceneName, scene));
		return TRUE;
	}

	//씬이 있으면 로드
	BOOL SceneManager::LoadScene(LPCSTR sceneName)
	{
		//씬의 이름이 비었거나, 씬의 이름이 NULL이면 FALSE 리턴
		if ("" == sceneName || scenes.find(sceneName) == scenes.end())return FALSE;
		//씬을 로드
		nextScene = sceneName;
		return TRUE;
	}

	HBITMAP SceneManager::CreateDIBSectionRe()
	{
		BITMAPINFO bmpInfo;
		//bmpInfo의 시작 주소 부터 bmpInfo의 크기 만큼의 메모리를 0으로 만듬 : 0으로 초기화
		ZeroMemory(&bmpInfo.bmiHeader, sizeof(BITMAPINFOHEADER));
		//비트맵의 사이즈
		bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		//비트맵의 색상을 표한하는 비트수
		bmpInfo.bmiHeader.biBitCount = 32;
		//너비
		bmpInfo.bmiHeader.biWidth = width;
		//높이
		bmpInfo.bmiHeader.biHeight = height;
		//패널의 수는 1개
		bmpInfo.bmiHeader.biPlanes = 1;
		LPVOID pBits;
		return CreateDIBSection(hDC, &bmpInfo, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
	}
} //namespace ENGINE