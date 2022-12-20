#include "Dropitem.h"
#include "ResourceManager.h"
#include "SceneManager.h"

// 생성자의 호출 시 name의 값은 없으면 안되고 names의 값은 없어도 됨 디폴트 매개변수로 만들어둠
DropItem::DropItem(Item_effect f, std::string name, std::string names)
{
    item_effect = f;
    // name에 맞는 이미지가 로드 
    std::string fullname = name + ".bmp";
    ResourceMgr->Load(fullname.c_str());
    //if (names != "")ResourceMgr->Load(names + ".bmp");

    //itemrenderer에 해당 이미지를 할당
    itemrenderer = new SpriteRenderer(fullname.c_str(), X, Y);
    //이미지가 어디를 기준으로 그려지는지 정해져야함
    itemrenderer->SetPivot(Pivot::Left | Pivot::Bottom);
    // 그림의 크기를 정해야함
    itemrenderer->SetScale(transform->scale.x, transform->scale.y);
    // 컴포넌트에 그림의 정보를 가지고 있는 itemrenderer을 적용 추가
    AddComponent(itemrenderer);
    // 그림 또한 anim에 해당 이미지가 사용할 그림을 컴포넌트로 적용 추가함
    AddComponent(anim = new SpriteAnimation(X, Y));
}

//이미지의 크기를 정함
VOID DropItem::SetScale(const Vector2& scale)
{
    GameObject::SetScale(scale);
    if (itemrenderer) itemrenderer->SetScale(scale.x, scale.y);
}

//좌표
VOID DropItem::Rand_Pos()
{
    //x축 값
    start_x = rand() % (SceneMgr->GetWidth() - itemrenderer->GetDrawSize().cx);
    //y축의 랜덤 위치
    rand_y = start_y - ((rand() % 10) * 40);
}

VOID DropItem::Position_Reset()
{
    // x축을 난수로
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
    //사용된 패턴 컴포넌트 패턴
    //드롭아이템 클래스가 소유한 모든 오퍼레이터 함수를 실행시킨다.
    Operate(this);
    //떨어지는 속도
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

//아이템의 위치와 사용여부
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