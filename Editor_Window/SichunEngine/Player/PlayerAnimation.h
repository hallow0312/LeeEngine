#pragma once
#include"Component/SMonobehaviour.h"

namespace Sichun 
{
	class Animator;
	class PlayerAnimation : public Monobehaviour
	{
	public:
		PlayerAnimation();
		~PlayerAnimation();
		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;

		void PlayAnimation(const std::wstring& name, bool loop = true);
		void PlayIdleAnimation();
		void PlayMoveAnimation();
	private:
		std::shared_ptr<Animator>_animator;
		bool _isMove;
		bool _isIdle;

	};
}

