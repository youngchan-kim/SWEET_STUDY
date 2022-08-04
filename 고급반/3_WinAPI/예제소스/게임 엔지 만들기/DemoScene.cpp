#include "DemoScene.h"
#include "ResourceManager.h"
#include "SceneManager.h"

Player::Player()
{
    ResourceMgr->Load("Player.bmp");

    renderer = new SpriteRenderer("Player.bmp", SpritesX, SpritesY);
    renderer->SetPivot(Pivot::Left | Pivot::Bottom);
    renderer->SetScale(transform->scale.x, transform->scale.y);
    AddComponent(renderer);
    AddComponent(anim = new SpriteAnimation(SpritesX, SpritesY));
    AddComponent(input = new LRInput);
}

VOID Player::SetScale(const Vector2& scale)
{
    GameObject::SetScale(scale);
    if (renderer) renderer->SetScale(scale.x, scale.y);
}

VOID Player::Initialize()
{
    transform->position = { 400, 600 };
}

VOID Player::Release()
{
}

VOID Player::Update(const FLOAT& deltaTime)
{
    Operate(this);

    switch (input->GetDirection())
    {
    case LRInput::Direction::Left: anim->Play(1); transform->position.x -= Speed * deltaTime; break;
    case LRInput::Direction::Right: anim->Play(0); transform->position.x += Speed * deltaTime; break;
    default: anim->Stop(); break;
    }
}

VOID Player::Draw()
{
    renderer->Draw();
}

VOID DemoScene::Initialize()
{
    ResourceMgr->Load("background.bmp");
    ResourceMgr->Load("pause_normal.bmp");
    ResourceMgr->Load("pause_pressed.bmp");
    ResourceMgr->Load("base_panel.bmp");
    ResourceMgr->Load("continue_normal.bmp");
    ResourceMgr->Load("continue_pressed.bmp");
    ResourceMgr->Load("quit_normal.bmp");
    ResourceMgr->Load("quit_pressed.bmp");

    bounds = SceneMgr->GetWidth();

    background = ResourceMgr->GetBitmap("background.bmp");
    background->SetDrawSize(bounds, SceneMgr->GetHeight());

    player = new Player;
    player->Initialize();
    playerTr = player->GetTransform();
    playerSr = static_cast<SpriteRenderer*>(player->GetComponent(ComponentType::Graphic));

    pauseBtn = UIMgr->AddUI<UIButton>("Pause Btn");
    pauseBtn->Initialize("pause_normal.bmp", "pause_pressed.bmp", "", "", DrawType::Transparent);
    pauseBtn->SetPosition(bounds - pauseBtn->GetSize().cx - 22, 10);
    pauseBtn->SetListener(std::bind(&DemoScene::PauseBtnClickHandler, this));    

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

    isPause = FALSE;
}

VOID DemoScene::Release()
{
    REL_DEL(player);
}

VOID DemoScene::Update(const FLOAT& deltaTime)
{
    if (isPause) return;

    player->Update(deltaTime);
    if (0 > playerTr->position.x) playerTr->position.x = 0;
    if (bounds < playerTr->position.x) playerTr->position.x = bounds;
}

VOID DemoScene::Draw()
{
    background->StretchBlt(0, 0);
    player->Draw();
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
    PostQuitMessage(0);
}
