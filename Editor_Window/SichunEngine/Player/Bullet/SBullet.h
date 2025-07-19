#pragma once
#include"Component/SMonobehaviour.h"

namespace  Sichun
{
	class Bullet :public Monobehaviour
	{
	public:

		virtual void Initialize()override;
		virtual void Update()override;
		virtual void LateUpdate()override;
		virtual void Render(HDC hdc)override;

	private:

	

	};

}

