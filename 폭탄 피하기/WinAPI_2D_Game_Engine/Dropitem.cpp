#include "Dropitem.h"
#include "ResourceManager.h"
#include "SceneManager.h"

// �������� ȣ�� �� name�� ���� ������ �ȵǰ� names�� ���� ��� �� ����Ʈ �Ű������� ������
DropItem::DropItem(Item_effect f, std::string name, std::string names)
{
    item_effect = f;
    // name�� �´� �̹����� �ε� 
    std::string fullname = name + ".bmp";
    ResourceMgr->Load(fullname.c_str());
    //if (names != "")ResourceMgr->Load(names + ".bmp");

    //itemrenderer�� �ش� �̹����� �Ҵ�
    itemrenderer = new SpriteRenderer(fullname.c_str(), X, Y);
    //�̹����� ��� �������� �׷������� ����������
    itemrenderer->SetPivot(Pivot::Left | Pivot::Bottom);
    // �׸��� ũ�⸦ ���ؾ���
    itemrenderer->SetScale(transform->scale.x, transform->scale.y);
    // ������Ʈ�� �׸��� ������ ������ �ִ� itemrenderer�� ���� �߰�
    AddComponent(itemrenderer);
    // �׸� ���� anim�� �ش� �̹����� ����� �׸��� ������Ʈ�� ���� �߰���
    AddComponent(anim = new SpriteAnimation(X, Y));
}

//�̹����� ũ�⸦ ����
VOID DropItem::SetScale(const Vector2& scale)
{
    GameObject::SetScale(scale);
    if (itemrenderer) itemrenderer->SetScale(scale.x, scale.y);
}

//��ǥ
VOID DropItem::Rand_Pos()
{
    //x�� ��
    start_x = rand() % (SceneMgr->GetWidth() - itemrenderer->GetDrawSize().cx);
    //y���� ���� ��ġ
    rand_y = start_y - ((rand() % 10) * 40);
}

VOID DropItem::Position_Reset()
{
    // x���� ������
    Rand_Pos();
    transform->position = { start_x, rand_y };

    Update(0);
}

VOID DropItem::Initialize()
{
    Position_Reset();
    isItem = true;
}

VOID DropItem::Release()
{
}

VOID DropItem::Update(const FLOAT& deltaTime)
{
    //���� ���� ������Ʈ ����
    //��Ӿ����� Ŭ������ ������ ��� ���۷����� �Լ��� �����Ų��.
    Operate(this);
    //�������� �ӵ�
    transform->position.y += speed * deltaTime;
    item_rect = { (LONG)transform->position.x,(LONG)(transform->position.y - itemrenderer->GetDrawSize().cy)
      ,(LONG)(transform->position.x + itemrenderer->GetDrawSize().cx) ,(LONG)transform->position.y };
}


VOID DropItem::Draw()
{
    this->itemrenderer->Draw();
    //Rectangle(SceneMgr->GetBackDC(), item_rect.left, item_rect.top,
    //    item_rect.right, item_rect.bottom);
}

//�������� ��ġ�� ��뿩��
VOID DropItem::Reset(bool isItem)
{
    if (!isItem)
    {
        Position_Reset();
        isItem = true;
    }
}
Position DropItem::Output_Position()
{
    position.x = transform->position.x;
    position.y = transform->position.y;
    return position;
}