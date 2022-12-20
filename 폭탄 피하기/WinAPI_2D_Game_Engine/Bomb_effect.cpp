#include "Bomb_effect.h"
#include "ResourceManager.h"
#include "SceneManager.h"

Bomb_effect::Bomb_effect()
{
    //폭발 이미지를 로드
    ResourceMgr->Load("bomb_effects.bmp");

    //spriterender의 renderer에 불러온 이미지를 가로 SpritesX, 세로 Sprites로 쪼개서 동적 할당
    bombrenderer = new SpriteRenderer("bomb_effects.bmp", SpritesX, SpritesY);
    //renderer이 그려지는 중심을 왼쪽 아래 모서리를 중심으로 그린다.
    bombrenderer->SetPivot(Pivot::Left | Pivot::Bottom);
    //renderer의 크기는 (1.0f, 1.0f) 이다.
    bombrenderer->SetScale(transform->scale.x, transform->scale.y);

    bombrenderer->GetDrawSize();
    //컴포턴트를 추가한다.
    AddComponent(bombrenderer);
    //애니메이션으로 가로 8 세로 1 의 그림을 나누어 동적할당한 후 컴포넌트에 추가한다.
    //만들어진 플레이어의 루프를 사용은 하는데 한번만 사용되도록 수정한다.
    AddComponent(bombanim = new SpriteAnimation(SpritesX, SpritesY));
}

//이미지의 크기를 정함
VOID Bomb_effect::SetScale(const Vector2& scale)
{
    GameObject::SetScale(scale);
    if (bombrenderer) bombrenderer->SetScale(scale.x, scale.y);
}


VOID Bomb_effect::Update(const FLOAT& deltaTime, bool isbomb)
{
    //
    Operate(this);
    item_rect = { (LONG)transform->position.x,(LONG)(transform->position.y - bombrenderer->GetDrawSize().cy)
      ,(LONG)(transform->position.x + bombrenderer->GetDrawSize().cx) ,(LONG)transform->position.y };
}


VOID Bomb_effect::Draw()
{
    //애니메이션이 실행중일때
    if(bombanim->IsPlay())
        //그려준다.
        bombrenderer->Draw();
}
VOID Bomb_effect::GetPosition(Position position)
{
    transform->position.x = position.x;
    transform->position.y = position.y;

    Update(0, 0);
    bombanim->Play(0);

}