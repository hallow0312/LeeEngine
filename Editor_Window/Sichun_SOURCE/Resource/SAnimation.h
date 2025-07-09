#pragma once
#include"SResource.h"
#include"../Component/STexture.h"

namespace Sichun
{
	class Animator;
	class Animation : public Resource
	{
		using Base = Resource;
	public:
		struct Sprite
		{
			Vector2 LeftTop;
			Vector2 Size;
			Vector2 Offset;
			float Duration;
			Sprite():
				LeftTop(Vector2::Zero),Size(Vector2::Zero),Offset(Vector2::Zero),Duration(0.0f)
			{

			}
		};
		Animation();
		~Animation();

		void Update();
		void Render(HDC hdc);

		void SettingPNG(HDC hdc, Vector2 pos);
		void SettingBMP(HDC hdc, Vector2 pos);

		void CreateAnimation(const std::wstring& name,
			std::shared_ptr<Sichun::Graphics::Texture>spriteSheet,
			Vector2 leftTop,
			Vector2 size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		HRESULT Load(const std::wstring& path)override;

		void Reset();
		bool IsComplete() { return _isComplete; }
		void SetAnimator(std::shared_ptr<Animator>animator) { _animator = animator; }
		std::shared_ptr<Animator>GetAnimator() { return _animator.lock(); }

	private:


		std::weak_ptr<Animator> _animator;
		std::shared_ptr<Graphics::Texture>_texture;
		std::vector<Sprite>_sprites;

		int _index;
		float _time;
		bool _isComplete;
	};

}