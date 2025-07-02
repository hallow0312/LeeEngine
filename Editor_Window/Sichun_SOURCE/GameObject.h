#pragma once
#include"CommonInclude.h"
//ue ¿¡¼­´Â actor
namespace Sichun
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float  x, float y)
		{
			_x = x;
			_y = y;
		}
		float GetPositionX()
		{
			return _x;
		}
		float GetPositionY()
		{
			return _y;
			
		}
	private:

		//gameObejct Coord ; 
		float _x;
		float _y;

	};
}
