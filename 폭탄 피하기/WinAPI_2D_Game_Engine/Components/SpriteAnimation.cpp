#include "SpriteAnimation.h"
#include "SpriteRenderer.h"
#include "../TimeManager.h"


//���� �Ӹ� �ƴ϶� ������ �ǵ��� ������ ��
namespace ENGINE
{
	SpriteAnimation::SpriteAnimation(UINT divX, UINT divY, BOOL autoPlay, BOOL Loop) :
		AnimationComponent(divY, divX, autoPlay, isLoop),
		frame(0), animTimer(frameRate), renderer(nullptr)
	{ }

	//���� �����ؼ� ������ �ǰ� �ѹ��� ����� �ǵ����Ұ�
	VOID SpriteAnimation::Operate(GameObject* Owner)
	{
		//���ӿ�����Ʈ �� �׷��� ������Ʈ�� renderer�� �����Ѵ�. 
		renderer = Owner->GetComponent(ComponentType::Graphic);
		if (!renderer) return;

		//frame�� renderer�� �ִ� ����� ������
		//index�� renderer�� �ִ� ����� ����
		static_cast<SpriteRenderer*>(renderer)->SetSrc(frame, index);

		// isPlaying�� false�� �������� �ʴ´�.
		if (!isPlaying)
		{
			//ù �ִϸ��̼����� �ʱ�ȭ
			frame = 0;
			//frameRate== �����Ӵ� �ɸ��� �ð���  animTimer�� �����Ѵ�.
			animTimer = frameRate;
			return;
		}

		// ���⼭ ���� ������ �����.
		// BOOL isLoop
		//animTimer : �����Ӵ� �ɸ��� �ð�
		//�����ӿ� �ɸ��� �ð��� (������Ÿ�� ���ϱ� ���ǵ�)�� ���Ѵ�.

		animTimer += TimeMgr->DeltaTime() * speed;
		//�����Ӵ� �ɸ��� �ð����� �ִϸ��̼� ����ð��� ũ�ٸ�
		if (frameRate <= animTimer)
		{
			//�ִϸ��̼� ����ð��� �ʱ�ȭ�Ѵ�.
			animTimer -= frameRate;
			//isReverse �� ���ǵ尡 0�̸� true�̴�. true�̸� -1 false�̸� 1�� ���Ѵ�.
			// �������� �Ѱ��ִ� ����

			if (!isLoop && frame >= (int)(length-1))
			{
				isPlaying = false;
				return;
			}
			//������ ����
			frame += (isReverse ? -1 : 1);
			//������ üũ�� �������̸� ó������ ������
			frame = Repeat(frame, (int)(length - 1));
		}
	}
	//������ ��� ���� ��
	//������ �ѹ� ���� ���̻� ���� �ʴ°�
	//������ �ѹ� ���Ҵٴ� ǥ�ø� ���ְ� ǥ�ø� Ư�� ��Ȳ������ �ʱ�ȭ��
	VOID SpriteAnimation::Reset()
	{
		index = 0U;
		speed = 1U;
		frame = 0;
		animTimer = frameRate;
	}
}


//�ڵ��ľ��ϴ� ���Ͽ츦 �������� 