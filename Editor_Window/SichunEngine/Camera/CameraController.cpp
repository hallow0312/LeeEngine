#include "CameraController.h"
#include"../SichunEngineHeader.h"
#include"Common/STime.h"
Sichun::CameraController::CameraController()
{
}

Sichun::CameraController::~CameraController()
{
}

void Sichun::CameraController::Initialize()
{
}

void Sichun::CameraController::Update()
{
	Move();
}

void Sichun::CameraController::LateUpdate()
{
}

void Sichun::CameraController::Render(HDC hdc)
{
}

void Sichun::CameraController::Move()
{
	const auto& tr = GetOwner()->GetComponent<Transform>();
	Vector2 pos = tr->GetWorldPosition();

	if (InputManager::GetKey(KeyCode::RIGHT))
	{
		pos.x += 100.0f * Time::DeltaTime();
	}
	if (InputManager::GetKey(KeyCode::LEFT))
	{
		pos.x -= 100.0f * Time::DeltaTime();
	}
	if (InputManager::GetKey(KeyCode::UP))
	{
		pos.y -= 100.0f * Time::DeltaTime();
	}
	if (InputManager::GetKey(KeyCode::DOWN))
	{
		pos.y += 100.0f * Time::DeltaTime();
	}
	tr->SetPosition(pos);
}
