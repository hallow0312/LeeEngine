#pragma once
#include"CommonInclude.h"
#include"SComponent.h"
//ue ¿¡¼­´Â actor
namespace Sichun
{
	class GameObject:  public enable_shared_from_this<GameObject>
	{
	public:
		GameObject();
		~GameObject();
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetPosition(float  x, float y)
		{
			_x = x;
			_y = y;
		}
		float GetPositionX()
		{
			return _x;
		}
		float GetPositionY()
		{
			return _y;
			
		}
		template<typename T>
		
		shared_ptr<T> AddComponent()
		{
			shared_ptr<T> component = make_shared<T>();
			component->SetOwner(shared_from_this()); 
			_components.push_back(component);
			return component;
		}
		template<typename T>
		shared_ptr<T>GetComponent()
		{
			shared_ptr<T>component = nullptr;
			for (shared_ptr<Component>comp : _components)
			{
				component = dynamic_pointer_cast<T>(comp);
				if (component)break;
			}
			return component;
		}

	private:

		//gameObejct Coord ; 
		float _x;
		float _y;
		vector<shared_ptr<Component>>_components; 
	};
}

