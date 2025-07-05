#pragma once
#include"../Common/SEntity.h"

namespace Sichun
{
	class GameObject;
	class Component:public Entity
	{
	public:
		Component(Enum::ComponentType type);
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetOwner(std::shared_ptr<GameObject>owner) { _owner = owner; }
		std::shared_ptr<GameObject>GetOwner() { return _owner; }
		 Enum::ComponentType GetType() { return _type; }
	private:
		std::shared_ptr<GameObject>_owner;
		 Enum::ComponentType _type;
	};

}
