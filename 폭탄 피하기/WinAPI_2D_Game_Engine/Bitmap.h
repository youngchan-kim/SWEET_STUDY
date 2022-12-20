#pragma once
#include "EngineMecro.h"

#ifndef BITMAP_H
#define BITMAP_H

namespace ENGINE
{
	enum Pivot
	{
		Center	= 1 << 0,	// 0000 0001 => 0000 0001
		Left	= 1 << 1,	// 0000 0001 => 0000 0010
		Right	= 1 << 2,	// 0000 0001 => 0000 0100
		Top		= 1 << 3,	// 0000 0001 => 0000 1000
		Bottom	= 1 << 4,	// 0000 0001 => 0001 0000
	};

	class Bitmap
	{
	private:
		HDC memDC;
		HBITMAP hBitmap;
		SIZE origin, dest;
		RECT src;
		POINT pivot;
		INT pivotType;
	public:
		~Bitmap();
		VOID Load(std::string name); // ��Ʈ�� �̹����� �ε��ϰ� �޸� DC�� �����.
		VOID SetDrawSize(UINT width = 0U, UINT height = 0U); // ���� ȭ�鿡 ��µ� ũ�⸦ ����.
		VOID ResetSize() { dest = origin; } // ȭ�鿡 ��µǴ� ũ�⸦ ���� ũ��� ����.
		// Sprites �̹����� ������ ��ġ���� ������ ũ�⸸ŭ ���.
		VOID SliceSource(UINT cx, UINT cy, UINT width, UINT height)
		{
			src = { (LONG)cx, (LONG)cy, (LONG)width, (LONG)height };
		}
		VOID SetPivot(INT pivot);
		VOID ResetPivot() { pivot = { 0, 0 }; }
		BOOL BitBlt(INT32 x, INT32 y); // ���� �״�� ȭ�鿡 ���.
		BOOL StretchBlt(INT32 x, INT32 y); // ������ ��� ������� �����Ͽ� ���.
		// ������ ��� ������� �����ϰ� ���� ���� ���� ó���Ͽ� ���.
		BOOL TransparentBlt(INT32 x, INT32 y, UINT transparent = RGB(255, 0, 255));
		SIZE GetBitmapSize() CONST { return origin; } // ���� ��Ʈ���� ũ��.
		SIZE GetSize() CONST { return dest; } // ȭ�鿡 ��µǴ� �̹����� ũ��.
	}; // class Bitmap
}
#endif // !BITMAP_H



