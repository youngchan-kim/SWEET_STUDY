#include "WinApiEngine.h"
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "DemoScene.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	ENGINE::WinApiEngine engine(hInstance, TEXT("WinAPI 2D Engine"),
		ENGINE::Client_Per_X, ENGINE::Client_Per_Y,
		ENGINE::ClientSize_Width, ENGINE::ClientSize_Height);

	//TODO:  여기에 새로운 씬 등록 및 로드
	
	MainMenuScene* mainmenu = new MainMenuScene;
	DemoScene *demoscene = new DemoScene;
	
	ENGINE::SceneMgr->RegisterScene("MainMenu", mainmenu);
	ENGINE::SceneMgr->RegisterScene("Demo", demoscene);

	//정상 실행시 ENGINE::SceneMgr->LoadScene("MainMenu");의 주석을 지움
	//ENGINE::SceneMgr->LoadScene("MainMenu");

	//Demo만 실행시 ENGINE::SceneMgr->LoadScene("Demo");의 주석을 지움
	ENGINE::SceneMgr->LoadScene("Demo");
	
	return engine.Run();
}
//22.07.25
/*
SceneManager추가
*/