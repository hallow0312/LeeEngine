#include "SSpriteRenderer.h"
#include"GameObject/GameObject.h"
#include"STransform.h"
#include"STexture.h"
namespace Sichun {
	SpriteRenderer::SpriteRenderer():Base(),_texture(nullptr), _size(Vector2::One)
	{
	}

	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		if (_texture == nullptr)assert(false); //need to texture setting

		std::shared_ptr<Transform> transform = GetOwner()->GetComponent<Transform>();
		math::Vector2 pos = transform->GetPos();

		if (_texture->GetTextureType() == Graphics::Texture::TextureType::BMP)
		{
			DrawBMP(pos, hdc);
		}
		else if (_texture->GetTextureType() == Graphics::Texture::TextureType::PNG)
		{
			DrawPNG(pos, hdc);
		}

	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{

	}

	void SpriteRenderer::DrawBMP(math::Vector2 pos, HDC hdc)
	{
		TransparentBlt(
			hdc, pos.x, pos.y,
			_texture->GetWidth()*_size.x, _texture->GetHeight()*_size.y,
			_texture->GetHdc(),0,0,
			_texture->GetWidth(),_texture->GetHeight(),
			RGB(255,0,255));
	}

	void SpriteRenderer::DrawPNG(math::Vector2 pos, HDC hdc)
	{
		Gdiplus::Graphics graphics(hdc);
		graphics.DrawImage
		(
			_texture->GetImage().get(),
			Gdiplus::Rect(pos.x, pos.y, _texture->GetWidth()*_size.x, _texture->GetHeight()*_size.y
			)
		);
	}

	
}