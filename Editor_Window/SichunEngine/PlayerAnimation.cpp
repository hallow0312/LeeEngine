#include "PlayerAnimation.h"
#include"Component/SAnimator.h"
#include"GameObject/GameObject.h"
namespace Sichun
{
	PlayerAnimation::PlayerAnimation():_isMove(false),_isIdle(false),_animator{}
	{
	}
	PlayerAnimation::~PlayerAnimation()
	{
	}
	void PlayerAnimation::Initialize()
	{
		if(_animator==nullptr)
			_animator=GetOwner()->GetComponent<Animator>();
	}
	
	void PlayerAnimation::Update()
	{
	}
	void PlayerAnimation::LateUpdate()
	{
	}
	void PlayerAnimation::Render(HDC hdc)
	{
	}
	void PlayerAnimation::PlayAnimation(const std::wstring& name, bool loop)
	{
		if (_animator == nullptr)_animator = GetOwner()->GetComponent<Animator>();
		if (_animator->IsPlayingAnimation(name))return;
		_animator->PlayAnimation(name, loop);
	}
	void PlayerAnimation::PlayIdleAnimation()
	{
		if (_isMove)_isMove = false;
		if (_isIdle)
			PlayAnimation(L"ReimuIdle");
		else
		{
			if (!_animator)
				_animator = GetOwner()->GetComponent<Animator>();
			if (_animator->IsCompleteAnimation())
			{
				_isIdle = true;
				return;
			}
			PlayAnimation(L"ReimuIdleStart", false);
		}
	}
	void PlayerAnimation::PlayMoveAnimation()
	{
		_isIdle = false;
		if (_isMove)
			PlayAnimation(L"ReimuMoveHorizontal");
		else
		{
			if (_animator->IsCompleteAnimation())
			{
				_isMove = true;
				return;
			}
			PlayAnimation(L"ReimuMoveStart", false);
		}
	}
}