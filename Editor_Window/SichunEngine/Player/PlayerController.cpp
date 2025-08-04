#include "PlayerController.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Common/STime.h"
#include"GameObject/GameObject.h"
#include"Component/SComponent.h"
#include"Component/SAnimator.h"
#include"GameObject/SObject.h"
namespace Sichun
{
	PlayerController::PlayerController() :_state(CharacterState::Idle), _animation(nullptr)
	{

	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::Initialize()
	{
		if (_animation == nullptr)_animation = GetOwner()->GetComponent<PlayerAnimation>();
	}

	void PlayerController::Update()
	{
		
		Move();
	}

	void PlayerController::LateUpdate()
	{
	}

	void PlayerController::Render(HDC hdc)
	{
	}
	
	void PlayerController::CheckState()
	{
	}

	void PlayerController::MoveHorizotnal(int horizontal, Vector2& dir)
	{
		if (horizontal < 0)
		{
			dir.x = -1;

		}
		else if (horizontal > 0)
		{
			dir.x = 1;
		}
		if (_animation == nullptr)_animation = GetOwner()->GetComponent<PlayerAnimation>();
		_animation->PlayMoveAnimation();
	}

	void PlayerController::MoveVertical(int vertical, Vector2& dir)
	{

		if (vertical < 0)
		{
			dir.y = -1;

		}
		else if (vertical > 0)
		{
			dir.y = 1;
		}
		if (_animation == nullptr)_animation = GetOwner()->GetComponent<PlayerAnimation>();
		_animation->PlayIdleAnimation();
	}

	void PlayerController::MoveDiagonal(int horizontal, int vertical, Vector2& dir)
	{
		if (horizontal < 0)
		{
			dir.x = -1;

		}
		else if (horizontal > 0)
		{
			dir.x = 1;
		}
		if (vertical < 0)
		{
			dir.y = -1;
		}
		else if (vertical > 0)
		{
			dir.y = 1;
		}
		
		if (_animation == nullptr)_animation = GetOwner()->GetComponent<PlayerAnimation>();
		_animation->PlayMoveAnimation();
	}

	void PlayerController::Move()
	{
		std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
		if (!transform) return;

		Vector2 pos = transform->GetLocalPos();
		Vector2 scale = transform->GetLocalScale();

		
		float dt = Time::DeltaTime();

		Vector2 inputDir = Vector2::Zero;

		int horizontal = InputManager::GetAxis("Horizontal");
		int vertical = InputManager::GetAxis("Vertical");

		if (horizontal != 0 && vertical != 0)
		{
			MoveDiagonal(horizontal, vertical, inputDir);
		}
		else if (horizontal != 0 || vertical != 0)
		{
			if (horizontal != 0)
				MoveHorizotnal(horizontal, inputDir);
			else
				MoveVertical(vertical, inputDir);
		}


		if (inputDir.x == 0 && inputDir.y == 0)
		{
			if (_animation == nullptr)_animation = GetOwner()->GetComponent<PlayerAnimation>();
			_animation->PlayIdleAnimation();
		}
		else
		{
			inputDir=inputDir.Normalize();
			pos += inputDir * _speed * dt;
		}

		
		if (inputDir.x > 0 && scale.x > 0)
			scale.x *= -1;
		else if (inputDir.x < 0 && scale.x < 0)
			scale.x *= -1;

		transform->SetPosition(pos);
		transform->SetScale(scale);
	}

	void PlayerController::OnTriggerEnter(std::shared_ptr<Collider> other)
	{
 		int a = 10;
	}

	void PlayerController::OnTriggerStay(std::shared_ptr<Collider> other)
	{
		int a = 10;
	}

	void PlayerController::OnTriggerExit(std::shared_ptr<Collider> other)
	{
		int a = 10;

	}

	


}

	

