#pragma once
#include"SResource.h"

namespace Sichun::Graphics
{

	class Texture : public Resource
	{
		using Base = Resource;
	public:
		enum class TextureType
		{
			BMP,
			PNG,
			NONE
		};
		Texture();
		~Texture();

		HRESULT Load(const std::wstring& path)override;

		UINT GetWidth() { return _width; }
		UINT GetHeight() { return _height; }
		HDC GetHdc() { return _hdc; }
		TextureType GetTextureType() { return _type; }
		std::shared_ptr<Gdiplus::Image>GetImage() { return _image; }
	private:
		TextureType _type;
		std::shared_ptr<Gdiplus::Image> _image;
		
		HBITMAP _bitMap;
		HDC _hdc;

		UINT _width;
		UINT _height;
	private:
		bool LoadBMP(const std::wstring& path);
		bool LoadPNG(const std::wstring& path);
	};
} 

