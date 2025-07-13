#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"

namespace  Sichun 
{
	class Animator;
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
		void Temp();
	private:
		CharacterState _state;
		std::shared_ptr<Animator>_animator;

	
		bool _isMove;
		bool _isIdle;

	private:
		void PlayAnimation(const std::wstring& name, bool loop = true);
		void PlayIdleAnimation();
		void PlayMoveAnimation();
		void CheckState();

		void MoveHorizotnal(int horizotnal, Vector2& dir);
		void MoveVertical(int vertical, Vector2& dir);
		void MoveDiagonal(int horizontal, int vertical, Vector2& dir);
	};
}

