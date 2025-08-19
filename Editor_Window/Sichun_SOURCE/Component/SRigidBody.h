#pragma once
#include "SComponent.h"

namespace Sichun {
	class RigidBody : public Component
	{
		using Super = Component;
	public:
		RigidBody();
		~RigidBody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void SetMass(float mass) { _mass = mass; }
		void SetFriction(float friction) { _friction = friction; }
		void SetGravity(Vector2 gravity) { _gravity = gravity; }
		void SetVelocity(Vector2 velocity) { _velocity = velocity; }

		Vector2 GetGravity() { return _gravity; }
		Vector2 GetVelocity() { return _velocity; }

		void CalculateMove();
		void AddForce(Vector2 force) { _force += force; }
		void ApplyFriction();
	private:
		bool _isGround = false;

		float _mass = 1.0f;
		float _friction = 10.0f;
		Vector2 _gravity = Vector2(0.0f, 9.8*2.0f);

		Vector2 _force = Vector2::Zero;
		Vector2 _accel = Vector2::One;
		Vector2 _velocity = Vector2::Zero;
		Vector2 _limitedVelocity = Vector2(200.0f, 1000.0f);

	private:
		void CalculateGravityVelocity();
		void LimitMaxSpeed();
	};
}
