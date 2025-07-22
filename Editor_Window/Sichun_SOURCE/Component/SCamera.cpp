#include "SCamera.h"
#include"GameObject/GameObject.h"
#include"STransform.h"
#include"../S_Application.h"

extern  Sichun::Application _application;
namespace Sichun
{
	Camera::Camera():
		Base(Enum::ComponentType::Camera),_distance(Vector2::One),_resolution(Vector2::Zero)
		,_lookPosition(Vector2::One),_target(nullptr)
	{
	}
	Camera::~Camera()
	{
		_resolution.x = _application.GetWidth();
		_resolution.y = _application.GetHeight();

	}
	void Camera::Initialize()
	{
	}
	void Camera::Update()
	{
		if (_target)
		{
			std::shared_ptr<Transform>transform = _target->GetComponent<Transform>();
			_lookPosition = transform->GetLocalPos();
		}
		else 
		{
			std::shared_ptr<Transform> cameraTransform = GetOwner()->GetComponent<Transform>();
			_lookPosition = cameraTransform->GetLocalPos();
		}
		_distance = _lookPosition - (_resolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}