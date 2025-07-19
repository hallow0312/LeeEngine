#pragma once
#include"SResource.h"
#include"../Common/CommonInclude.h"
namespace Sichun 
{
	class Resources
	{
	public:
		template<typename T>
		static std::shared_ptr<T> Find(const std::wstring& key)
		{
			static_assert(std::is_base_of<Resource, T>::value, "T must be derived from Resource");

			auto iter = _resources.find(key);
			if (iter == _resources.end())
				return nullptr;

			return std::dynamic_pointer_cast<T>(iter->second);
		}
		template<typename T>
		static std::shared_ptr<T>Load(const std::wstring& key, const std::wstring& path)
		{
			static_assert(std::is_base_of<Resource, T>::value, "T must be derived from Resource");

			std::shared_ptr<T>resource = Resources::Find<T>(key);
			if (resource != nullptr)return resource;

			resource = std::make_shared<T>();
			if (FAILED(resource->Load(path)))assert(false);
			
			resource->SetName(key);
			resource->SetPath(path);
			_resources.insert({ key,resource });
			return resource;
		}
	
		static void Insert(const std::wstring& key, std::shared_ptr<Resource> resource)
		{
			if (key == L"")return;
			if (resource == nullptr)return;
			_resources.insert(std::make_pair(key, resource));
		}
			
		
	private:
		static std::map<std::wstring,std::shared_ptr<Resource>>_resources;
		 
	};
}

