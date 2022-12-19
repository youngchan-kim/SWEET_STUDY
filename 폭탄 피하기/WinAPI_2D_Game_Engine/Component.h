#include<windows.h>
#include<map>
#include "Math.h"

#ifndef COMPONENT_H
#define COMPONENT_H

namespace ENGINE
{
	//������Ʈ�� ���� ���ӿ�����Ʈ, ��ȯ, �׷���, �Է�, �ִϸ��̼�
	enum class ComponentType { GameObject, Transform, Graphic, Input, Animation, };

	class GameObject;
	//������Ʈ�� ���۰� �缳��, ������ƮŸ���� �����´�. 
	__interface Component
	{
		VOID Operate(GameObject* Owner);
		VOID Reset();
		ComponentType GetType() CONST;
	};

	//��ȯ ����ü�� �������̽� ������Ʈ�� ��ӹ޴´�.
	struct Transform : public Component
	{
		//��ġ
		Vector2 position;
		//ũ��
		Vector2 scale;

		//��ȯ�Լ��� �Ű������� ��ġ�� ũ�⸦ �����Ѵ�.
		Transform() : position(0.0f, 0.0f), scale(1.0f, 1.0f) {}

		// Component��(��) ���� ��ӵ�
		virtual VOID Operate(GameObject* Owner) override { }
		virtual VOID Reset() override;
		virtual ComponentType GetType() const override { return ComponentType::Transform; }
	};

	//���ӿ�����Ʈ�� ������Ʈ�� ��� �޴´�.
	class GameObject : public Component
	{
	private:
		std::map<ComponentType, Component*> components;

	protected:
		Transform* transform;

	public:
		GameObject();
		virtual ~GameObject();

	public:
		//� ������Ʈ���� ������Ʈ�� ������ �������� �Լ�
		Component* GetComponent(CONST ComponentType& type);
		//������Ʈ�� �߰��ϴ� �Լ�
		BOOL AddComponent(Component* component);
		//��ȯ�� ������ �������� �Լ�
		Transform* GetTransform() CONST { return transform; }

		//��ȯ�� ��ġ�� �Ű������� �� ��ġ ���� �Լ�
		virtual VOID SetPosition(CONST Vector2& pos) { transform->position = pos; }
		//��ȯ�� ũ�⸦ �Ű������� �� ũ�� ���� �Լ�
		virtual VOID SetScale(CONST Vector2& scale) { transform->scale = scale; }

		// Component��(��) ���� ��ӵ�
		virtual VOID Operate(GameObject*) override;
		virtual VOID Reset() override;
		virtual ComponentType GetType() const override { return ComponentType::GameObject; }
	};
	//�׷���������Ʈ
	class GrahpicComponent : public Component
	{
	public:
		virtual ~GrahpicComponent() { }

		//��ǥ�� �޾� ũ�⸦ ����
		virtual VOID SetScale(UINT cx, UINT cy) abstract;
		virtual VOID Draw() abstract;
		// Component��(��) ���� ��ӵ�
		virtual ComponentType GetType() const override { return ComponentType::Graphic; }
	};
	//�Է� ������Ʈ
	class InputComponent : public Component
	{
	public:
		virtual ~InputComponent() { }

		// Component��(��) ���� ��ӵ�
		virtual ComponentType GetType() const override { return ComponentType::Input; }
	};
	//�ִϸ��̼� ������Ʈ
	class AnimationComponent : public Component
	{
	protected:
		BOOL isPlaying, isReverse, isLoop;
		UINT index;
		FLOAT speed;
		CONST UINT length;
		CONST UINT maxSize;
		CONST FLOAT frameRate;

	private:
		AnimationComponent();
	public:
		//
		AnimationComponent(UINT count, UINT length, BOOL Loop, BOOL autoPlay) : isLoop(Loop), isPlaying(autoPlay), isReverse(FALSE), index(0U), speed(1.0f), length(length), maxSize(count), frameRate(1.0f / length) { }
		virtual ~AnimationComponent() { }

		//�ִϸ��̼��� ���ǵ�
		VOID SetSpeed(FLOAT speed);
		//�÷��� �߿� ����
		// �÷��̾��� �ε��� 
		//clamp : index�� 0 ��maxSize - 1 ������ ���̴�.
		VOID Play(UINT index) { this->index = clamp(index, 0, maxSize - 1); isPlaying = TRUE; }

		//������ ���߾�����
		VOID Stop() { isPlaying = FALSE; }
		BOOL IsPlay(){ return isPlaying; }

		// Component��(��) ���� ��ӵ�
		virtual ComponentType GetType() const override { return ComponentType::Animation; }
	};
}

#endif // !COMPONENT_H