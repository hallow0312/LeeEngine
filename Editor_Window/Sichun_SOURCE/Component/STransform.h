#pragma once
#include"SComponent.h"

namespace Sichun 
{
	using namespace math;
	
	class Transform : public Component
	{
		using Base = Component;
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;
		void SetPos(Vector2 pos) { _pos = pos; }
		void SetScale(Vector2 scale) { _scale = scale; }
		void SetRotation(float rotation) { _rotation = rotation; }

		float GetRotation() { return _rotation; }

		Vector2 GetPos() { return _pos; }
		Vector2 GetScale() { return _scale; }
	
	private:
		Vector2 _pos;
		Vector2 _scale;
		float _rotation;
	};
}
