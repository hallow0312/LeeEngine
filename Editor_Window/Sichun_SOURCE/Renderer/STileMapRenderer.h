#pragma once
#include"../Common/SEntity.h"
#include"../Component/STexture.h"
#include"../Component/SComponent.h"

namespace Sichun 
{
	class Transform;

	class TileMapRenderer : public Component
	{
		using Super = Component;
		
	public:

		TileMapRenderer();
		~TileMapRenderer();

		void Initialize()override;
		void Update()override;
		void LateUpdate()override;
		void Render(HDC hdc)override;

		void SetTexture(std::shared_ptr<Graphics::Texture>texture) { _texture = texture; }
		void SetSize(math::Vector2 size) { _size = size; }
		void SetIndex(Vector2 index) { _index = index;  }
		void SetTileSize(Vector2 tileSize) { _tileSize = tileSize; }
		void ImageLoad(const std::wstring& path);
		void DrawBMP(std::shared_ptr<Transform>transform, HDC hdc);
		void DrawPNG(std::shared_ptr<Transform>transform, HDC hdc);

		static const Vector2& GetTileSize() { return TileSize; }
		Vector2 GetIndex() { return _index; }

	private:
		
		Vector2 _tileSize;
		Vector2 _size;
		Vector2 _index;

		std::shared_ptr<Graphics::Texture>_texture;

		static Vector2 TileSize;
		
	};
}
