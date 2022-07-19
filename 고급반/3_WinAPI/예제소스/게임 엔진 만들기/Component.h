#include<windows.h>
#include<map>
#include "Math.h"

#ifndef COMPONENT_H
#define COMPONENT_H

namespace ENGINE
{
	enum class ComponentType { GameObject, Transform, Graphic, Input, Animation, };

	class GameObject;
	__interface Component
	{
		VOID Operate(GameObject* Owner);
		VOID Reset();
		ComponentType GetType() CONST;
	};

	struct Transform : public Component
	{
		Vector2 position;
		Vector2 scale;

		Transform() : position(0.0f, 0.0f), scale(1.0f, 1.0f) {}

		// Component��(��) ���� ��ӵ�
		virtual VOID Operate(GameObject* Owner) override { }
		virtual VOID Reset() override;
		virtual ComponentType GetType() const override { return ComponentType::Transform; }
	};

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
		Component* GetComponent(CONST ComponentType& type);
		BOOL AddComponent(Component* component);
		Transform* GetTransform() CONST { return transform; }

		virtual VOID SetPosition(CONST Vector2& pos) { transform->position = pos; }
		virtual VOID SetScale(CONST Vector2& scale) { transform->scale = scale; }

		// Component��(��) ���� ��ӵ�
		virtual VOID Operate(GameObject*) override;
		virtual VOID Reset() override;
		virtual ComponentType GetType() const override { return ComponentType::GameObject; }
	};

	class GrahpicComponent : public Component
	{
	public:
		virtual ~GrahpicComponent() { }

		virtual VOID SetScale(UINT cx, UINT cy) abstract;
		virtual VOID Draw() abstract;
		// Component��(��) ���� ��ӵ�
		virtual ComponentType GetType() const override { return ComponentType::Graphic; }
	};

	class InputComponent : public Component
	{
	public:
		virtual ~InputComponent() { }

		// Component��(��) ���� ��ӵ�
		virtual ComponentType GetType() const override { return ComponentType::Input; }
	};

	class AnimationComponent : public Component
	{
	protected:
		BOOL isPlaying, isReverse;
		UINT index;
		FLOAT speed;
		CONST UINT length;
		CONST UINT maxSize;
		CONST FLOAT frameRate;

	private:
		AnimationComponent();
	public:
		AnimationComponent(UINT count, UINT length, BOOL autoPlay) : isPlaying(autoPlay), isReverse(FALSE),  index(0U), speed(1.0f), length(length), maxSize(count), frameRate(1.0f / length) { }
		virtual ~AnimationComponent() { }

		VOID SetSpeed(FLOAT speed);
		VOID Play(UINT index) { this->index = clamp(index, 0, maxSize - 1); isPlaying = TRUE; }
		VOID Stop() { isPlaying = FALSE; }
		// Component��(��) ���� ��ӵ�
		virtual ComponentType GetType() const override { return ComponentType::Animation; }	
	};
}

#endif // !COMPONENT_H