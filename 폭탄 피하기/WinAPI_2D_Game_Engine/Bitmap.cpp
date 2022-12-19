#include "Bitmap.h"
#include "SceneManager.h"

namespace ENGINE
{
	Bitmap::~Bitmap()
	{
		//사용이 끝난 memDC는 제거
		DeleteDC(memDC);
		//사용이 끝난 hBitmap는 제거
		DeleteObject(hBitmap);
	}

	VOID Bitmap::Load(std::string name)
	{
		//DC란 비트맵이미지를 로드하여 보여지는 공간을 의미
		//hBackDC는 DC에만 그리게되면 초기화와 그려기는게 반복 됨으로 연속적으로
		//보여주기 어렵기 때문에 만든 보이지 않는 DC를 hBackDC로 이름 붙임
		//hBackDC 와 호환 되는 DC를 만들어 리턴하여 memDC에 대입연산한다.
		memDC = CreateCompatibleDC(SceneMgr->GetBackDC()); //메모리 DC 생성.
		//비트맵 이미지 로드
		//로드한 이미지를 비트맵 리턴하여 hBitmap에 대입연산한다.
		hBitmap = (HBITMAP)LoadImageA(NULL, name.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE); // 비트맵 이미지 로드.
		
		SelectObject(memDC, hBitmap); //메모리 DC에 비트맵 이미지 적용.

		BITMAP BitMap;
		GetObject(hBitmap, sizeof(BITMAP), &BitMap); //비트맵의 정보 얻기,
		origin.cx = BitMap.bmWidth; //비트맵의 원본 크기 저장.
		origin.cy = BitMap.bmHeight; //비트맵의 원본 크기 저장.
		dest = origin; src = { 0,0,origin.cx ,origin.cy }; //화면에 그려줄 크기와 rec를 원본 크기로 지정.

		//x축 : 0 , y축 : 0
		pivot = { 0,0 };
		//pivotType은 Left 이거나 Top 이다.
		// pivot의 0,0은 왼쪽을 0으로 위를 0으로 한다. 좌, 상을 pivot의 중심으로 함
		pivotType = (Pivot::Left | Pivot::Top);
	}

	//그리는 사이즈를 설정한다
	VOID Bitmap::SetDrawSize(UINT width, UINT height)
	{
		// 원래 위치에서 그려지는 위치를 대입연산
		dest = { (LONG)width, (LONG)height };
		// 원래 위치에서 그려지는 그림의 위치의 pivot을 재설정하기 위함
		SetPivot(pivotType);
	}

	//pivot을 재설정
	VOID Bitmap::SetPivot(INT pivot)
	{
		//0,0의 위치를 리턴 받음
		pivotType = pivot;

		//새로 그려지는 너비의 중앙
		int halfWidth = dest.cx * 0.5f;
		//새로 그려지는 높이의 중앙
		int halfHeight = dest.cy * 0.5f;

		//pivot의 0,0을  -halfWidth, -halfHeight 으로 대입
		//오른쪽 이나 아래로 가려면 -값을 더해야한다.(생각해보거나 그려보면 알수 있음)
		this->pivot = { -halfWidth, -halfHeight };

		//pivot이 Left 면 this->pivot.x에 halfWidth만큼 더한다.
		if (pivot & Pivot::Left) this->pivot.x += halfWidth;
		//pivot이 Right 면 this->pivot.x에 halfWidth만큼 뺀다.
		if (pivot & Pivot::Right) this->pivot.x += -halfWidth;
		//pivot이 Top 면 this->pivot.y에 halfHeight만큼 뺀다.
		if (pivot & Pivot::Top) this->pivot.y += halfHeight;
		//pivot이 Bottom 면 this->pivot.y에 halfHeight만큼 뺀다.
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