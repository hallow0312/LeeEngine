#include "PlayerMovement.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Common/STime.h"
#include"GameObject/GameObject.h"
#include"Component/SComponent.h"
namespace Sichun
{
	PlayerMovement::PlayerMovement() 
	{

	}

	PlayerMovement::~PlayerMovement() 
	{
	}

	void PlayerMovement ::Initialize()
	{
	}

	void PlayerMovement::Update()
	{
		Move();
	}

	void PlayerMovement::LateUpdate()
	{
	}

	void PlayerMovement::Render(HDC hdc)
	{
	}

	void PlayerMovement::Move()
	{

		if (InputManager::GetAxis("Horizontal"))
		{
			int num = InputManager::GetAxis("Horizontal");
			std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPos();
			pos.x += 100.0f *num* Time::DeltaTime();
			transform->SetPos(pos);
		}
		
		if (InputManager::GetAxis("Vertical"))
		{
			int num = InputManager::GetAxis("Vertical");
			std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
			Vector2 pos = transform->GetPos();
			pos.y += 100.0f * num*Time::DeltaTime();
			transform->SetPos(pos);
		}
		
	}

}