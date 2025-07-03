#pragma once
#include"CommonInclude.h"

namespace Sichun {
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
		void SetName(const wstring& name) { _name = name; }
		wstring& GetName() { return _name; }
	private:
		wstring _name;

	};

}
