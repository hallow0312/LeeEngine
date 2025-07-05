#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"

namespace  Sichun 
{
	class PlayerMovement : public Monobehaviour
	{ //PlayerCharacter
	public:
		PlayerMovement();
		~PlayerMovement();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
		void Move();
	private:
		
	};
}

