// WinApiEngine.h
//�⺻���� ������ �Ͽ� Window�� ����� ���� ������ �۵��Ѵ�.
//����Ʈ �����ڸ� ������� �ʱ� ���Ͽ� private�� ���� �Ѵ�.
#include "EngineMecro.h"
//SceneManager �߰�
#include "SceneManager.h"
// #ifndef ENGINE_MAIN_H �ĺ��� ENGINE_MAIN_H �� ���ٸ� ����
#ifndef ENGINE_MAIN_H
#define ENGINE_MAIN_H
namespace ENGINE
{
	class WinApiEngine
	{
	private:
		BOOL isInit;			// �ʱ�ȭ �ߴ��� ���ߴ���
		INT32 x, y;				// int32�� 32�� ���� : 32��Ʈ�� ���� int�� �̶�� ��
								// ��� ���� : ��� ��ǻ�Ϳ��� ������ int���� ũ�⸸ ���� ����
		UINT32 width, height;	//unsignint : ������ �ִ� int 
		std::wstring title;		

		WinApiEngine(); // �����ڸ� �� �ι� ������
	public:
		WinApiEngine(HINSTANCE hInstance, std::wstring title, INT32 per_x, INT32 per_y, UINT32 width, UINT32 height);
		~WinApiEngine();

		INT Run(); //
		VOID Release();
	};
}

#endif // !ENGINE_MAIN_H
