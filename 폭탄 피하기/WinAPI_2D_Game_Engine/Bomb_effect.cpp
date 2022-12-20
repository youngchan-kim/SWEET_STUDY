#include "Bomb_effect.h"
#include "ResourceManager.h"
#include "SceneManager.h"

Bomb_effect::Bomb_effect()
{
    //���� �̹����� �ε�
    ResourceMgr->Load("bomb_effects.bmp");

    //spriterender�� renderer�� �ҷ��� �̹����� ���� SpritesX, ���� Sprites�� �ɰ��� ���� �Ҵ�
    bombrenderer = new SpriteRenderer("bomb_effects.bmp", SpritesX, SpritesY);
    //renderer�� �׷����� �߽��� ���� �Ʒ� �𼭸��� �߽����� �׸���.
    bombrenderer->SetPivot(Pivot::Left | Pivot::Bottom);
    //renderer�� ũ��� (1.0f, 1.0f) �̴�.
    bombrenderer->SetScale(transform->scale.x, transform->scale.y);

    bombrenderer->GetDrawSize();
    //������Ʈ�� �߰��Ѵ�.
    AddComponent(bombrenderer);
    //�ִϸ��̼����� ���� 8 ���� 1 �� �׸��� ������ �����Ҵ��� �� ������Ʈ�� �߰��Ѵ�.
    //������� �÷��̾��� ������ ����� �ϴµ� �ѹ��� ���ǵ��� �����Ѵ�.
    AddComponent(bombanim = new SpriteAnimation(SpritesX, SpritesY));
}

//�̹����� ũ�⸦ ����
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
    //�ִϸ��̼��� �������϶�
    if(bombanim->IsPlay())
        //�׷��ش�.
        bombrenderer->Draw();
}
VOID Bomb_effect::GetPosition(Position position)
{
    transform->position.x = position.x;
    transform->position.y = position.y;

    Update(0, 0);
    bombanim->Play(0);

}