#include "SpriteRenderer.h"
#include "../ResourceManager.h"

namespace ENGINE
{
    //�̹����� �����ؼ� �׷��ִ� �Լ�
    SpriteRenderer::SpriteRenderer(LPCSTR name, UINT divX, UINT divY) : divide({ 1.0f / divX, 1.0f / divY })
    {
        // ���� �� ������ �ش� ��Ʈ���� ����
        sprites = ResourceMgr->GetBitmap(name);

        // ��Ʈ���� ����� localsize�� ����
        localSize = sprites->GetBitmapSize();

        //localsize�� cx �� divide.x�� ���ѵ� ���� ����
        localSize.cx *= divide.x;
        //localsize�� cy �� divide.y�� ���ѵ� ���� ����
        localSize.cy *= divide.y;
        //localSize�� ���� size�� ����
        size = localSize;
        SetSrc(0, 0);
    }
    //�Ϻκ��� ������ �����Ѵ�.
    VOID SpriteRenderer::SetSrc(UINT cx, UINT cy)
    {
        //���� �� ��Ʈ���� �Ϻκ��� 0,0 ,localSize.cx ,localSize.cy �� ������.
        sprites->SliceSource(cx * localSize.cx, cy * localSize.cy, localSize.cx, localSize.cy);
    }

    VOID SpriteRenderer::Operate(GameObject* Owner) 
    {
        //���� ������ ������ �Լ��� ������ renderer�� ��ġ�� ����
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