#include "SpriteRenderer.h"
#include "../ResourceManager.h"

namespace ENGINE
{
    //이미지를 분할해서 그려주는 함수
    SpriteRenderer::SpriteRenderer(LPCSTR name, UINT divX, UINT divY) : divide({ 1.0f / divX, 1.0f / divY })
    {
        // 분할 할 변수에 해당 비트맵을 대입
        sprites = ResourceMgr->GetBitmap(name);

        // 비트맵의 사이즈를 localsize에 대입
        localSize = sprites->GetBitmapSize();

        //localsize의 cx 에 divide.x을 곱한뒤 값을 대입
        localSize.cx *= divide.x;
        //localsize의 cy 에 divide.y을 곱한뒤 값을 대입
        localSize.cy *= divide.y;
        //localSize의 값을 size에 대입
        size = localSize;
        SetSrc(0, 0);
    }
    //일부분의 영역을 설정한다.
    VOID SpriteRenderer::SetSrc(UINT cx, UINT cy)
    {
        //분할 할 비트맵의 일부분을 0,0 ,localSize.cx ,localSize.cy 로 나눈다.
        sprites->SliceSource(cx * localSize.cx, cy * localSize.cy, localSize.cx, localSize.cy);
    }

    VOID SpriteRenderer::Operate(GameObject* Owner) 
    {
        //분할 변수가 있으면 함수를 실행한 renderer의 위치를 대입
        if (sprites) pos = Owner->GetTransform()->position;
    }

    VOID SpriteRenderer::Reset()
    {
        if (sprites)
        {
            sprites->ResetSize();
            sprites->ResetPivot();
        }
    }

    VOID SpriteRenderer::SetScale(UINT cx, UINT cy)
    {
        //
        size = { (LONG)(localSize.cx * cx), (LONG)(localSize.cy * cy) };
        sprites->SetDrawSize(size.cx, size.cy);
    }

    VOID SpriteRenderer::Draw()
    {
        if (sprites) sprites->TransparentBlt(pos.x, pos.y);
    }
}