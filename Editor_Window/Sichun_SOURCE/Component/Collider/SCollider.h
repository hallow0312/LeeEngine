#pragma once
#include"../SComponent.h"
namespace Sichun
{
	class Collider :public Component
	{
		using Super = Component;
	public:
		Collider();
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void  SetOffset(Vector2 offset) { _offset = offset; }
		Vector2 GetOffset() { return _offset; }
	private:
	
		Vector2 _offset;
	};
}