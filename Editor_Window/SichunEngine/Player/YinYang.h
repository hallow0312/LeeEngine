#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"

namespace Sichun
{
	class YinYang : public Monobehaviour
	{
	public:
		YinYang();
		~YinYang();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
		void Move();
		void Rotate();
	private:
		float _value = 0.0f;
	};

}
