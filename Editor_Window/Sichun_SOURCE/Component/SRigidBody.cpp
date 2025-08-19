#include "SRigidBody.h"
#include "../Common/STime.h"
#include "../Component/STransform.h"
#include "../GameObject/GameObject.h"

namespace Sichun
{
	RigidBody::RigidBody()
		: Super(Enum::ComponentType::RigidBody)
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

        CalculateGravityVelocity();

        LimitMaxSpeed();

        _velocity += _accel * Time::DeltaTime();

        if (!(_velocity == Vector2::Zero))
        {
            
            Vector2 friction = -_velocity;
            friction = friction.Normalize() * _friction * _mass * Time::DeltaTime();

            
            if (_velocity.Length() <= friction.Length())
            {
               
                _velocity = Vector2::Zero;
            }
            else
            {
                _velocity += friction;
            }
        }

       
        auto transform = GetOwner()->GetComponent<Transform>();
        Vector2 pos = transform->GetWorldPosition();
        pos += _velocity * Time::DeltaTime();
        transform->SetPosition(pos);

        
        _force.Clear();
    }

    void RigidBody::ApplyFriction()
    {
        if (_velocity.Length() > 0.0f)
        {
            
          
            Vector2 frictionForce = -_velocity.Normalize() * _friction * Time::DeltaTime();

          
            if (frictionForce.Length() > _velocity.Length())
            {
                _velocity = Vector2::Zero;
            }
            else
            {
                _velocity += frictionForce;
            }
        }
    }

    void RigidBody::CalculateGravityVelocity()
    {
        Vector2 gravityDir = _gravity.Normalize();

        if (_isGround)
        {
            float dot = Vector2::Dot(_velocity, gravityDir);
            _velocity -= gravityDir * dot;
        }
        else
        {
            _velocity += _gravity * Time::DeltaTime();
        }
    }

    void RigidBody::LimitMaxSpeed()
    {
        Vector2 gravityDir = _gravity.Normalize();
        float dot = Vector2::Dot(_velocity, gravityDir);
        Vector2 gravityVel = gravityDir * dot;

        Vector2 sideVel = _velocity - gravityVel;

        // 중력 방향 제한
        if (gravityVel.Length() > _limitedVelocity.y)
            gravityVel = gravityDir * _limitedVelocity.y;

        // 수평 방향 제한
        if (sideVel.Length() > _limitedVelocity.x)
            sideVel = sideVel.Normalize() * _limitedVelocity.x;

        _velocity = gravityVel + sideVel;
    }
}
