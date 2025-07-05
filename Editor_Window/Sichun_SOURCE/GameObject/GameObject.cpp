#include "GameObject.h"
#include "InputManager.h"
#include"Common/STime.h"
#include"Component/STransform.h"

namespace Sichun {
	GameObject::GameObject()
	{
		
	}
	
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		
		for (std::shared_ptr<Component>comp : _components)
		{
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (std::shared_ptr<Component>comp : _components)
		{
			comp->Update();
		}
		
	}
	void  GameObject::InitializeTransform()
	{
		if (!GetComponent<Transform>()) {
			std::shared_ptr<Transform>transform = AddComponent<Transform>();
			transform->SetPos(Vector2(0, 0));
		}
		
	}
	void GameObject::LateUpdate()
	{
		for (std::shared_ptr<Component>comp : _components)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (std::shared_ptr<Component>comp : _components)
		{
			comp->Render(hdc);
		}
	}
}