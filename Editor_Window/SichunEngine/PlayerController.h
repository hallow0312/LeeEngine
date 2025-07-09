#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"

namespace  Sichun 
{
	class PlayerController : public Monobehaviour
	{ //PlayerCharacter
	public:
		enum class CharacterState
		{
			Idle,
			Left,
			Right,
			Up,
			Down,
		
		};

		PlayerController();
		~PlayerController();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
		void Move();
		
		void CheckState();

	private:
		CharacterState _state;
	};
}

