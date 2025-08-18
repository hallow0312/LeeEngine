#pragma once
#include"..//Sichun_SOURCE//Component/SMonobehaviour.h"
#include"PlayerAnimation.h"
namespace  Sichun 
{
	class Animator;
	class RigidBody;
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

		void OnTriggerEnter(std::shared_ptr<Collider>other)override;
		void OnTriggerStay(std::shared_ptr<Collider>other)override;
		void OnTriggerExit(std::shared_ptr<Collider>other)override;
	private:
		CharacterState _state;
		
		std::shared_ptr<PlayerAnimation>_animation;
	
		
	private:
		float _deathTime=10.0f;
		 
		float _speed =180.0f;
		void CheckState();

		void MoveHorizotnal(int horizotnal, Vector2& dir);
		void MoveVertical(int vertical, Vector2& dir);
		void MoveDiagonal(int horizontal, int vertical, Vector2& dir);
	};
}

