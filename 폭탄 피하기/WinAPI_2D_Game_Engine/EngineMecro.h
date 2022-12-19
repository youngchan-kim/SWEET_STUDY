//Engine���� ����� Mecro ����
///
/// �������� ���������� ���� ��ũ�� �Լ� �� �������̽� ����
/// FPS �� Window ũ�⸦ ������ �д�.
///

#pragma comment(lib, "msimg32.lib")
#include <crtdbg.h>
#include<windows.h>
#include<time.h>
#include<string>
#include<vector>
#include <map>
#include<functional>
#include<algorithm>
#include"Component.h"
#include <stdlib.h>

// �ĺ��� ENGINE_MECRO_H �� ���ٸ�  ENGINE_MECRO_H�� #endif �� ������ ���� ��� ���� ����� �ش�.
#ifndef ENGINE_MECRO_H
#define ENGINE_MECRO_H

#ifndef DEL 
#define DEL(a) if(a) {delete a; a = nullptr;}//delete ��ũ�� �Լ�
#endif // !DEL

#ifndef REL_DEL
#define REL_DEL(a) if(a) { a->Release(); delete a; a = nullptr; } // Release() �Լ� ȣ�� �� delete
#endif // !REL_DEL

//void ���� ��üȭ �Ѵ�.
// ��üȭ�� void �Լ��� EventListener��� ������ ���δ�.
typedef std::function<VOID()> EventListener;

typedef struct position
{
	float x;
	float y;
}Position;

namespace ENGINE //namespace�� ���� ����?
{
	enum // ����(no name) enum, ���� ������ ���Ǵ� ���� �⺻ ������ ���� ��
	{
		ClientSize_Width = 800, // Ŭ���̾�Ʈ�� �ʺ� 800
		ClientSize_Height = 600, // Ŭ���̾�Ʈ�� ���� 600
		Client_Per_X = 50, 
		Client_Per_Y = 50, /* 0 ~ 100% */ //Ŭ���̾�Ʈ�� ������ �ۼ�Ʈ?
		FPS = 120 /* �ʴ� ������ */
	};

	__interface Scene // ���̶�� �������̽��� �����.
	{
		VOID Initialize();	//�ʱ�ȭ
		VOID Release();		//����
		VOID Update(CONST FLOAT& deltaTime);	//������Ʈ, ����
		VOID Draw();		//�׸��� 
	};
}

#endif // !ENGINE_MECRO_H
