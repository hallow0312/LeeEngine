#include "SSpriteRenderer.h"
#include"GameObject.h"
#include"STransform.h"
namespace Sichun {
	SpriteRenderer::SpriteRenderer():_image(nullptr),_width(0),_height(0)
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
		std::shared_ptr<Transform> tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		Gdiplus::Graphics graphics(hdc);
		if (_image)
		{
			graphics.DrawImage(_image.get(), Gdiplus::Rect(pos.x, pos.y, _width, _height));
		}
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{

		 _image = std::shared_ptr<Gdiplus::Image>(Gdiplus::Image::FromFile(path.c_str()));

		 if (_image && _image->GetLastStatus() == Gdiplus::Ok)
		 {
			 _width = _image->GetWidth();
			 _height = _image->GetHeight();
			 OutputDebugString(L"[ImageLoad] 로딩 성공\n");
		 }
		 else
		 {
			 OutputDebugString(L"[ImageLoad] 로딩 실패!\n");
			 _image = nullptr;
		 }
	}

	
}