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
		Vector2 GetPos() { return _pos; }

	private:
		Vector2 _pos;
	};
}
