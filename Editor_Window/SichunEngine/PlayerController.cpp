#include "PlayerController.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Common/STime.h"
#include"GameObject/GameObject.h"
#include"Component/SComponent.h"
#include"Component/SAnimator.h"
namespace Sichun
{
	PlayerController::PlayerController():_isMove(false),_state(CharacterState::Idle)
	{
		
	}

	PlayerController::~PlayerController() 
	{
	}

	void PlayerController ::Initialize()
	{
	
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
		PlayMoveAnimation();
	}

	void PlayerController::MoveVertical(int vertical,Vector2& dir)
	{

		if (vertical < 0)
		{
			dir.y = -1;
			
		}
		else if (vertical > 0)
		{
			dir.y = 1;
		}
		PlayIdleAnimation();
	}

	void PlayerController::MoveDiagonal(int horizontal,int vertical,Vector2& dir)
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
		PlayMoveAnimation();
	}

	void PlayerController::Move()
	{
		std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
		if (!transform) return;

		Vector2 pos = transform->GetPos();
		Vector2 scale = transform->GetScale();

		float speed = 180.0f;
		float dt = Time::DeltaTime();

		Vector2 inputDir = Vector2::Zero;

		int horizontal = InputManager::GetAxis("Horizontal");
		int vertical = InputManager::GetAxis("Vertical");

		if(horizontal!=0&&vertical!=0)
		{
			 MoveDiagonal(horizontal, vertical, inputDir);
		}
		else if (horizontal != 0 || vertical != 0)
		{
			if (horizontal != 0)
				MoveHorizotnal(horizontal,inputDir);
			else
				MoveVertical(vertical,inputDir);
		}

	
		if (inputDir.x == 0 && inputDir.y == 0)
		{
			PlayIdleAnimation();
		}
		else
		{
			inputDir.Normalize();
			pos += inputDir * speed * dt;
		}

		// ÁÂ¿ì ¹ÝÀü
		if (inputDir.x > 0 && scale.x > 0)
			scale.x *= -1;
		else if (inputDir.x < 0 && scale.x < 0)
			scale.x *= -1;

		transform->SetPos(pos);
		transform->SetScale(scale);
	}

	void PlayerController::Temp()
	{
		int a = 10;
	}


	void PlayerController::PlayAnimation(const std::wstring& name, bool loop)
	{
		if (_animator == nullptr)_animator = GetOwner()->GetComponent<Animator>();
		if (_animator->IsPlayingAnimation(name))return;
		_animator->PlayAnimation(name,loop);
	}

	void PlayerController::PlayIdleAnimation()
	{
		if (_isMove)_isMove = false;
		if (_isIdle)
			PlayAnimation(L"ReimuIdle");
		else
		{
			if (_animator->IsCompleteAnimation())
			{
				_isIdle = true;
				return;
			}
			PlayAnimation(L"ReimuIdleStart", false);
		}
		
	}

	void PlayerController::PlayMoveAnimation()
	{
		_isIdle = false;
		if(_isMove)
		PlayAnimation(L"ReimuMoveHorizontal");
		else
		{
			if (_animator->IsCompleteAnimation())
			{
				_isMove = true;
				return;
			}
			PlayAnimation(L"ReimuMoveStart",false);
		}
	}
	

	
}
