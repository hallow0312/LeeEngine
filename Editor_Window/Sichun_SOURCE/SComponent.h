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

		void SetOwner(shared_ptr<GameObject>owner) { _owner = owner; }
		shared_ptr<GameObject>GetOwner() { return _owner; }

	private:
		shared_ptr<GameObject>_owner;
	};

}
