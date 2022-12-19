#include "UIImage.h"
#include "ResourceManager.h"
namespace ENGINE
{
    //�簢�� ����
    VOID ENGINE::UIImage::SetRect(BOOL pivotCenter)
    {
        //�׷����� �������� pos�� ���Կ���
        POINT pos = position;
        //ũ��� �̹����� bitmap�� ũ��
        size = image->GetBitmapSize();
        // �������� �簢���� �߾ӿ� �ִٸ�
        if (pivotCenter)
        {
            pos.x -= size.cx * 0.5f;
            pos.y -= size.cy * 0.5f;
        }
        // �簢���� �׸�
        rect = { pos.x, pos.y, pos.x + size.cx, pos.y + size.cy };
    }

    //�ʱ�ȭ
    VOID ENGINE::UIImage::Initialize(const std::string& ImageName, DrawType type)
    {
        //�̹��� ������ ���ҽ��� ImageName�� �̸��� ��Ʈ���� ���Կ���
        image = ResourceMgr->GetBitmap(ImageName);
        //�׸��� Ÿ���� �ɹ������� ����
        this->type = type;
        //�簢���� ����
        SetRect(pivotCenter);
    }

    VOID ENGINE::UIImage::Draw()
    {
        //���Ұ���
        if (!isEnable) return;
        //��밡��
        // �̹����� �ִٸ�
        if (image)
        {
            //Transparent type ���� �ƴ���
            switch (type)
            {
                //�̹����� Ư������ �����ϰ� ������� ȭ�鿡 ���
            case DrawType::Transparent: image->TransparentBlt(rect.left, rect.top); break;
                //�̹��� �״�� ���
            default: image->BitBlt(rect.left, rect.top); break;
            }
        }
        UIPanel::Draw();
    }
}//namespace ENGINE
