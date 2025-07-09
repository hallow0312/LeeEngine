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
		 if (_activeAnimation)_activeAnimation->Render(hdc);
	 }
	 void Animator::PlayActiveAnimation()
	 {
		 _activeAnimation->Update();
		 if (_activeAnimation->IsComplete() && _isLoop == true)
		 {
			 _activeAnimation->Reset();  
		 }
	 }
	 void Animator::CreateAnimation(
		 const std::wstring& name, 
		 std::shared_ptr<Sichun::Graphics::Texture> spriteSheet, 
		 Vector2 leftTop, 
		 Vector2 size,
		 Vector2 offset,
		 UINT spriteLength, 
		 float duration)
	 {
		 std::shared_ptr<Animation>animation = nullptr;
		 animation = FindAnimation(name);
		 if (animation != nullptr)return;

		 animation = std::make_shared<Animation>();
		 animation->CreateAnimation(name, spriteSheet, leftTop, size, offset, spriteLength, duration);
		 animation->SetAnimator(shared_from_this());
		 _animations.insert(std::make_pair(name, animation));
	 }
	 std::shared_ptr<Animation> Animator::FindAnimation(const std::wstring& name)
	 {
		 auto iter = _animations.find(name);
		 if (iter != _animations.end())return iter->second;
		 
		 return nullptr;

	 }
	 void Animator::PlayAnimation(const std::wstring& name, bool loop)
	 {
		 std::shared_ptr<Animation>animation = FindAnimation(name);
		 if (animation == nullptr)return;

		 _activeAnimation = animation;
		 _activeAnimation->Reset();
		 _isLoop = loop;
	 }
}


