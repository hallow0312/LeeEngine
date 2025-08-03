#include "SBoxCollider2D.h"
#include"../STransform.h"
#include"../Sichun_SOURCE/GameObject/GameObject.h"
#include"Component/SCamera.h"
#include"Renderer/SRenderer.h"
namespace Sichun
{
	BoxCollider2D::BoxCollider2D():Super(ColliderType::Rect)
	{
	}
	BoxCollider2D::~BoxCollider2D()
	{
	}
	void BoxCollider2D::Initialize()
	{
	}
	void BoxCollider2D::Update()
	{
	}
	void BoxCollider2D::LateUpdate()
	{
	}
	void BoxCollider2D::Render(HDC hdc)
	{
		std::shared_ptr<Transform> trans = GetOwner()->GetComponent<Transform>();
		Vector2 pos = trans->GetWorldPosition();
		Vector2 offset = GetOffset();
		Vector2 size = GetSize(); 

		if (Renderer::_mainCamera)
			pos = Renderer::_mainCamera->CalculatePosition(pos);

		HPEN greenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		
		Rectangle(hdc,
			pos.x + offset.x,
			pos.y + offset.y,
			pos.x + offset.x + size.x * 100.0f,
			pos.y + offset.y + size.y * 100.0f);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		DeleteObject(greenPen);
	}
}