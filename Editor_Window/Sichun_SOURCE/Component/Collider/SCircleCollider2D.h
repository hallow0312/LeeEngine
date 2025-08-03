#pragma once
#include"SCollider.h"

namespace Sichun 
{
	class CircleCollider2D:public Collider
	{
		using Super = Collider;
	public:

		CircleCollider2D();
		~CircleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		
	private:
		float  _radius;
	};
}

