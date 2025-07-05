#pragma once
#include"Common/SEntity.h"

namespace Sichun
{
	//abstract
	class Resource : public Entity
	{
	public:
		Resource(Enum::ResourceType type);
		
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; //pure virtual 
		const std::wstring GetPath() { return _path; }
		void SetPath(const std::wstring& path) { _path = path; }
	private:
		Enum::ResourceType _type;
		std::wstring _path;
	};
	
}

