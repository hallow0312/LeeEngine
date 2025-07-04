#pragma once
#include"SComponent.h"

namespace Sichun 
{
	struct Pos
	{
		int _x;
		int _y;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPos(int x, int y) { _x = x; _y = y; }
		int GetX() { return _x; }
		int GetY() { return _y; }

	private:
		int _x;
		int _y;
	};
}
