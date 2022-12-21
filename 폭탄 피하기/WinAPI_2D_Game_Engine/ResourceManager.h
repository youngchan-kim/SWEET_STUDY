#pragma once
#include "Singleton.h"
#include "Bitmap.h"
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H
namespace ENGINE
{
	//이미지를 가져오기에 편리성을 추구하여 변하지 않는 값으로 주소를 설정
	static const char* defaultPath = "Resources\\";

	class ResourceManager : public Singleton <ResourceManager>
	{
	private:
		std::map<std::string, Bitmap*> resources;

		ResourceManager() {}
	public:
		~ResourceManager();

		//초기화
		VOID Initialize();

		//입력된 이름과 매치되는 비트맵 불러오기
		Bitmap* GetBitmap(const std::string& name);
		
		//비트맵 이미지를 로드한다.
		BOOL Load(const std::string& fileName);
		
		//폴더의 모든 비트맵 이미지를 로드.
		//하위 폴더는 검색하지 않는다.
		VOID LoadAll(const std::string& directoryName = "");

		//로드되어 있는 모든 리소스를 지운다.
		VOID Clear();

		friend Singleton;
	};//class ResourceManager
#define ResourceMgr ResourceManager::GetInstance()
} // namespace ENGINE
#endif // !RESOURCE_MANAGER_H

