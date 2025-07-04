#include "GameObject.h"
#include "InputManager.h"
#include"STime.h"
namespace Sichun {
	GameObject::GameObject()
	{
		SetPosition(0, 0);
	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		for (shared_ptr<Component>comp : _components)
		{
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (shared_ptr<Component>comp : _components)
		{
			comp->Update();
		}
		
	}
	void GameObject::LateUpdate()
	{
		for (shared_ptr<Component>comp : _components)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (shared_ptr<Component>comp : _components)
		{
			comp->Render(hdc);
		}
	}
}