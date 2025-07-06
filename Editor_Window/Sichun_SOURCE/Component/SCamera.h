#pragma once
#include"SComponent.h"
#include"../GameObject/GameObject.h"
namespace Sichun
{
	
	class Camera : public Component
	{
		using Base = Component;
	public:
		math::Vector2 CalculatePosition(math::Vector2 pos) 
		{
			return pos - _distance;
		};
		Camera();
		~Camera();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;

	private:
		math::Vector2 _distance ;
		math::Vector2 _resolution;
		math::Vector2 _lookPosition;
		std::shared_ptr<GameObject>_target;

	};
}