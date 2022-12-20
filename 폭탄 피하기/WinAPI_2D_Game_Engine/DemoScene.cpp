#include "DemoScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"

VOID CALLBACK Score(int* score);
VOID CALLBACK Bomb(int* life);


VOID DemoScene::Initialize()
{
    //이미지를 로드
    ResourceMgr->Load("background.bmp");
    ResourceMgr->Load("pause_normal.bmp");
    ResourceMgr->Load("pause_pressed.bmp");
    ResourceMgr->Load("base_panel.bmp");
    ResourceMgr->Load("continue_normal.bmp");
    ResourceMgr->Load("continue_pressed.bmp");
    ResourceMgr->Load("quit_normal.bmp");
    ResourceMgr->Load("quit_pressed.bmp");
    ResourceMgr->Load("Life.bmp");
    //범위(가로 너비)
    bounds = SceneMgr->GetWidth();

    background = ResourceMgr->GetBitmap("background.bmp");

    background->SetDrawSize(bounds, SceneMgr->GetHeight());
    //플레이어set
    player = new Player;
    player->Initialize();
    //플레이어의 위치 정보
    playerTr = player->GetTransform();
    //플레이어의 그래픽 설정
    playerSr = static_cast<SpriteRenderer*>(player->GetComponent(ComponentType::Graphic));
    
    //일시정지 버튼set
    pauseBtn = UIMgr->AddUI<UIButton>("Pause Btn");
    pauseBtn->Initialize("pause_normal.bmp", "pause_pressed.bmp", "", "", DrawType::Transparent);
    pauseBtn->SetPosition(bounds - pauseBtn->GetSize().cx - 22, 10);
    pauseBtn->SetListener(std::bind(&DemoScene::PauseBtnClickHandler, this));

    //일시정지 화면이 나오면
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
    
    //life 비트맵 이미지를 가져옴
    life_imageSr = ResourceMgr->GetBitmap("Life.bmp");
    //이미지의 사이즈를 가져옴
    drawSize = life_imageSr->GetBitmapSize();
    //이미지를 잘라 쓸 x값을 구함
    drawSize.cx = (float)(drawSize.cx / SpritesX);
    
    //이미지를 자를만큼 사이즈를 입력
    life_imageSr->SetDrawSize(drawSize.cx, drawSize.cy);
    //이미지가 그려질 위치
    life_draw_pos = { (long)(background->GetSize().cx * 0.01f), (long)(background->GetSize().cy * 0.1f) };
    
    life = life_num;

    //떨어지는 아이템들 set
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
            //함수 포인터 사용
            // void 형에 int 변수를 가진 Test라는 이름을 가진 함수 포인터를 만듦
            // dropitem[i] = new DropItem(std::bind(&DemoScene::AddScore, this, std::placeholders::_1));
            //std::bind(&DemoScene::AddScore, this, std::placeholders::_1
            //는 함수 포인트를 사용한다.

            //함수 포인터를 Test 선언한뒤 test로 호출
            //DropItem(Test f) { test = f; }
            //std::bind(&DemoScene::AddScore, this, std::placeholders::_1를 f로 받는다.
            //test에 f 값을 대입한다.
            //test(10)의 test는 함수포인터 이기 때문에  DemoScene::AddScore가 호출되고 매개변수 값으로 10을 넣게 된다.
            //함수를 객체로 사용
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
    
    //폭팔set
    bomb_effect = new Bomb_effect;
    bomb_effectTr = bomb_effect->GetTransform();
    bomb_effectSr = static_cast<SpriteRenderer*>(bomb_effect->GetComponent(ComponentType::Animation));
   
    //점수판
    //board_name = "점수 : " + std::to_string(score);
    font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, L"굵은고딕");
    board = UIMgr->AddUI<UILabel>("score_board");
    board->Initialize("점수 : " + std::to_string(score), RGB(220, 220, 220), font);
    board->SetPosition((bounds * 0.01f) - (board->GetSize().cx * 0.01f), SceneMgr->GetHeight() * 0.01f);
    board->SetEnable(true);

    isPause = FALSE;

    endmenuscene = new EndMenuScene;
    isDie = false;
}
//점수 증가
void DemoScene::AddScore(int a)
{
    score += a * 10;
}
//목숨 감소
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
        //폭탄이 터졌을때
        if (isBomb)
        {
            //타이머에 델타타임을 더한후
            timer += deltaTime;
            //타이머가 1초보다 크거나 같으면
            if (1 <= timer)
            {
                //실행문을 실행
                for (int i = 0; i < 7; i++) dropitem[i]->Position_Reset();
                isBomb = false;
                if (life <= 0) isDie = true;
            }
            else
            {
                //1초보다 작은 타이머 이면 해당실행문을 실행
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
            //시간 만큼 update한다.
            dropitem[i]->Update(deltaTime);

            //SceneMgr->GetHeight()의 값이 바닥
            if (SceneMgr->GetHeight() < dropitemTr[i]->position.y)
            {
                dropitemTr[i]->position.y = SceneMgr->GetHeight();
                dropitem[i]->Position_Reset();
            }
            //충돌을 알려줌
            intersect = player->Intersect_with_item(dropitem[i]->GetRect());
            //충돌시 충돌한 오브젝트를 원위치화
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
        board->SetText("점수 : " + std::to_string(score));
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

        //전부 리셋
        //메인 메뉴로
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
        //플레이어 그리기
        player->Draw();
        //오브젝트 그리기
        for (int i = 0; i < 7; i++) dropitem[i]->Draw();

        //폭탄이 터지지 않았을때 폭탄을 그려주고
        if (!isBomb)dropitem[7]->Draw();
        //폭탄이 터졌을때 폭발의 이미지를 보여준다.
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
