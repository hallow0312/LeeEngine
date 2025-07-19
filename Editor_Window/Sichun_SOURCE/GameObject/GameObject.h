#pragma once
#include "../Common/CommonInclude.h"
#include "../Component/SComponent.h"
#include"../Component/SMonobehaviour.h"

namespace Sichun
{
	class GameObject : public std::enable_shared_from_this<GameObject>
	{
	public:
		//friend void  Object::Destroy(std::shared_ptr<GameObject>obj);
	
		enum class ObjectState
		{
			Active,
			Paused,
			Destroy,
			End
		};
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		void SetActive(bool value);
		
		void InitializeTransform();

		ObjectState GetActive() { return _state; }
		template<typename T>
		std::shared_ptr<T> AddComponent()
		{
			std::shared_ptr<T> component = std::make_shared<T>();
			component->SetOwner(shared_from_this());

			auto type = component->GetType();
			if (type == Enum::ComponentType::Script)
			{
				_scripts.push_back(component);
			}
			else
			{
				size_t index = static_cast<size_t>(type);
				if (index >= _components.size())
					_components.resize(index + 1);

				_components[index] = component;
			}

			return component;
		}
	
		
		template<typename T>
		std::shared_ptr<T> GetComponent()
		{
			static_assert(std::is_base_of_v<Component, T>, "T must inherit from Component");

			// 고정 컴포넌트 먼저 검색
			for (const auto& comp : _components)
			{
				if (auto casted = std::dynamic_pointer_cast<T>(comp))
					return casted;
			}

			// 스크립트도 검색
			for (const auto& script : _scripts)
			{
				if (auto casted = std::dynamic_pointer_cast<T>(script))
					return casted;
			}

			return nullptr;
		}
		void OnDestroy() { _state = ObjectState::Destroy; }
		
	private:
		
		std::vector<std::shared_ptr<Component>>_components;
		std::vector<std::shared_ptr<Component>> _scripts;
		ObjectState _state;

	private:
	
	};
}
