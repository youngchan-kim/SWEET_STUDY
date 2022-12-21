#include<windows.h>
#include<map>
#include "Math.h"

#ifndef COMPONENT_H
#define COMPONENT_H

namespace ENGINE
{
	//컴포넌트의 종류 게임오브젝트, 변환, 그래픽, 입력, 애니매이션
	enum class ComponentType { GameObject, Transform, Graphic, Input, Animation, };

	class GameObject;
	//오브젝트별 동작과 재설정, 컴포넌트타입을 가져온다. 
	__interface Component
	{
		VOID Operate(GameObject* Owner);
		VOID Reset();
		ComponentType GetType() CONST;
	};

	//변환 구조체는 인터페이스 컴포넌트를 상속받는다.
	struct Transform : public Component
	{
		//위치
		Vector2 position;
		//크기
		Vector2 scale;

		//변환함수의 매개변수로 위치와 크기를 대입한다.
		Transform() : position(0.0f, 0.0f), scale(1.0f, 1.0f) {}

		// Component을(를) 통해 상속됨
		virtual VOID Operate(GameObject* Owner) override { }
		virtual VOID Reset() override;
		virtual ComponentType GetType() const override { return ComponentType::Transform; }
	};

	//게임오브젝트는 컴포넌트를 상속 받는다.
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
		//어떤 컴포넌트인지 컴포넌트의 정보를 가져오는 함수
		Component* GetComponent(CONST ComponentType& type);
		//컴포넌트를 추가하는 함수
		BOOL AddComponent(Component* component);
		//변환의 정보를 가져오는 함수
		Transform* GetTransform() CONST { return transform; }

		//변환된 위치를 매개변수로 한 위치 설정 함수
		virtual VOID SetPosition(CONST Vector2& pos) { transform->position = pos; }
		//변환된 크기를 매개변수로 한 크기 설정 함수
		virtual VOID SetScale(CONST Vector2& scale) { transform->scale = scale; }

		// Component을(를) 통해 상속됨
		virtual VOID Operate(GameObject*) override;
		virtual VOID Reset() override;
		virtual ComponentType GetType() const override { return ComponentType::GameObject; }
	};
	//그래픽컴포넌트
	class GrahpicComponent : public Component
	{
	public:
		virtual ~GrahpicComponent() { }

		//좌표를 받아 크기를 설정
		virtual VOID SetScale(UINT cx, UINT cy) abstract;
		virtual VOID Draw() abstract;
		// Component을(를) 통해 상속됨
		virtual ComponentType GetType() const override { return ComponentType::Graphic; }
	};
	//입력 컴포넌트
	class InputComponent : public Component
	{
	public:
		virtual ~InputComponent() { }

		// Component을(를) 통해 상속됨
		virtual ComponentType GetType() const override { return ComponentType::Input; }
	};
	//애니매이션 컴포넌트
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

		//애니매이션의 스피드
		VOID SetSpeed(FLOAT speed);
		//플레이 중에 사용됨
		// 플레이어의 인덱스 
		//clamp : index는 0 과maxSize - 1 사이의 값이다.
		VOID Play(UINT index) { this->index = clamp(index, 0, maxSize - 1); isPlaying = TRUE; }

		//게임을 멈추었을때
		VOID Stop() { isPlaying = FALSE; }
		BOOL IsPlay(){ return isPlaying; }

		// Component을(를) 통해 상속됨
		virtual ComponentType GetType() const override { return ComponentType::Animation; }
	};
}

#endif // !COMPONENT_H