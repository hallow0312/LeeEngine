#include "STileMapRenderer.h"
#include"GameObject/GameObject.h"
#include"../Component/STransform.h"
#include"../Component/STexture.h"
#include"Renderer/SRenderer.h"
namespace  Sichun
{
	Vector2 TileMapRenderer::TileSize = Vector2::One;
	
	TileMapRenderer::TileMapRenderer():
		Super(Enum::ComponentType::TileMapRenderer),
		_texture(nullptr),
		_size(2.0f,2.0f),
		_index(Vector2::Zero),
		_tileSize(16.0f,16.0f)
	{
		TileSize = _tileSize * _size;
	}
	TileMapRenderer::~TileMapRenderer()
	{
	}
	void TileMapRenderer::Initialize()
	{
	}
	void TileMapRenderer::Update()
	{
	}
	void TileMapRenderer::LateUpdate()
	{
		
	}
	void TileMapRenderer::Render(HDC hdc)
	{
		if (_texture == nullptr)assert(false);

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
	void TileMapRenderer::ImageLoad(const std::wstring& path)
	{
	}
	void TileMapRenderer::DrawBMP(std::shared_ptr<Transform> transform, HDC hdc)
	{
		Vector2 pos = transform->GetWorldPosition();
		Vector2 scale = transform->GetWorldScale();

		pos = Renderer::_mainCamera->CalculatePosition(pos);

		TransparentBlt(
			hdc, pos.x, pos.y,
			_tileSize.x*_size.x*scale.x,
			_tileSize.y*_size.y*scale.y,
			_texture->GetHdc(), _index.x*_tileSize.x, _index.y*_tileSize.y,
			_tileSize.x, _tileSize.y,
			RGB(255, 0, 255)
		);
	}
	void TileMapRenderer::DrawPNG(std::shared_ptr<Transform> transform, HDC hdc)
	{
		Vector2 pos = transform->GetWorldPosition();
		Vector2 scale = transform->GetWorldScale();
		float rotation = transform->GetWorldRotation();

		pos = Renderer::_mainCamera->CalculatePosition(pos);

		Gdiplus::Graphics graphics(hdc);
		graphics.TranslateTransform(pos.x, pos.y);   
		graphics.RotateTransform(rotation);          
		graphics.TranslateTransform(-pos.x, -pos.y); 

		graphics.DrawImage(
			_texture->GetImage().get(),
			Gdiplus::Rect(
				pos.x,
				pos.y,
				_tileSize.x * _size.x * scale.x, 
				_tileSize.y * _size.y * scale.y  
			),
			_index.x * _tileSize.x,              
			_index.y * _tileSize.y,              
			_tileSize.x,                         
			_tileSize.y,                         
			Gdiplus::UnitPixel
		);
	}
}