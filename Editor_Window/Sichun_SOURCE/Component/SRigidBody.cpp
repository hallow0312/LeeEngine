#include "SRigidBody.h"
#include"../Common/STime.h"
#include"../Component/STransform.h"
#include"../GameObject/GameObject.h"
namespace Sichun
{
	RigidBody::RigidBody() :Super(Enum::ComponentType::RigidBody)
	,_mass(1.0f)
	,_friction(50.0f)
	,_force(Vector2::Zero)
	,_velocity(Vector2::Zero)
	,_gravity(9.8f)
	{
	}
	RigidBody::~RigidBody()
	{
	}
	void RigidBody::Initialize()
	{
	}
	void RigidBody::Update()
	{
		CalculateMove();
	}
	void RigidBody::LateUpdate()
	{
	}
	void RigidBody::Render(HDC hdc)
	{
	}
	void RigidBody::CalculateMove()
	{
		_accel = _force / _mass;

	
		if (!(_velocity == Vector2::Zero))
		{
			Vector2 frictionDir = -_velocity.Normalize();
			Vector2 friction = frictionDir * _friction; 
			_accel += friction / _mass;
		}

		_velocity += _accel * Time::DeltaTime();

		
		if (_velocity.Length() < 0.001f)
			_velocity = Vector2::Zero;

		auto transform = GetOwner()->GetComponent<Transform>();
		Vector2 pos = transform->GetWorldPosition();
		pos += _velocity * Time::DeltaTime();
		transform->SetPosition(pos);

		_force.Clear();
	}
}