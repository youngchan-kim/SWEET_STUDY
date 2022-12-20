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

	//����(���� �ʺ�)
	bounds = SceneMgr->GetWidth();
	btn_height = SceneMgr->GetHeight();
	//��׶��� ������ ��Ʈ���� ������
	background = ResourceMgr->GetBitmap("background.bmp");
	//��׶��带 �׸��� ������� ���� �ʺ�� ���̷� �����Ͽ� �׸���.
	background->SetDrawSize(bounds, SceneMgr->GetHeight());


	//UI�� �߰� ������ UIimage �̸���  EndWindow Canvas
	EndWindow = UIMgr->AddUI<UIImage>("EndWindow Canvas");
	if (EndWindow)
	{
		EndWindow->Initialize("background.bmp",DrawType::Transparent);
		EndWindow->SetPosition(0, 0, TRUE);
		//UI �߰� UIbutton�� �̸��� Play Btn ���Ǵ� ���� ��濡�� ��밡��
		playBtn = UIMgr->AddUI<UIButton>("Play Btn", EndWindow);
		//��ŸƮ��ư�� �ʱⰪ���� play�븻�� ������ �̹����� ������ Ÿ���� Transparent�� ������.
		playBtn->Initialize("play_normal.bmp", "play_pressed.bmp", "", "", DrawType::Transparent);

		//��ư�� ��ġ
		//ȭ���� �ʺ� �߾�
		playBtn->SetPosition(bounds * 0.1f, btn_height * 0.7f);
		playBtn->SetListener(std::bind(&EndMenuScene::PlayBtnClickHandler, this));

		endquitBtn = UIMgr->AddUI<UIButton>("EndQuit Btn", EndWindow);
		endquitBtn->Initialize("quit_normal.bmp", "quit_pressed.bmp", "", "", DrawType::Transparent);
		endquitBtn->SetPosition(bounds * 0.6f, btn_height * 0.7f);
		endquitBtn->SetListener(std::bind(&EndMenuScene::QuitBtnClickHandler, this));


		font = CreateFont(40, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"�ü�");
		scoretitle = UIMgr->AddUI<UILabel>("Title", EndWindow);
		scoretitle->Initialize(std::to_string(score) + "��", RGB(220, 220, 220), font);
		scoretitle->SetPosition((bounds * 0.5f) - (scoretitle->GetSize().cx * 0.5f), btn_height * 0.1f);
		scoretitle->SetEnable(TRUE);
		EndWindow->SetEnable(FALSE);
	}

	isStart = FALSE;
}

VOID EndMenuScene::Update()
{
	scoretitle->SetText(std::to_string(score) + "��");
}

VOID EndMenuScene::Draw()
{
	background->StretchBlt(0, 0);
}
//�÷��� �϶��� �ٲ�����
VOID EndMenuScene::PlayBtnClickHandler()
{
	//��ŸƮ�� Ʈ��� �ٲ۴�.
	isStart = TRUE;
	scoretitle->SetEnable(FALSE);
	//��ư�� ��ȣ�ۿ��� �Ұ����ϰ� �����.
	playBtn->SetInteracterble(FALSE);
	//��ŸƮ�� Ʈ���̸� Demo���� �ҷ��´�.
	if (isStart)	{ENGINE::SceneMgr->LoadScene("Demo");}
}
//����
VOID EndMenuScene::QuitBtnClickHandler()
{
	PostQuitMessage(0);
}

VOID EndMenuScene::EndWindow_Enable_True()
{
	EndWindow->SetEnable(TRUE);
}

