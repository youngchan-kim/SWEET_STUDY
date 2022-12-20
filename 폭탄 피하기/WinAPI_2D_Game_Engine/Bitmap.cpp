#include "Bitmap.h"
#include "SceneManager.h"

namespace ENGINE
{
	Bitmap::~Bitmap()
	{
		//����� ���� memDC�� ����
		DeleteDC(memDC);
		//����� ���� hBitmap�� ����
		DeleteObject(hBitmap);
	}

	VOID Bitmap::Load(std::string name)
	{
		//DC�� ��Ʈ���̹����� �ε��Ͽ� �������� ������ �ǹ�
		//hBackDC�� DC���� �׸��ԵǸ� �ʱ�ȭ�� �׷���°� �ݺ� ������ ����������
		//�����ֱ� ��Ʊ� ������ ���� ������ �ʴ� DC�� hBackDC�� �̸� ����
		//hBackDC �� ȣȯ �Ǵ� DC�� ����� �����Ͽ� memDC�� ���Կ����Ѵ�.
		memDC = CreateCompatibleDC(SceneMgr->GetBackDC()); //�޸� DC ����.
		//��Ʈ�� �̹��� �ε�
		//�ε��� �̹����� ��Ʈ�� �����Ͽ� hBitmap�� ���Կ����Ѵ�.
		hBitmap = (HBITMAP)LoadImageA(NULL, name.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE); // ��Ʈ�� �̹��� �ε�.
		
		SelectObject(memDC, hBitmap); //�޸� DC�� ��Ʈ�� �̹��� ����.

		BITMAP BitMap;
		GetObject(hBitmap, sizeof(BITMAP), &BitMap); //��Ʈ���� ���� ���,
		origin.cx = BitMap.bmWidth; //��Ʈ���� ���� ũ�� ����.
		origin.cy = BitMap.bmHeight; //��Ʈ���� ���� ũ�� ����.
		dest = origin; src = { 0,0,origin.cx ,origin.cy }; //ȭ�鿡 �׷��� ũ��� rec�� ���� ũ��� ����.

		//x�� : 0 , y�� : 0
		pivot = { 0,0 };
		//pivotType�� Left �̰ų� Top �̴�.
		// pivot�� 0,0�� ������ 0���� ���� 0���� �Ѵ�. ��, ���� pivot�� �߽����� ��
		pivotType = (Pivot::Left | Pivot::Top);
	}

	//�׸��� ����� �����Ѵ�
	VOID Bitmap::SetDrawSize(UINT width, UINT height)
	{
		// ���� ��ġ���� �׷����� ��ġ�� ���Կ���
		dest = { (LONG)width, (LONG)height };
		// ���� ��ġ���� �׷����� �׸��� ��ġ�� pivot�� �缳���ϱ� ����
		SetPivot(pivotType);
	}

	//pivot�� �缳��
	VOID Bitmap::SetPivot(INT pivot)
	{
		//0,0�� ��ġ�� ���� ����
		pivotType = pivot;

		//���� �׷����� �ʺ��� �߾�
		int halfWidth = dest.cx * 0.5f;
		//���� �׷����� ������ �߾�
		int halfHeight = dest.cy * 0.5f;

		//pivot�� 0,0��  -halfWidth, -halfHeight ���� ����
		//������ �̳� �Ʒ��� ������ -���� ���ؾ��Ѵ�.(�����غ��ų� �׷����� �˼� ����)
		this->pivot = { -halfWidth, -halfHeight };

		//pivot�� Left �� this->pivot.x�� halfWidth��ŭ ���Ѵ�.
		if (pivot & Pivot::Left) this->pivot.x += halfWidth;
		//pivot�� Right �� this->pivot.x�� halfWidth��ŭ ����.
		if (pivot & Pivot::Right) this->pivot.x += -halfWidth;
		//pivot�� Top �� this->pivot.y�� halfHeight��ŭ ����.
		if (pivot & Pivot::Top) this->pivot.y += halfHeight;
		//pivot�� Bottom �� this->pivot.y�� halfHeight��ŭ ����.
		if (pivot & Pivot::Bottom) this->pivot.y += -halfHeight;
	}

	BOOL Bitmap::BitBlt(INT32 x, INT32 y)
	{
		return ::BitBlt(SceneMgr->GetBackDC(), pivot.x + x, pivot.y + y, src.right, src.bottom, memDC, src.left, src.top, SRCCOPY);
	}

	BOOL Bitmap::StretchBlt(INT32 x, INT32 y)
	{
		return ::StretchBlt(SceneMgr->GetBackDC(), pivot.x + x, pivot.y + y, dest.cx, dest.cy, memDC, src.left, src.top, src.right, src.bottom, SRCCOPY);
	}

	BOOL Bitmap::TransparentBlt(INT32 x, INT32 y, UINT transparent)
	{
		return ::TransparentBlt(SceneMgr->GetBackDC(), pivot.x + x, pivot.y + y, dest.cx, dest.cy, memDC, src.left, src.top, src.right, src.bottom, transparent);
	}
}//namespace ENGINE