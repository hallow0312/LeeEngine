#pragma once
#include"SComponent.h"
#include"../Resource/SAnimation.h"
#include"STexture.h"
namespace Sichun
{
	class Animator : public Component, public std::enable_shared_from_this<Animator>
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
		void CreateAnimation(
			const std::wstring& name,
			std::shared_ptr<Sichun::Graphics::Texture> spriteSheet,
			Vector2 leftTop,
			Vector2 size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		std::shared_ptr<Animation>FindAnimation(const std::wstring& name);

		void  PlayAnimation(const std::wstring& name, bool loop= true );
		bool IsPlayingAnimation(const std::wstring& name);

	private:
		std::map<std::wstring, std::shared_ptr<Animation>>_animations;
		std::shared_ptr<Animation>_activeAnimation;
		bool _isLoop;
	};

	
}