#include "Player.h"
#include "ResourceManager.h"
#include "SceneManager.h"

Player::Player()
{
    //플레이어 이미지를 로드
    ResourceMgr->Load("Player.bmp");

    //spriterender의 renderer에 불러온 이미지를 가로 SpritesX, 세로 Sprites로 쪼개서 동적 할당
    renderer = new SpriteRenderer("Player.bmp", SpritesX, SpritesY);
    //renderer이 그려지는 중심을 왼쪽 아래 모서리를 중심으로 그린다.
    renderer->SetPivot(Pivot::Left | Pivot::Bottom);
    //renderer의 크기는 (1.0f, 1.0f) 이다.
    renderer->SetScale(transform->scale.x, transform->scale.y);

    renderer->GetDrawSize();
    //컴포턴트를 추가한다.
    AddComponent(renderer);
    //애니메이션으로 가로 4 세로 2 의 그림을 나누어 동적할당한 후 컴포넌트에 추가한다.
    AddComponent(anim = new SpriteAnimation(SpritesX, SpritesY));
    AddComponent(input = new LRInput);
}

VOID Player::SetScale(const Vector2& scale)
{
    //크기는 scale 값을 적용한다.
    GameObject::SetScale(scale);
    //renderer의 값이 있다면     renderer의 크기 또한 scale의 값을 적용한다.
    if (renderer) renderer->SetScale(scale.x, scale.y);
}

VOID Player::Initialize()
{
    //변환 되는 정보중 포지션의 정보를 입력 받는다.
    transform->position = { 400, 600 };

}

VOID Player::Release()
{
}

VOID Player::Update(const FLOAT& deltaTime)
{
    //어떻게 사용됨? 무슨 일을 하는 것인지
    Operate(this);
    //방향의 값을 가져와서 분류해줌
    switch (input->GetDirection())
    {
    case LRInput::Direction::Left: anim->Play(1); transform->position.x -= Speed * deltaTime; break;
    case LRInput::Direction::Right: anim->Play(0); transform->position.x += Speed * deltaTime; break;
    default: anim->Stop(); break;
    }
    player_rect = { (LONG)transform->position.x,(LONG)(transform->position.y - renderer->GetDrawSize().cy)
       ,(LONG)(transform->position.x + renderer->GetDrawSize().cx) ,(LONG)transform->position.y };
}



VOID Player::Draw()
{
    renderer->Draw();
    Rectangle(SceneMgr->GetBackDC(), player_rect.left, player_rect.top,
        player_rect.right, player_rect.bottom);
}

//충돌 체크 함수
BOOL Player::Intersect_with_item(RECT item_rect)
{
    RECT tmp;
    return IntersectRect(&tmp, &player_rect, &item_rect);
}
