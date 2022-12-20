#include "UIImage.h"
#include "ResourceManager.h"
namespace ENGINE
{
    //사각형 설정
    VOID ENGINE::UIImage::SetRect(BOOL pivotCenter)
    {
        //그려지는 기준점을 pos에 대입연산
        POINT pos = position;
        //크기는 이미지의 bitmap의 크기
        size = image->GetBitmapSize();
        // 기준점이 사각형의 중앙에 있다면
        if (pivotCenter)
        {
            pos.x -= size.cx * 0.5f;
            pos.y -= size.cy * 0.5f;
        }
        // 사각형을 그림
        rect = { pos.x, pos.y, pos.x + size.cx, pos.y + size.cy };
    }

    //초기화
    VOID ENGINE::UIImage::Initialize(const std::string& ImageName, DrawType type)
    {
        //이미지 변수에 리소스의 ImageName의 이름의 비트맵을 대입연산
        image = ResourceMgr->GetBitmap(ImageName);
        //그리는 타입을 맴버변수에 대입
        this->type = type;
        //사각형을 설정
        SetRect(pivotCenter);
    }

    VOID ENGINE::UIImage::Draw()
    {
        //사용불가능
        if (!isEnable) return;
        //사용가능
        // 이미지가 있다면
        if (image)
        {
            //Transparent type 인지 아닌지
            switch (type)
            {
                //이미지의 특정색을 투명하게 적용시켜 화면에 출력
            case DrawType::Transparent: image->TransparentBlt(rect.left, rect.top); break;
                //이미지 그대로 출력
            default: image->BitBlt(rect.left, rect.top); break;
            }
        }
        UIPanel::Draw();
    }
}//namespace ENGINE
