#include "SLayer.h"

namespace  Sichun
{
	Layer::Layer()
		: _objs{}
	{

	}
	Layer::~Layer()
	{
		
	}
	void Layer::Initialize()
	{
		for (const auto&element : _objs)
		{
			if (element == nullptr)continue;
			element->Initialize();
		}
	}
	void Layer::Update()
	{
		for (const auto& element  : _objs)
		{
			if (element == nullptr)continue;
			
		
			if (IsElementDisabled(element))
				continue;
			
			element->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (const auto& element  : _objs)
		{
			if (element == nullptr)continue;
			if (IsElementDisabled(element))
				continue;
			element->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (const auto& element : _objs)
		{
			if (element == nullptr)continue;

			if(IsElementDisabled(element))
				continue;

			element->Render(hdc);
		}
	}
	void Layer::DestroyDeadObjects()
	{
		std::erase_if(_objs,
			[](std::shared_ptr<GameObject> gameObj)
			{
				return gameObj->IsDead();
			});
	}
	void Layer::AddGameObject(std::shared_ptr<GameObject>obj)
	{
		if (obj == nullptr)return;
		_objs.push_back(obj);
	}
	void Layer::DestroyGameObject(std::shared_ptr<GameObject> obj)
	{
		std::erase_if(_objs,
			[=](std::shared_ptr<GameObject> gameObj)
			{
				return gameObj == obj;
			});
		
	}
	bool Layer::IsElementDisabled(std::shared_ptr<GameObject> obj)
	{
		GameObject::ObjectState state = obj->GetActive();
		return (state == GameObject::ObjectState::Paused || state == GameObject::ObjectState::Destroy);
	}
		
}