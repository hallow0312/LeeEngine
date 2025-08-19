#include "PlayerController.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Common/STime.h"
#include"GameObject/GameObject.h"
#include"Component/SComponent.h"
#include"Component/SAnimator.h"
#include"GameObject/SObject.h"
#include"Component/SRigidBody.h"
namespace Sichun
{
	PlayerController::PlayerController() :_state(CharacterState::Idle), 
		_animation(nullptr)
	
	{

	}

	PlayerController::~PlayerController()
	{
	}

	void PlayerController::Initialize()
	{
		_animation = GetOwner()->GetComponent<PlayerAnimation>();
		_rb = GetOwner()->GetComponent<RigidBody>();
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
		
		_animation->PlayMoveAnimation();
	}

	void PlayerController::Move()
{
    std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
    if (!transform) return;

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

    if (inputDir == Vector2::Zero)
    {
        if (_animation == nullptr)
            _animation = GetOwner()->GetComponent<PlayerAnimation>();
        _animation->PlayIdleAnimation();

     
       // _rb->SetVelocity(Vector2::Zero);
    }
    else
    {
        inputDir = inputDir.Normalize();

        // 힘 또는 속도 적용
        //_rb->AddForce(inputDir * _moveForce);   // 힘 방식
        _rb->AddForce(inputDir * _speed);     // 속도 직접 세팅 방식
    }

    // 좌우 반전은 스케일 그대로 유지
    Vector2 scale = transform->GetLocalScale();
    if (inputDir.x > 0 && scale.x > 0)
        scale.x *= -1;
    else if (inputDir.x < 0 && scale.x < 0)
        scale.x *= -1;

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

	

