#pragma once
#include"SCollider.h"

namespace Sichun 
{
	class CircleCollider2D:public Collider
	{
		CircleCollider2D();
		~CircleCollider2D();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		Vector2  GetOffset() { return _offset;}
		void SetOffset(Vector2 offset) { _offset = offset; }
	private:
		Vector2 _offset;
	};
}

