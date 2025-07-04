#pragma once
#include"SEntity.h"

namespace Sichun
{
	class GameObject;
	class Component:public Entity
	{
	public:
		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(std::shared_ptr<GameObject>owner) { _owner = owner; }
		std::shared_ptr<GameObject>GetOwner() { return _owner; }

	private:
		std::shared_ptr<GameObject>_owner;
	};

}
