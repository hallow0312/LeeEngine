#pragma once
#include"../Common/SEntity.h"
#include"STexture.h"
#include"SComponent.h"
namespace Sichun 
{
	class Transform;
	
	class SpriteRenderer:public Component
	{
		using Base = Component;
	public:
		SpriteRenderer();
		~SpriteRenderer();
		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;
		
		void SetTexture(std::shared_ptr<Graphics::Texture>texture) { _texture = texture; }
		void SetSize(math::Vector2 size) { _size = size; }

		void ImageLoad(const std::wstring& path);
		void DrawBMP(std::shared_ptr<Transform>transform, HDC hdc);
		void DrawPNG(std::shared_ptr<Transform>transform,HDC hdc);

	private:
		
		std::shared_ptr<Graphics::Texture>_texture;
		math::Vector2 _size;
	};

}
