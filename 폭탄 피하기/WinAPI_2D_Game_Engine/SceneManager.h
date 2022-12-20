#pragma once
// SceneManager.h
#include "Singleton.h"
#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H


namespace ENGINE
{
	class SceneManager : public Singleton< SceneManager>
	{
	private:
		HWND hWnd;
		HDC hDC, hBackDC;
		UINT32 width, height;

		Scene* currScene;
		std::string nextScene;
		std::map<std::string, Scene*> scenes;

		SceneManager() : hWnd(NULL), hDC(NULL), hBackDC(NULL), width(0), height(0), currScene(NULL) {}
	public :
		~SceneManager();

		VOID Initialize(HWND hWnd, UINT32 width, UINT32 height);
		VOID Release();
		VOID Render();

		//Scene�� ���.
		//RegisterScene(���� �ް� ���� �̸�, ���� �ּ�)
		BOOL RegisterScene(LPCSTR sceneName, Scene* scene); 

		//�ҷ� �� Scene�� ����.
		BOOL LoadScene(LPCSTR sceneName); 

		//�������� Ŭ���̾�Ʈ �ʺ�
		UINT32 GetWidth() CONST { return width; }
		//�������� Ŭ���̾�Ʈ ����
		UINT32 GetHeight() CONST { return height; }
		HWND GetHWND() CONST { return hWnd; }
		HDC GetBackDC() CONST { return hBackDC; }

	private:
		VOID SetScene(); // ��ϵ� Scene�� ����.
		VOID Update();
		VOID Draw();
		HBITMAP CreateDIBSectionRe(); //Back Bitmap�� ��������� ��Ʈ�� Creater

		friend Singleton;
	}; // class SceneManager
#define SceneMgr SceneManager::GetInstance()
} // namespace ENGINE

#endif // !SCENE_MANAGER_H
