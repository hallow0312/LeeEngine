#pragma once
#include"SCollider.h"

namespace Sichun {
	class BoxCollider2D :public Collider
	{
		using Super = Collider;
	public:

		BoxCollider2D();
		~BoxCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		Vector2 _size;
	};
}

