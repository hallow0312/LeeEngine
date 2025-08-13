#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"

namespace Sichun {
	class CameraController : public Monobehaviour
	{
	public:
		CameraController();
		~CameraController();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
		void Move();

	private:
	};
}

