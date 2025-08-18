#pragma once
#include"SComponent.h"

namespace Sichun {
	class RigidBody:public Component
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
		void SetGravity(float gravity) { _gravity = gravity; }
		
		void CalculateMove();

		void  AddForce(Vector2 force) { _force = force; }
	private:
		float _mass;
		float _friction;
		float _gravity;

		Vector2 _force;
		Vector2 _accel;
		Vector2 _velocity;
	};
}

