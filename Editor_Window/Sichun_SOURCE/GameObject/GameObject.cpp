#include "GameObject.h"
#include "InputManager.h"
#include"Common/STime.h"
#include"Component/STransform.h"

namespace Sichun {
	GameObject::GameObject():_state(ObjectState::Active)
	{
		_components.resize(static_cast<UINT>(Enum::ComponentType::End));
	}

	
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		for (const auto& comp : _components)  
		{
			if (comp) comp->Initialize();
		}
		for (const auto& script : _scripts)
		{
			if (script)script->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (const auto& comp : _components) 
		{
			if (comp) comp->Update();
		}
		for (const auto& script : _scripts)
		{
			if (script)script->Update();
		}
	}
	void  GameObject::InitializeTransform()
	{
		if (!GetComponent<Transform>()) {

			std::shared_ptr<Transform>transform = AddComponent<Transform>();
			transform->SetPosition(Vector2(0, 0));
		}
		
	}

	void GameObject::LateUpdate()
	{
		for (const auto& comp : _components)  
		{
			if (comp) comp->LateUpdate();
		}
		for (const auto& script : _scripts)
		{
			if (script)script->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (const auto& comp : _components)  
		{
			if (comp) comp->Render(hdc);
		}
		for (const auto& script : _scripts)
		{
			if (script)script->Render(hdc);
		}
	}
	void GameObject::SetActive(bool value)
	{
		_state = value ? ObjectState::Active : ObjectState::Paused;

		auto transform = GetComponent<Transform>();
		if (!transform)
			return;

		for (const auto& child : transform->GetChildren())
		{
			if (auto owner = child->GetOwner())
			{
				owner->SetActive(value); 
			}
		}
	}
}