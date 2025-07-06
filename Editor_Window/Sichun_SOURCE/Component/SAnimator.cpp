#include "SAnimator.h"


 namespace Sichun
{
	 Animator::Animator():Base(Enum::ComponentType::Animator)
		 ,_animations{}
		 ,_activeAnimation(nullptr)
		 ,_isLoop(false)
	 {
	 }

	 Animator::~Animator()
	 {
	 }

	 void Animator::Initialize()
	 {
	 }

	 void Animator::Update()
	 {
		 if (_activeAnimation)PlayActiveAnimation();
	 }

	 void Animator::LateUpdate()
	 {
	 }

	 void Animator::Render(HDC hdc)
	 {
	 }
	 void Animator::PlayActiveAnimation()
	 {
		 _activeAnimation->Update();
		 if (_activeAnimation->IsComplete() && _isLoop == true)
		 {
			 _activeAnimation->Reset();
		 }
	 }
	 void Animator::CreateAnimation(const std::wstring& name, std::shared_ptr<Sichun::Graphics::Texture> spriteSheet, Vector2 leftTop, Vector2 size, UINT spriteLength, float duration)
	 {

	 }
	 std::shared_ptr<Animation> Animator::FindAnimation(const std::wstring& name)
	 {
		 return std::shared_ptr<Animation>();
	 }
	 void Animator::PlayAnimation(const std::wstring& name, bool loop)
	 {
	 }
}


