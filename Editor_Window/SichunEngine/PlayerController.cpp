#include "PlayerController.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Common/STime.h"
#include"GameObject/GameObject.h"
#include"Component/SComponent.h"
namespace Sichun
{
	PlayerController::PlayerController()
	{
		_state = CharacterState::Idle;
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

	void PlayerController::Move()
	{
		std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
		if (!transform) return;

		Vector2 pos = transform->GetPos();
		Vector2 scale = transform->GetScale();

		float speed = 100.0f;
		float dt = Time::DeltaTime();

		// 입력값을 벡터로 저장
		Vector2 inputDir = Vector2::Zero;

		int horizontal = InputManager::GetAxis("Horizontal");
		int vertical = InputManager::GetAxis("Vertical");

		if (horizontal < 0)
			inputDir.x = -1;
		else if (horizontal > 0)
			inputDir.x = 1;

		if (vertical < 0)
			inputDir.y = -1;
		else if (vertical > 0)
			inputDir.y = 1;

		// 방향 벡터 정규화 (대각선 이동 보정)
		if (inputDir.x != 0 || inputDir.y != 0)
			inputDir.Normalize();

		pos += inputDir * speed * dt;

		// 좌우 반전 처리
		if (inputDir.x < 0 && scale.x > 0)
			scale.x *= -1;
		else if (inputDir.x > 0 && scale.x < 0)
			scale.x *= -1;

		transform->SetPos(pos);
		transform->SetScale(scale);
	}
	

	
}
