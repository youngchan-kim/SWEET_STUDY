#include "ResourceManager.h"
#include <fstream>
#include <io.h>//access()

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING // c++17 이상의 경우 #include<filesystem>를 사용.
#include <experimental/filesystem> //directory_iterator()

using namespace std::experimental::filesystem;
namespace ENGINE
{
	//소멸자 호출에서 리소스 클리어
	ResourceManager::~ResourceManager() { Clear(); }

	//초기화할때 리소스 클리어
	VOID ResourceManager::Initialize() { Clear(); }

	//파일의 이름이 있고 파일과 디렉토리가 존재하면 불러온다.
	BOOL ResourceManager::Load(const std::string& fileName)
	{
		//파일의 이름 변수가 비었다면 FALSE를 리턴
		if (fileName.empty()) return FALSE;

		std::string path = defaultPath + fileName;
		// 0 : 파일 및 디렉토리의 존재 유무.
		// 2 : 쓰기 접근 가능 여부.
		// 4 : 읽기 접근 가능 여부.
		// 6 : 읽기, 쓰기 접근 가능 여부.
		// return : 0(true), -1(false)
		//_access(path.c_str(), 0)는 해당 패스(path.c_str())에 0 ( 파일 및 디렉토리의 존재 유,무)
		//있으면 0 없으면 -1
		if (0 != _access(path.c_str(), 0)) return FALSE;
		
		//비트맵을 동적할당
		Bitmap* bitmap = new Bitmap;

		// 동적할당된 비트맵 포인터에 로드
		bitmap->Load(defaultPath + fileName);

		//리소스들의 맵에 파일의 이름이 key이고, bitmap이 내용으로하는 정보를 추가한다.
		resources.insert(make_pair(fileName, bitmap));

		return TRUE;
	}

	//폴더 내의 파일 및 폴더를 찾아서 전부 로드한다.
	VOID ResourceManager::LoadAll(const std::string& directoryName)
	{
		//v1이란?/*std::experimental::filesystem::*/의 namespace이다.
		v1::path path;
		std::string name;

		//directory_iterator : 디렉토리(폴더) 내의 파일 및 폴더를 찾는다. 하위 디렉토리는 탐색하지 않는다.
		for (const auto& file : directory_iterator(defaultPath + directoryName))
		{
			//파일의 path를 path변수에 대입연산
			path = file.path();
			//extension() : 확장자명
			//u8string() : 문자를 utf-8로 만듬 
			if (".bmp" != path.extension().u8string()) continue;//비트맵 리소스 만을 로드

			// 패스 전체를 utf-8로 만들어 리턴
			name = path.u8string();
			// path중 defaultPath를 찾아서 defaultPath의 길이만큼 삭제("")후 합침
			name.replace(name.find(defaultPath), strlen(defaultPath), ""); //Load()에서 defaultPath를 추가하여 쓰기 때문에 문자열에서 제거.

			if (nullptr != GetBitmap(name))continue; //이미 가지고 있는 파일은 로드에서 제외.
			Load(name);
		}
	}

	// 가져오지 않은 비트맵을 찾아서 있으면 가져온다. 
	Bitmap* ResourceManager::GetBitmap(const std::string& name)
	{
		//리소스들중에서 name을 찾아서 iter에 대입연산
		std::map<std::string, Bitmap*>::iterator iter = resources.find(name);
		//찾은 name이 리소스들 중에 일치하는게 없으면 name의 정보를 리턴
		if (resources.end() != iter) return iter->second;
		//일치하는게 있으면 nullptr을 리턴
		return nullptr;
	}

	// 리소스를 클리어
	VOID ResourceManager::Clear()
	{
		// 리소스의 second를 삭제
		for (std::pair<std::string, Bitmap*>resource : resources) DEL(resource.second);
		// 리소스들을 해제
		resources.clear();
	}
} // namespace ENGINE