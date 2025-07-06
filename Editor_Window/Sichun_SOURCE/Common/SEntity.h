#pragma once
#include"CommonInclude.h"

namespace Sichun {
	using  namespace math;
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();
		void SetName(const std::wstring& name) { _name = name; }
		std::wstring& GetName() { return _name; }
	private:
		std::wstring _name;

	};

}
