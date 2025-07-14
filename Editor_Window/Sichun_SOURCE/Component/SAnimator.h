#pragma once
#include "SComponent.h"
#include "../Resource/SAnimation.h"
#include "STexture.h"

namespace Sichun
{
	class Animator : public Component, public std::enable_shared_from_this<Animator>
	{
		using Base = Component;
	public:
		struct Event
		{
			void operator=(std::function<void()> action)
			{
				Action = std::move(action);
			}
			void operator()()
			{
				if (Action) Action();
			}
			std::function<void()> Action;
		};
		struct Events
		{
			Event StartEvent;
			Event CompleteEvent;
			Event EndEvent;
		};

		Animator();
		~Animator();
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void LateUpdate() override;
		virtual void Render(HDC hdc) override;

		void PlayActiveAnimation();
		void CreateAnimation(const std::wstring& name,
			std::shared_ptr<Sichun::Graphics::Texture> spriteSheet,
			Vector2 leftTop, Vector2 size, Vector2 offset,
			UINT spriteLength, float duration);

		std::shared_ptr<Animation> FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

		void CallStartEvent();
		void CallCompleteEvent();
		void CallEndEvent();

		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsPlayingAnimation(const std::wstring& name);
		bool IsCompleteAnimation() { 
			return _activeAnimation->IsComplete();
		}

	private:
		std::map<std::wstring, std::shared_ptr<Animation>> _animations;
		std::shared_ptr<Animation> _activeAnimation;
		bool _isLoop;

		std::map<std::wstring, Events> _events; // ¹Ù²ï ºÎºÐ
	};
}
