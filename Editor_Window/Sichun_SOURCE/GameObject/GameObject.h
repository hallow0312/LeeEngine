#pragma once
#include "../Common/CommonInclude.h"
#include "../Component/SComponent.h"

namespace Sichun
{
	class GameObject : public std::enable_shared_from_this<GameObject>
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		
		void InitializeTransform();

		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> component = std::make_shared<T>();
			component->SetOwner(shared_from_this());
			UINT type = static_cast<UINT>(component->GetType());
			if (_components[type] != nullptr);
			_components[type] = component;
			return component;
		}

		template<typename T>
		std::shared_ptr<T> GetComponent()
		{
			std::shared_ptr<T> component = nullptr;
			for (std::shared_ptr<Component> comp : _components)
			{
				component = std::dynamic_pointer_cast<T>(comp);
				if (component) break;
			}
			return component;
		}
	private:
		
		std::vector<std::shared_ptr<Component>> _components;
	};
}
