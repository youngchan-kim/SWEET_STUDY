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
		if (!hWnd)return; //hWnd�� ���� ��찡 �ֳ�?

		this->hWnd = hWnd;
		this->width = width;
		this->height = height;
		//hDC�� hWnd�� DC�� ����Ѵ�.
		hDC = GetDC(hWnd);
		//hBackDC�� hDC�� DC�� ȣȯ�ǵ��� �Ѵ�.
		//�׸� ����� ������ �ƴ� ��Ʈ�ʿ� �׸��� �׸��°� ����
		hBackDC = CreateCompatibleDC(hDC);
		////�� �ʱ�ȭ��
		// FPS : EngineMecro::ENGINE::enum::FPS
		TimeMgr->Initialize(FPS); 
		////�� �ʱ�ȭ��
		InputMgr->Initialize();
		//�� �ʱ�ȭ�� ���ҽ� Ŭ����
		ResourceMgr->Initialize();
		////�� �ʱ�ȭ��
		UIMgr->Initialize();
	}

	VOID SceneManager::Release()
	{
		//���� ���� NULL
		currScene = NULL;
		UIMgr->Destroy();
		InputMgr->Destroy();

		//�ð��Ŵ��� ����
		TimeMgr->Destroy();

		//scenes�� ������ std::pair<std::string, Scene*>�� �����ϴ� ���� scene�� ����
		//std::pair<std::string, Scene*>���� Scene*�� ������ �̱� ������
		//REL_DEL(scene.second)�� �������൵ scenes�� Scene�������� ���� ������
		//�� scene�� Scene*�� scenes�� Scene*�� ���� �ּҸ� ������ ������ ������

		//�޸� ������ �����ϱ� ���� �����Ҵ��� Scene*�� �����ϱ� ���� Release�ϱ�����
		//for���� �� ������ scenes�� ó������ ������ ���� ����
		//���鼭 Release()�� ��
		for (std::pair<std::string, Scene*> scene : scenes) REL_DEL(scene.second);
		//Scene*�� ���� �Ҵ�� �κ��� ���� �Ǿ����ϱ�
		//���� ������ ������ �ִ� scenes�� clear ���ش�.
		scenes.clear();

		//hBackDC�� ����� ������ ������ Object���� ����
		DeleteObject(hBackDC);
		//hWnd���� hDC�� ����� ������ ������ ����
		ReleaseDC(hWnd, hDC);
		ResourceMgr->Destroy();
	}

	VOID SceneManager::Render()
	{
		if (!TimeMgr->Update())return;

		//���� ���� ������
		if (currScene)
		{
			Update();
			Draw();
			InputMgr->Update();
		}
		//�ʱ�ȭ�� 
		SetScene();
	}

	VOID SceneManager::SetScene()
	{
		//���� ���� ��� �ִٸ� ����
		if (nextScene.empty()) return;
		//���� ���� �ְ� ���� ���� �ִٸ� ������� ����
		if (currScene) 
		{ 
			currScene->Release(); 
			UIMgr->Clear();
			ResourceMgr->Clear();
		}

		currScene = scenes[nextScene];
		//���� ���� �ʱ�ȭ
		currScene->Initialize();
		//���� ���� ����ȭ
		nextScene = "";
	}

	VOID SceneManager::Update()
	{
		UIMgr->Update();
		//�� ������Ʈ Ÿ�Ӹ޴����� ��ŸŸ�� ����
		currScene->Update(TimeMgr->DeltaTime());
	}
	VOID SceneManager::Draw()
	{
		//���Ʈ���Ҵ�
		HBITMAP backBitmap = CreateDIBSectionRe();
		//hBackDC�� ���Ʈ���� ���
		SelectObject(hBackDC, backBitmap);
		//hBackDC�� currScene->Draw() �׸�
		currScene->Draw();
		UIMgr->Draw();
		//���� �̹����� ��ȭ���� �ʰ� �׸�
		BitBlt(hDC, 0, 0, width, height, hBackDC, 0, 0, SRCCOPY);
		//hBackDC�� backBitmap�� ����
		DeleteObject(backBitmap);
	}

	//���� �´��� Ȯ���� ������ ���� �߰�
	BOOL SceneManager::RegisterScene(LPCSTR sceneName, Scene* scene)
	{
		if ("" == sceneName || !scene || scenes.find(sceneName) != scenes.end()) return FALSE;
		//�� �߰�
		scenes.insert(std::make_pair(sceneName, scene));
		return TRUE;
	}

	//���� ������ �ε�
	BOOL SceneManager::LoadScene(LPCSTR sceneName)
	{
		//���� �̸��� ����ų�, ���� �̸��� NULL�̸� FALSE ����
		if ("" == sceneName || scenes.find(sceneName) == scenes.end())return FALSE;
		//���� �ε�
		nextScene = sceneName;
		return TRUE;
	}

	HBITMAP SceneManager::CreateDIBSectionRe()
	{
		BITMAPINFO bmpInfo;
		//bmpInfo�� ���� �ּ� ���� bmpInfo�� ũ�� ��ŭ�� �޸𸮸� 0���� ���� : 0���� �ʱ�ȭ
		ZeroMemory(&bmpInfo.bmiHeader, sizeof(BITMAPINFOHEADER));
		//��Ʈ���� ������
		bmpInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		//��Ʈ���� ������ ǥ���ϴ� ��Ʈ��
		bmpInfo.bmiHeader.biBitCount = 32;
		//�ʺ�
		bmpInfo.bmiHeader.biWidth = width;
		//����
		bmpInfo.bmiHeader.biHeight = height;
		//�г��� ���� 1��
		bmpInfo.bmiHeader.biPlanes = 1;
		LPVOID pBits;
		return CreateDIBSection(hDC, &bmpInfo, DIB_RGB_COLORS, (void**)&pBits, NULL, 0);
	}
} //namespace ENGINE