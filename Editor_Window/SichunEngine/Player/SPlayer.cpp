#include "SPlayer.h"
#include"../SichunEngineHeader.h"
#include"Common/STime.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"PlayerController.h"
#include"YinYang.h"
namespace Sichun
{
	Player::Player():_leftYinYang(nullptr),_rightYinYang(nullptr)
	{
	}
	Player::~Player()
	{
	}
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
	void Player::Init()
	{
	
		AddComponent<PlayerAnimation>();
		AddComponent <BoxCollider2D>();
		AddComponent<RigidBody>();
		GetComponent<RigidBody>()->SetGravity(0.0f);
		AddComponent<PlayerController>();

		GetComponent<BoxCollider2D>()->SetOffset(Vector2(-10.f, -20.0f));
		GetComponent<BoxCollider2D>()->SetSize(Vector2(0.2f, 0.4f));
		
		{
			_leftYinYang = Object::Instantiate<GameObject>(Sichun::Enum::LayerType::Player);

			std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"YinYang");
			std::shared_ptr<SpriteRenderer> sprite = _leftYinYang->AddComponent<SpriteRenderer>();
			sprite->SetTexture(texture);

			_leftYinYang ->AddComponent<YinYang>();
			_leftYinYang ->GetComponent<YinYang>()->Setting(GetComponent<Transform>(), Vector2(-30.0f, -5.0f));
		}
		{
			_rightYinYang = Object::Instantiate<GameObject>(Sichun::Enum::LayerType::Player);

			std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"YinYang");
			std::shared_ptr<SpriteRenderer> sprite = _rightYinYang->AddComponent<SpriteRenderer>();
			sprite->SetTexture(texture);

			_rightYinYang->AddComponent<YinYang>();
			_rightYinYang->GetComponent<YinYang>()->Setting(GetComponent<Transform>(), Vector2(15.0f, -5.0f));
		}
		
	}
}