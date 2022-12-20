#include "Player.h"
#include "ResourceManager.h"
#include "SceneManager.h"

Player::Player()
{
    //�÷��̾� �̹����� �ε�
    ResourceMgr->Load("Player.bmp");

    //spriterender�� renderer�� �ҷ��� �̹����� ���� SpritesX, ���� Sprites�� �ɰ��� ���� �Ҵ�
    renderer = new SpriteRenderer("Player.bmp", SpritesX, SpritesY);
    //renderer�� �׷����� �߽��� ���� �Ʒ� �𼭸��� �߽����� �׸���.
    renderer->SetPivot(Pivot::Left | Pivot::Bottom);
    //renderer�� ũ��� (1.0f, 1.0f) �̴�.
    renderer->SetScale(transform->scale.x, transform->scale.y);

    renderer->GetDrawSize();
    //������Ʈ�� �߰��Ѵ�.
    AddComponent(renderer);
    //�ִϸ��̼����� ���� 4 ���� 2 �� �׸��� ������ �����Ҵ��� �� ������Ʈ�� �߰��Ѵ�.
    AddComponent(anim = new SpriteAnimation(SpritesX, SpritesY));
    AddComponent(input = new LRInput);
}

VOID Player::SetScale(const Vector2& scale)
{
    //ũ��� scale ���� �����Ѵ�.
    GameObject::SetScale(scale);
    //renderer�� ���� �ִٸ�     renderer�� ũ�� ���� scale�� ���� �����Ѵ�.
    if (renderer) renderer->SetScale(scale.x, scale.y);
}

VOID Player::Initialize()
{
    //��ȯ �Ǵ� ������ �������� ������ �Է� �޴´�.
    transform->position = { 400, 600 };

}

VOID Player::Release()
{
}

VOID Player::Update(const FLOAT& deltaTime)
{
    //��� ����? ���� ���� �ϴ� ������
    Operate(this);
    //������ ���� �����ͼ� �з�����
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

//�浹 üũ �Լ�
BOOL Player::Intersect_with_item(RECT item_rect)
{
    RECT tmp;
    return IntersectRect(&tmp, &player_rect, &item_rect);
}
