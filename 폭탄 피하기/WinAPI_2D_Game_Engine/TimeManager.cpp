#include "TimeManager.h"
namespace ENGINE
{
	VOID TimeManager::Initialize(UINT32  FPS)
	{
		//Ÿ�Ӹ޴����� fps�� 1000���� 120fps�̴�.
		this->FPS = 1000 / FPS;
		//GetTickCount64 : �����찡 ���۵ǰ� ���������� ��� �ð��� Ȯ��(�����ð� Ȯ��)
		//�ʱ�ȭ �Ǿ����� �� �ð��� ����
		currTime = lastTime = GetTickCount64();
	}

	BOOL TimeManager::Update()
	{
		//������Ʈ �ɶ� �ð��� ����
		currTime = GetTickCount64();

		//�������� : ����ð� - �����ð�
		elapsed = (currTime - lastTime);
		//�������� this->fps�� ������ ������ FALSE
		if (elapsed < FPS) return FALSE;
		//���� ���� this->fps�� ������ ũ�� 
		//���� �ð��� (����ð� - �����ð�)*0.001f
		elapseTime = elapsed * 0.001f;
		//���� �ð� �� ����
		lastTime = currTime;

		return TRUE;
	}
}
