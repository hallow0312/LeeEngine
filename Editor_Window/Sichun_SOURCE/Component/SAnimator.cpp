#include "SAnimator.h"
#include"Component/STexture.h"
#include"Resource/SResources.h"
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
		
		 if (_activeAnimation->IsComplete() )
		 {
			 CallCompleteEvent();

			 if( _isLoop)
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
		 animation->SetName(name);
		
		 _events.insert(std::make_pair(name, Events{}));
		 _animations.insert(std::make_pair(name, animation));
	 }

	 void Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration)
	 {
		 std::shared_ptr<Animation>  animation = nullptr;
		 animation = FindAnimation(name);
		 if (animation != nullptr)return;

		 std::filesystem::path fs(path);
		 std::vector<std::shared_ptr<Graphics::Texture>>images = {};
		 int fileCount = 0;
		 for (auto& p : std::filesystem::recursive_directory_iterator(fs))
		 {
			 std::wstring fileName = p.path().filename();
			 std::wstring fullName = p.path();
			 std::shared_ptr<Graphics::Texture>texture = Resources::Load<Graphics::Texture>(fileName, fullName);
			 images.push_back(texture);
			 fileCount++;
		 }
		 UINT sheetWidth = images[0]->GetWidth() * FileDispositionInfo;
		 UINT sheetHeight = images[0]->GetHeight();

		 std::shared_ptr<Graphics::Texture> spriteSheet = Graphics::Texture::Create(name, sheetWidth, sheetHeight);
		 UINT imageWidth = images[0]->GetWidth();
		 UINT imageHeight = images[0]->GetHeight();

		 for (size_t i = 0; i < images.size(); i++)
		 {
			 BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0, 
				 imageWidth, imageHeight,
				 images[i]->GetHdc(), 0, 0, SRCCOPY);
		 }
		 CreateAnimation(name, spriteSheet, Vector2::One, Vector2(imageWidth, imageHeight), offset, fileCount, duration);
	 }

	 std::shared_ptr<Animation> Animator::FindAnimation(const std::wstring& name)
	 {		 auto iter = _animations.find(name);
		 if (iter != _animations.end())return iter->second;
		 
		 return nullptr;

	 }
	 void Animator::PlayAnimation(const std::wstring& name, bool loop)
	 {
		 std::shared_ptr<Animation>animation = FindAnimation(name);
		 if (animation == nullptr)return;

		 CallEndEvent();

		 _activeAnimation = animation;
		
		 CallStartEvent();
		 
		 _activeAnimation->Reset();
		 _isLoop = loop;
	 }

	 Animator::Events* Animator::FindEvents(const std::wstring& name)
	 {
		 auto iter = _events.find(name);
		 if (iter != _events.end()) return &iter->second;
		 return nullptr;
	 }

	 void Animator::CallStartEvent()
	 {
		 if (!_activeAnimation) return;
		 if (Events* event = FindEvents(_activeAnimation->GetName()))
			 event->StartEvent();
	 }

	 void Animator::CallCompleteEvent()
	 {
		 if (!_activeAnimation) return;
		 if (Events* event = FindEvents(_activeAnimation->GetName()))
			 event->CompleteEvent();
	 }

	 void Animator::CallEndEvent()
	 {
		 if (!_activeAnimation) return;
		 if (Events* event = FindEvents(_activeAnimation->GetName()))
			 event->EndEvent();
	 }

	 std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	 {
		 return _events[name].StartEvent.Action;
	 }

	 std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	 {
		 return _events[name].CompleteEvent.Action;
	 }

	 std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	 {
		 return _events[name].EndEvent.Action;
	 }
	 bool Animator::IsPlayingAnimation(const std::wstring& name)
	 {
		 std::shared_ptr<Animation>animation = FindAnimation(name);
		 
		 return animation == _activeAnimation;
	 }
}


