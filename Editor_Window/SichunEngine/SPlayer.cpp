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
		
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}