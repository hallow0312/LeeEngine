#include "SAnimation.h"
#include"../Common/STime.h"
#include"../Component/STransform.h"
#include"../GameObject/GameObject.h"
#include"../Renderer/SRenderer.h"
#include"../Component/SCamera.h"
#include"../Component/SAnimator.h"
namespace Sichun {
	Animation::Animation():Base(Enum::ResourceType::Animation)
		, _texture(nullptr)
		,_sprites{}
		,_index(0)
		,_time(0.0f)
		,_isComplete(false)
	{
		
	}

	
	Animation::~Animation()
	{
	}
	void Animation::Update()
	{
		if (_isComplete)return;
		_time += Time::DeltaTime();

		if (_sprites[_index].Duration <= _time)
		{
			if (_index < _sprites.size()-1)
			{
				_time = 0;
				_index++;
			}
			else
			{
				_isComplete = true;
			}
		}
	}
	void Animation::Render(HDC hdc)
	{
		if (_texture == nullptr)
			return;
		std::shared_ptr<Sichun::Animator> animator = GetAnimator();
		if (!animator) return;
		std::shared_ptr<GameObject> obj = animator->GetOwner();
		if (!obj) return;
		std::shared_ptr<Transform> transform = obj->GetComponent<Transform>();
		if (!transform) return;
		

		Graphics::Texture::TextureType type = _texture->GetTextureType();
		if (type == Graphics::Texture::TextureType::BMP)
		{
			SettingBMP(hdc, transform);
		}
		else if (type == Graphics::Texture::TextureType::PNG)
		{
			SettingPNG(hdc,transform);
		}
		

	}

	void Animation::SettingPNG(HDC hdc, std::shared_ptr<Transform> transform)
	{
		Vector2 pos = transform->GetLocalPos();
		Vector2 scale = transform->GetLocalScale();
		float rotation = transform->GetLocalRotation();

		if (Renderer::_mainCamera)
			Renderer::_mainCamera->CalculatePosition(pos);

		Sprite sprite = _sprites[_index];

		Gdiplus::Graphics graphics(hdc);
	
		graphics.TranslateTransform(pos.x, pos.y);
		if (scale.x < 0.0f)
		{
			graphics.ScaleTransform(-1.0f, 1.0f); 
		}

		if (rotation != 0.0f)
		{
			graphics.RotateTransform(rotation);
		}
		Gdiplus::Rect destRect(
			(-sprite.Size.x / 2.0f),
			(-sprite.Size.y / 2.0f),
			(sprite.Size.x),
			(sprite.Size.y)
		);

		
		Gdiplus::ImageAttributes imgAtt;
		imgAtt.SetColorKey(Gdiplus::Color(100, 100, 100), Gdiplus::Color(255, 255, 255));

		graphics.DrawImage(
			_texture->GetImage().get(),
			destRect,
			(sprite.LeftTop.x),
			(sprite.LeftTop.y),
			(sprite.Size.x),
			(sprite.Size.y),
			Gdiplus::UnitPixel
			
		);
	}
	void Animation::SettingBMP(HDC hdc, std::shared_ptr<Transform> transform)
	{
		Vector2 pos = transform->GetLocalPos();
		Vector2 scale = transform->GetLocalScale();
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 125; // 0(transparent) ~ 255(Opaque)

		Sprite sprite = _sprites[_index];
		HDC imgHdc = _texture->GetHdc();

		AlphaBlend(hdc
			, pos.x - (sprite.Size.x / 2.0f), pos.y - (sprite.Size.y / 2.0f)
			, sprite.Size.x * scale.x
			, sprite.Size.y * scale.y
			, imgHdc
			, sprite.LeftTop.x
			, sprite.LeftTop.y
			, sprite.Size.x
			, sprite.Size.y
			, func);
	}
	void Animation::CreateAnimation(const std::wstring& name, std::shared_ptr<Sichun::Graphics::Texture> spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset ,UINT spriteLength, float duration)
	{
		_texture = spriteSheet;
	
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.LeftTop.x = leftTop.x  + size.x *  i;
			sprite.LeftTop.y = leftTop.y;
			sprite.Size = size;
			sprite.Offset = offset;
			sprite.Duration = duration;
			_sprites.push_back(sprite);
		}
				
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Reset()
	{
		_time = 0.0f;
		_index = 0;
		_isComplete = false;
	}
}