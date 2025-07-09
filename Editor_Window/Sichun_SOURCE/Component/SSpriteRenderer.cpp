#include "SSpriteRenderer.h"
#include"GameObject/GameObject.h"
#include"STransform.h"
#include"STexture.h"
#include"Renderer/SRenderer.h"

namespace Sichun {
	SpriteRenderer::SpriteRenderer():Base(Enum::ComponentType::SpriteRenderer),_texture(nullptr), _size(Vector2::One)
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
		
		if (_texture->GetTextureType() == Graphics::Texture::TextureType::BMP)
		{
			DrawBMP(transform, hdc);
		}
		else if (_texture->GetTextureType() == Graphics::Texture::TextureType::PNG)
		{
			DrawPNG(transform, hdc);
		}

	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{

	}

	void SpriteRenderer::DrawBMP(std::shared_ptr<Transform>transform, HDC hdc)
	{
		math::Vector2 pos = transform->GetPos();
		Vector2 scale = transform->GetScale();
		pos = Renderer::_mainCamera->CalculatePosition(pos);
		TransparentBlt(
			hdc, pos.x, pos.y,
			_texture->GetWidth()*_size.x*scale.x, _texture->GetHeight()*_size.y*scale.y,
			_texture->GetHdc(),0,0,
			_texture->GetWidth(),_texture->GetHeight(),
			RGB(255,0,255));
	}

	void SpriteRenderer::DrawPNG(std::shared_ptr<Transform>transform, HDC hdc)
	{
		Vector2 pos = transform->GetPos();
		Vector2 scale = transform->GetScale();

		if (Renderer::_mainCamera)
			Renderer::_mainCamera->CalculatePosition(pos);

		Gdiplus::Graphics graphics(hdc);


		graphics.RotateTransform(transform->GetRotation());
	
		graphics.DrawImage(
			_texture->GetImage().get(), // std::shared_ptr<Gdiplus::Image>
			Gdiplus::Rect(
				(pos.x),
				(pos.y),
				(_texture->GetWidth() * _size.x*scale.x),
				(_texture->GetHeight() * _size.y*scale.y)
			),
			0, 0,
			_texture->GetWidth(), _texture->GetHeight(),
			Gdiplus::UnitPixel
		);
	}

	
}