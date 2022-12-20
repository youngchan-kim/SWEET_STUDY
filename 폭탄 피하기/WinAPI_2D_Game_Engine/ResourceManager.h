#pragma once
#include "Singleton.h"
#include "Bitmap.h"
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
namespace ENGINE
{
	//�̹����� �������⿡ ������ �߱��Ͽ� ������ �ʴ� ������ �ּҸ� ����
	static const char* defaultPath = "Resources\\";

	class ResourceManager : public Singleton <ResourceManager>
	{
	private:
		std::map<std::string, Bitmap*> resources;

		ResourceManager() {}
	public:
		~ResourceManager();

		//�ʱ�ȭ
		VOID Initialize();

		//�Էµ� �̸��� ��ġ�Ǵ� ��Ʈ�� �ҷ�����
		Bitmap* GetBitmap(const std::string& name);
		
		//��Ʈ�� �̹����� �ε��Ѵ�.
		BOOL Load(const std::string& fileName);
		
		//������ ��� ��Ʈ�� �̹����� �ε�.
		//���� ������ �˻����� �ʴ´�.
		VOID LoadAll(const std::string& directoryName = "");

		//�ε�Ǿ� �ִ� ��� ���ҽ��� �����.
		VOID Clear();

		friend Singleton;
	};//class ResourceManager
#define ResourceMgr ResourceManager::GetInstance()
} // namespace ENGINE
#endif // !RESOURCE_MANAGER_H

