#include "MainMenuScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"

namespace ENGINE
{
	VOID MainMenuScene::Initialize()
	{
		//���� �̹����� ��Ʈ�ʿ� �ε�
		ResourceMgr->Load("background.bmp");
		ResourceMgr->Load("base_panel.bmp");
		ResourceMgr->Load("play_normal.bmp");
		ResourceMgr->Load("play_pressed.bmp");
		ResourceMgr->Load("quit_normal.bmp");
		ResourceMgr->Load("quit_pressed.bmp");

		//����� ������ ���� �ʺ� ���
		bounds = SceneMgr->GetWidth();
		btn_height = SceneMgr->GetHeight();
		//��׶��� ������ ��Ʈ���� ������
		background = ResourceMgr->GetBitmap("base_panel.bmp");
		//��׶��带 �׸��� ������� ���� �ʺ�� ���̷� �����Ͽ� �׸���.
		background->SetDrawSize(bounds, SceneMgr->GetHeight());

		//UI�� �߰��� ������ UIButton �̸��� Start Btn
		startBtn = UIMgr->AddUI<UIButton>("Start Btn");

		//��ŸƮ��ư�� �ʱⰪ���� play�븻�� ������ �̹����� ������ Ÿ���� Transparent�� ������.
		startBtn->Initialize("play_normal.bmp", "play_pressed.bmp", "", "", DrawType::Transparent);
		//��ư�� ��ġ
		//ȭ���� �ʺ� �߾� : (bounds*0.5f) - (startBtn->GetSize().cx*0.5f)
		startBtn->SetPosition((bounds*0.5f) - (startBtn->GetSize().cx*0.5f) , btn_height*0.4f);
		//start��ư�� �����ʸ� ���� StartBtnClickHandler�� this(startBtn)�� ���´�.
		startBtn->SetListener(std::bind(&MainMenuScene::StartBtnClickHandler, this));

		//UI�� �߰��� ������ UIButton �̸��� Exit Btn
		quitBtn = UIMgr->AddUI<UIButton>("Exit Btn");

		quitBtn->Initialize("quit_normal.bmp", "quit_pressed.bmp", "", "", DrawType::Transparent);
		quitBtn->SetPosition((bounds * 0.5f) - (quitBtn->GetSize().cx * 0.5f), btn_height * 0.6f);
		quitBtn->SetListener(std::bind(&MainMenuScene::QuitBtnClickHandler, this));

		font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"�ü�");
		title = UIMgr->AddUI<UILabel>("Title");
		title->Initialize("hunglry man(����� ���)", RGB(220,220,220), font);
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
		//��ŸƮ�� Ʈ��� �ٲ۴�.
		isStart = TRUE;
		//��ư�� ��ȣ�ۿ��� �Ұ����ϰ� �����.
		startBtn->SetInteracterble(FALSE);
		//��ŸƮ�� Ʈ���̸� Demo���� �ҷ��´�.
		if(isStart)	ENGINE::SceneMgr->LoadScene("Demo");
	}
	VOID MainMenuScene::QuitBtnClickHandler()
	{
		PostQuitMessage(0);
	}
}//namespace ENGINE