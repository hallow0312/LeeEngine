#pragma once
#include"SComponent.h"
#include"../Resource/SAnimation.h"
#include"STexture.h"
namespace Sichun
{
	class Animator : public Component
	{
		using Base = Component;
	public:
		Animator();
		~Animator();
		virtual void Initialize()override;
		virtual void Update()override;
		virtual void LateUpdate()override;
		virtual void Render(HDC hdc)override;

		void PlayActiveAnimation();
		void CreateAnimation(const std::wstring& name,
			std::shared_ptr<Sichun::Graphics::Texture>spriteSheet,
			Vector2 leftTop,
			Vector2 size,
			UINT spriteLength, 
			float duration);

		std::shared_ptr<Animation>FindAnimation(const std::wstring& name);

		void  PlayAnimation(const std::wstring& name, bool loop= true );


	private:
		std::map<std::wstring, std::shared_ptr<Animation>>_animations;
		std::shared_ptr<Animation>_activeAnimation;
		bool _isLoop;
	};

	
}