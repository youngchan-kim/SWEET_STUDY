#include "DemoScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"

VOID CALLBACK Score(int* score);
VOID CALLBACK Bomb(int* life);


VOID DemoScene::Initialize()
{
    //�̹����� �ε�
    ResourceMgr->Load("background.bmp");
    ResourceMgr->Load("pause_normal.bmp");
    ResourceMgr->Load("pause_pressed.bmp");
    ResourceMgr->Load("base_panel.bmp");
    ResourceMgr->Load("continue_normal.bmp");
    ResourceMgr->Load("continue_pressed.bmp");
    ResourceMgr->Load("quit_normal.bmp");
    ResourceMgr->Load("quit_pressed.bmp");
    ResourceMgr->Load("Life.bmp");
    //����(���� �ʺ�)
    bounds = SceneMgr->GetWidth();

    background = ResourceMgr->GetBitmap("background.bmp");

    background->SetDrawSize(bounds, SceneMgr->GetHeight());
    //�÷��̾�set
    player = new Player;
    player->Initialize();
    //�÷��̾��� ��ġ ����
    playerTr = player->GetTransform();
    //�÷��̾��� �׷��� ����
    playerSr = static_cast<SpriteRenderer*>(player->GetComponent(ComponentType::Graphic));
    
    //�Ͻ����� ��ưset
    pauseBtn = UIMgr->AddUI<UIButton>("Pause Btn");
    pauseBtn->Initialize("pause_normal.bmp", "pause_pressed.bmp", "", "", DrawType::Transparent);
    pauseBtn->SetPosition(bounds - pauseBtn->GetSize().cx - 22, 10);
    pauseBtn->SetListener(std::bind(&DemoScene::PauseBtnClickHandler, this));

    //�Ͻ����� ȭ���� ������
    pauseWindow = UIMgr->AddUI<UIImage>("PauseWindow Canvas");
    if (pauseWindow)
    {
        pauseWindow->Initialize("base_panel.bmp", DrawType::Transparent);
        pauseWindow->SetPosition(bounds * 0.5f, SceneMgr->GetHeight() * 0.5f, TRUE);

        UIButton* continueBtn = UIMgr->AddUI<UIButton>("Continue Btn", pauseWindow);
        continueBtn->Initialize("continue_normal.bmp", "continue_pressed.bmp", "", "", DrawType::Transparent);
        continueBtn->SetLocalPosition(pauseWindow->GetSize().cx * 0.5f, pauseWindow->GetSize().cy * 0.5f - 100, true);
        continueBtn->SetListener(std::bind(&DemoScene::ContinueBtnClickHandler, this));

        UIButton* quitBtn = UIMgr->AddUI<UIButton>("Quit Btn", pauseWindow);
        quitBtn->Initialize("quit_normal.bmp", "quit_pressed.bmp", "", "", DrawType::Transparent);
        quitBtn->SetLocalPosition(pauseWindow->GetSize().cx * 0.5f, pauseWindow->GetSize().cy * 0.5f + 50, true);
        quitBtn->SetListener(std::bind(&DemoScene::QuitBtnClickHandler, this));

        pauseWindow->SetEnable(FALSE);
    }

    bounds -= playerSr->GetDrawSize().cx;
    
    //life ��Ʈ�� �̹����� ������
    life_imageSr = ResourceMgr->GetBitmap("Life.bmp");
    //�̹����� ����� ������
    drawSize = life_imageSr->GetBitmapSize();
    //�̹����� �߶� �� x���� ����
    drawSize.cx = (float)(drawSize.cx / SpritesX);
    
    //�̹����� �ڸ���ŭ ����� �Է�
    life_imageSr->SetDrawSize(drawSize.cx, drawSize.cy);
    //�̹����� �׷��� ��ġ
    life_draw_pos = { (long)(background->GetSize().cx * 0.01f), (long)(background->GetSize().cy * 0.1f) };
    
    life = life_num;

    //�������� �����۵� set
    for (int i = 0; i < ITEMNUM; i++)
    {
        switch (i)
        {
        case 0:  name = "Apple";  break;
        case 1:  name = "Avocado"; break;
        case 2:  name = "Bacon"; break;
        case 3:  name = "Bread"; break;
        case 4:  name = "Cheese"; break;
        case 5:  name = "Cherry"; break;
        case 6:  name = "Chicken"; break;
        case 7:  name = "Bomb"; break;
        }
        switch (i)
        {
        default:
            //�Լ� ������ ���
            // void ���� int ������ ���� Test��� �̸��� ���� �Լ� �����͸� ����
            // dropitem[i] = new DropItem(std::bind(&DemoScene::AddScore, this, std::placeholders::_1));
            //std::bind(&DemoScene::AddScore, this, std::placeholders::_1
            //�� �Լ� ����Ʈ�� ����Ѵ�.

            //�Լ� �����͸� Test �����ѵ� test�� ȣ��
            //DropItem(Test f) { test = f; }
            //std::bind(&DemoScene::AddScore, this, std::placeholders::_1�� f�� �޴´�.
            //test�� f ���� �����Ѵ�.
            //test(10)�� test�� �Լ������� �̱� ������  DemoScene::AddScore�� ȣ��ǰ� �Ű����� ������ 10�� �ְ� �ȴ�.
            //�Լ��� ��ü�� ���
            dropitem[i] = new DropItem(std::bind(&DemoScene::AddScore, this, std::placeholders::_1), name, names);
            break;

        case 7:
            dropitem[i] = new DropItem(std::bind(&DemoScene::Dec_Life, this, std::placeholders::_1), name, names);
            //Life_Decrease();
            break;
        }

        dropitem[i]->Initialize();

        dropitemTr[i] = dropitem[i]->GetTransform();
        dropitemSr[i] = static_cast<SpriteRenderer*>(dropitem[i]->GetComponent(ComponentType::Graphic));

    }
    
    //����set
    bomb_effect = new Bomb_effect;
    bomb_effectTr = bomb_effect->GetTransform();
    bomb_effectSr = static_cast<SpriteRenderer*>(bomb_effect->GetComponent(ComponentType::Animation));
   
    //������
    //board_name = "���� : " + std::to_string(score);
    font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"�������");
    board = UIMgr->AddUI<UILabel>("score_board");
    board->Initialize("���� : " + std::to_string(score), RGB(220, 220, 220), font);
    board->SetPosition((bounds * 0.01f) - (board->GetSize().cx * 0.01f), SceneMgr->GetHeight() * 0.01f);
    board->SetEnable(true);

    isPause = FALSE;

    endmenuscene = new EndMenuScene;
    isDie = false;
}
//���� ����
void DemoScene::AddScore(int a)
{
    score += a * 10;
}
//��� ����
void DemoScene::Dec_Life(int a)
{
    life -= a;
}
VOID DemoScene::Release()
{
    REL_DEL(player);
    for(int i = 0; i < ITEMNUM; i++)   REL_DEL(dropitem[i]);
}

VOID DemoScene::Update(const FLOAT& deltaTime)
{
    if (isPause) return;

    switch (isDie)
    {
    case false:
        //��ź�� ��������
        if (isBomb)
        {
            //Ÿ�̸ӿ� ��ŸŸ���� ������
            timer += deltaTime;
            //Ÿ�̸Ӱ� 1�ʺ��� ũ�ų� ������
            if (1 <= timer)
            {
                //���๮�� ����
                for (int i = 0; i < 7; i++) dropitem[i]->Position_Reset();
                isBomb = false;
                if (life <= 0) isDie = true;
            }
            else
            {
                //1�ʺ��� ���� Ÿ�̸� �̸� �ش���๮�� ����
                bomb_effect->Update(deltaTime, isBomb);
            }
            return;
        }
        else
            timer = 0;

        player->Update(deltaTime);

        if (0 > playerTr->position.x) playerTr->position.x = 0;
        if (bounds < playerTr->position.x) playerTr->position.x = bounds;

        for (int i = 0; i < ITEMNUM; i++)
        {
            //�ð� ��ŭ update�Ѵ�.
            dropitem[i]->Update(deltaTime);

            //SceneMgr->GetHeight()�� ���� �ٴ�
            if (SceneMgr->GetHeight() < dropitemTr[i]->position.y)
            {
                dropitemTr[i]->position.y = SceneMgr->GetHeight();
                dropitem[i]->Position_Reset();
            }
            //�浹�� �˷���
            intersect = player->Intersect_with_item(dropitem[i]->GetRect());
            //�浹�� �浹�� ������Ʈ�� ����ġȭ
            if (intersect)
            {
                if (i == 7)
                {
                    isBomb = true;
                    bomb_effect->GetPosition(dropitem[ITEMNUM - 1]->Output_Position());
                }
                if (life > 0)
                {
                    dropitem[i]->CollisionCheck(dropitem[i]->GetRect());
                    intersect = false;
                }
                dropitem[i]->Position_Reset();
            }
        }
        board->SetText("���� : " + std::to_string(score));
        break;
    case true:
        for (int i = 0; i < ITEMNUM; i++)
        {
            dropitem[i]->Position_Reset();
        }
        endmenuscene->Score(score);
        endmenuscene->Update();
        board->SetEnable(false);
        pauseBtn->SetEnable(FALSE);
        endmenuscene->EndWindow_Enable_True();

        //���� ����
        //���� �޴���
        if (endmenuscene->restart())
        {
            ReSet();
        }
        break;
    }
}

VOID DemoScene::ReSet()
{
    pauseBtn->SetEnable(TRUE);
    board->SetEnable(true);
    life = life_num;
    score = 0;
    for (int i = 0; i < ITEMNUM; i++)
        dropitem[i]->Position_Reset();
}

VOID DemoScene::Draw()
{
    background->StretchBlt(0, 0);
    if (!isDie)
    {
        //�÷��̾� �׸���
        player->Draw();
        //������Ʈ �׸���
        for (int i = 0; i < 7; i++) dropitem[i]->Draw();

        //��ź�� ������ �ʾ����� ��ź�� �׷��ְ�
        if (!isBomb)dropitem[7]->Draw();
        //��ź�� �������� ������ �̹����� �����ش�.
        else
            bomb_effect->Draw();

        int src = 0;
        for (int i = 0; i < life_num; i++)
        {
            src = 0;
            if (i > (life - 1))
            {
                src = drawSize.cx;
            }
            life_imageSr->SliceSource(src, 0, drawSize.cx, drawSize.cy);
            life_imageSr->TransparentBlt(life_draw_pos.x + i * drawSize.cx, life_draw_pos.y);
        }
    }
    else
    {
        for (int i = 0; i < ITEMNUM; i++)
            dropitem[i]->Draw();
        return;
    }
    
}

VOID DemoScene::PauseBtnClickHandler()
{
    isPause = TRUE;
    pauseBtn->SetInteracterble(FALSE);
    pauseWindow->SetEnable(TRUE);
}

VOID DemoScene::ContinueBtnClickHandler()
{
    pauseWindow->SetEnable(FALSE);
    pauseBtn->SetInteracterble(TRUE);
    isPause = FALSE;
}

VOID DemoScene::QuitBtnClickHandler()
{
    ReSet();
    ENGINE::SceneMgr->LoadScene("MainMenu");
}
