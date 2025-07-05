#include "SSpriteRenderer.h"
#include"GameObject/GameObject.h"
#include"STransform.h"
namespace Sichun {
	SpriteRenderer::SpriteRenderer()
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
		/*if (_image)
		{
			graphics.DrawImage(_image.get(), Gdiplus::Rect(pos.x, pos.y, _width, _height));
		}*/
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{

	}

	
}