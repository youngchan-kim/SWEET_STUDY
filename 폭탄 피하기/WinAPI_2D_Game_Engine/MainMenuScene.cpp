#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"

namespace ENGINE
{
	VOID MainMenuScene::Initialize()
	{
		//각각 이미지를 비트맵에 로드
		ResourceMgr->Load("background.bmp");
		ResourceMgr->Load("base_panel.bmp");
		ResourceMgr->Load("play_normal.bmp");
		ResourceMgr->Load("play_pressed.bmp");
		ResourceMgr->Load("quit_normal.bmp");
		ResourceMgr->Load("quit_pressed.bmp");

		//사용할 범위를 씬의 너비를 사용
		bounds = SceneMgr->GetWidth();
		btn_height = SceneMgr->GetHeight();
		//백그라운드 변수에 비트맵을 가져옴
		background = ResourceMgr->GetBitmap("base_panel.bmp");
		//백그라운드를 그리는 사이즈는 씬의 너비와 높이로 설정하여 그린다.
		background->SetDrawSize(bounds, SceneMgr->GetHeight());

		//UI를 추가함 종류는 UIButton 이름은 Start Btn
		startBtn = UIMgr->AddUI<UIButton>("Start Btn");

		//스타트버튼의 초기값으로 play노말과 프레스 이미지를 가지고 타입은 Transparent을 가진다.
		startBtn->Initialize("play_normal.bmp", "play_pressed.bmp", "", "", DrawType::Transparent);
		//버튼의 위치
		//화면은 너비 중앙 : (bounds*0.5f) - (startBtn->GetSize().cx*0.5f)
		startBtn->SetPosition((bounds*0.5f) - (startBtn->GetSize().cx*0.5f) , btn_height*0.4f);
		//start버튼의 리스너를 셋팅 StartBtnClickHandler와 this(startBtn)를 묶는다.
		startBtn->SetListener(std::bind(&MainMenuScene::StartBtnClickHandler, this));

		//UI를 추가함 종류는 UIButton 이름은 Exit Btn
		quitBtn = UIMgr->AddUI<UIButton>("Exit Btn");

		quitBtn->Initialize("quit_normal.bmp", "quit_pressed.bmp", "", "", DrawType::Transparent);
		quitBtn->SetPosition((bounds * 0.5f) - (quitBtn->GetSize().cx * 0.5f), btn_height * 0.6f);
		quitBtn->SetListener(std::bind(&MainMenuScene::QuitBtnClickHandler, this));

		font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"궁서");
		title = UIMgr->AddUI<UILabel>("Title");
		title->Initialize("hunglry man(배고픈 사람)", RGB(220,220,220), font);
		title->SetPosition((bounds * 0.5f) - (title->GetSize().cx * 0.5f), btn_height * 0.1f);

		isStart = FALSE;
	}

	VOID MainMenuScene::Release()
	{
		return VOID();
	}

	VOID MainMenuScene::Update(const FLOAT& deltaTime)
	{
		return VOID();
	}


	VOID MainMenuScene::Draw()
	{
		background->StretchBlt(0, 0);
	}
	VOID MainMenuScene::StartBtnClickHandler()
	{
		//스타트를 트루로 바꾼다.
		isStart = TRUE;
		//버튼의 상호작용을 불가능하게 만든다.
		startBtn->SetInteracterble(FALSE);
		//스타트가 트루이면 Demo씬을 불러온다.
		if(isStart)	ENGINE::SceneMgr->LoadScene("Demo");
	}
	VOID MainMenuScene::QuitBtnClickHandler()
	{
		PostQuitMessage(0);
	}
}//namespace ENGINE