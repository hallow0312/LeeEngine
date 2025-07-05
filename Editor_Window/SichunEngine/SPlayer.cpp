#include "SPlayer.h"
#include"Common/STime.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
namespace Sichun
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
		if (InputManager::GetKey(KeyCode::RIGHT))
		{
			std::shared_ptr<Transform> transform = GetComponent<Transform>();
			Vector2 pos = transform->GetPos();
			pos.x += 100.0f * Time::DeltaTime();
			transform->SetPos(pos);
		}
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}