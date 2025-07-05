#include "STexture.h"
#include "S_Application.h"
extern Sichun::Application _application;
namespace Sichun::Graphics
{
	Texture::Texture():Base(Enum::ResourceType::Texture)
	{
	}
	Texture::~Texture()
	{
	}
	HRESULT Sichun::Graphics::Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".")+1);
		if (ext == L"bmp")
		{
			if (LoadBMP(path))return S_OK;
		}
		else if (ext == L"png")
		{
			if (LoadPNG(path))return S_OK;
		}
		return S_FALSE;
	}
	bool Texture::LoadBMP(const std::wstring& path)
	{
		
		_bitMap =static_cast<HBITMAP>
			(
			LoadImageW(
				nullptr, path.c_str(),
				IMAGE_BITMAP, 0, 0,
				LR_LOADFROMFILE | LR_CREATEDIBSECTION
			)
			);
		if (_bitMap == nullptr)
		{
			_type = TextureType::NONE;
			return  false;
		}
		else
		{
			_type = TextureType::BMP;
			BITMAP info = {};

			GetObject(_bitMap, sizeof(BITMAP), &info);

			_width = info.bmWidth;
			_height = info.bmHeight;

			HDC mainHDC = _application.GetHDC();
			_hdc = CreateCompatibleDC(mainHDC);
			HBITMAP oldbitmap = (HBITMAP) SelectObject(_hdc, _bitMap);
			DeleteObject(oldbitmap);

			return true;
		}
		
	}

	bool Texture::LoadPNG(const std::wstring& path)
	{
		_image = std::shared_ptr<Gdiplus::Image>(Gdiplus::Image::FromFile(path.c_str()));
		if (_image && _image->GetLastStatus() == Gdiplus::Ok)
		{
			_type = TextureType::PNG;
			_width = _image->GetWidth();
			_height = _image->GetHeight();
			OutputDebugString(L"[ImageLoad] 로딩 성공\n");
			return true;
		}
		else
		{
			_type = TextureType::NONE;
			OutputDebugString(L"[ImageLoad] 로딩 실패!\n");
			_image = nullptr;
			return false;
		}
	}
}