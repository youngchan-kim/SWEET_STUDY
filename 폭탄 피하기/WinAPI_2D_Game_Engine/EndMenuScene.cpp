#include "EndMenuScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"

EndMenuScene::EndMenuScene()
{
	ResourceMgr->Load("background.bmp");
	ResourceMgr->Load("base_panel.bmp");
	ResourceMgr->Load("play_normal.bmp");
	ResourceMgr->Load("play_pressed.bmp");
	ResourceMgr->Load("quit_normal.bmp");
	ResourceMgr->Load("quit_pressed.bmp");

	//범위(가로 너비)
	bounds = SceneMgr->GetWidth();
	btn_height = SceneMgr->GetHeight();
	//백그라운드 변수에 비트맵을 가져옴
	background = ResourceMgr->GetBitmap("background.bmp");
	//백그라운드를 그리는 사이즈는 씬의 너비와 높이로 설정하여 그린다.
	background->SetDrawSize(bounds, SceneMgr->GetHeight());


	//UI를 추가 종류는 UIimage 이름은  EndWindow Canvas
	EndWindow = UIMgr->AddUI<UIImage>("EndWindow Canvas");
	if (EndWindow)
	{
		EndWindow->Initialize("background.bmp",DrawType::Transparent);
		EndWindow->SetPosition(0, 0, TRUE);
		//UI 추가 UIbutton의 이름은 Play Btn 사용되는 곳은 배경에서 사용가능
		playBtn = UIMgr->AddUI<UIButton>("Play Btn", EndWindow);
		//스타트버튼의 초기값으로 play노말과 프레스 이미지를 가지고 타입은 Transparent을 가진다.
		playBtn->Initialize("play_normal.bmp", "play_pressed.bmp", "", "", DrawType::Transparent);

		//버튼의 위치
		//화면의 너비 중앙
		playBtn->SetPosition(bounds * 0.1f, btn_height * 0.7f);
		playBtn->SetListener(std::bind(&EndMenuScene::PlayBtnClickHandler, this));

		endquitBtn = UIMgr->AddUI<UIButton>("EndQuit Btn", EndWindow);
		endquitBtn->Initialize("quit_normal.bmp", "quit_pressed.bmp", "", "", DrawType::Transparent);
		endquitBtn->SetPosition(bounds * 0.6f, btn_height * 0.7f);
		endquitBtn->SetListener(std::bind(&EndMenuScene::QuitBtnClickHandler, this));


		font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"궁서");
		scoretitle = UIMgr->AddUI<UILabel>("Title", EndWindow);
		scoretitle->Initialize(std::to_string(score) + "점", RGB(220, 220, 220), font);
		scoretitle->SetPosition((bounds * 0.5f) - (scoretitle->GetSize().cx * 0.5f), btn_height * 0.1f);
		scoretitle->SetEnable(TRUE);
		EndWindow->SetEnable(FALSE);
	}

	isStart = FALSE;
}

VOID EndMenuScene::Update()
{
	scoretitle->SetText(std::to_string(score) + "점");
}

VOID EndMenuScene::Draw()
{
	background->StretchBlt(0, 0);
}
//플레이 일때로 바뀌어야함
VOID EndMenuScene::PlayBtnClickHandler()
{
	//스타트를 트루로 바꾼다.
	isStart = TRUE;
	scoretitle->SetEnable(FALSE);
	//버튼의 상호작용을 불가능하게 만든다.
	playBtn->SetInteracterble(FALSE);
	//스타트가 트루이면 Demo씬을 불러온다.
	if (isStart)	{ENGINE::SceneMgr->LoadScene("Demo");}
}
//종료
VOID EndMenuScene::QuitBtnClickHandler()
{
	PostQuitMessage(0);
}

VOID EndMenuScene::EndWindow_Enable_True()
{
	EndWindow->SetEnable(TRUE);
}

