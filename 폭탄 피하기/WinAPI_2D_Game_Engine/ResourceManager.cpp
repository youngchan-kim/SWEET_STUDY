#include "ResourceManager.h"
#include <fstream>
#include <io.h>//access()

#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING // c++17 �̻��� ��� #include<filesystem>�� ���.
#include <experimental/filesystem> //directory_iterator()

using namespace std::experimental::filesystem;
namespace ENGINE
{
	//�Ҹ��� ȣ�⿡�� ���ҽ� Ŭ����
	ResourceManager::~ResourceManager() { Clear(); }

	//�ʱ�ȭ�Ҷ� ���ҽ� Ŭ����
	VOID ResourceManager::Initialize() { Clear(); }

	//������ �̸��� �ְ� ���ϰ� ���丮�� �����ϸ� �ҷ��´�.
	BOOL ResourceManager::Load(const std::string& fileName)
	{
		//������ �̸� ������ ����ٸ� FALSE�� ����
		if (fileName.empty()) return FALSE;

		std::string path = defaultPath + fileName;
		// 0 : ���� �� ���丮�� ���� ����.
		// 2 : ���� ���� ���� ����.
		// 4 : �б� ���� ���� ����.
		// 6 : �б�, ���� ���� ���� ����.
		// return : 0(true), -1(false)
		//_access(path.c_str(), 0)�� �ش� �н�(path.c_str())�� 0 ( ���� �� ���丮�� ���� ��,��)
		//������ 0 ������ -1
		if (0 != _access(path.c_str(), 0)) return FALSE;
		
		//��Ʈ���� �����Ҵ�
		Bitmap* bitmap = new Bitmap;

		// �����Ҵ�� ��Ʈ�� �����Ϳ� �ε�
		bitmap->Load(defaultPath + fileName);

		//���ҽ����� �ʿ� ������ �̸��� key�̰�, bitmap�� ���������ϴ� ������ �߰��Ѵ�.
		resources.insert(make_pair(fileName, bitmap));

		return TRUE;
	}

	//���� ���� ���� �� ������ ã�Ƽ� ���� �ε��Ѵ�.
	VOID ResourceManager::LoadAll(const std::string& directoryName)
	{
		//v1�̶�?/*std::experimental::filesystem::*/�� namespace�̴�.
		v1::path path;
		std::string name;

		//directory_iterator : ���丮(����) ���� ���� �� ������ ã�´�. ���� ���丮�� Ž������ �ʴ´�.
		for (const auto& file : directory_iterator(defaultPath + directoryName))
		{
			//������ path�� path������ ���Կ���
			path = file.path();
			//extension() : Ȯ���ڸ�
			//u8string() : ���ڸ� utf-8�� ���� 
			if (".bmp" != path.extension().u8string()) continue;//��Ʈ�� ���ҽ� ���� �ε�

			// �н� ��ü�� utf-8�� ����� ����
			name = path.u8string();
			// path�� defaultPath�� ã�Ƽ� defaultPath�� ���̸�ŭ ����("")�� ��ħ
			name.replace(name.find(defaultPath), strlen(defaultPath), ""); //Load()���� defaultPath�� �߰��Ͽ� ���� ������ ���ڿ����� ����.

			if (nullptr != GetBitmap(name))continue; //�̹� ������ �ִ� ������ �ε忡�� ����.
			Load(name);
		}
	}

	// �������� ���� ��Ʈ���� ã�Ƽ� ������ �����´�. 
	Bitmap* ResourceManager::GetBitmap(const std::string& name)
	{
		//���ҽ����߿��� name�� ã�Ƽ� iter�� ���Կ���
		std::map<std::string, Bitmap*>::iterator iter = resources.find(name);
		//ã�� name�� ���ҽ��� �߿� ��ġ�ϴ°� ������ name�� ������ ����
		if (resources.end() != iter) return iter->second;
		//��ġ�ϴ°� ������ nullptr�� ����
		return nullptr;
	}

	// ���ҽ��� Ŭ����
	VOID ResourceManager::Clear()
	{
		// ���ҽ��� second�� ����
		for (std::pair<std::string, Bitmap*>resource : resources) DEL(resource.second);
		// ���ҽ����� ����
		resources.clear();
	}
} // namespace ENGINE