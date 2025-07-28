#include "SBoxCollider2D.h"
#include"../STransform.h"
#include"../Sichun_SOURCE/GameObject/GameObject.h"
namespace Sichun
{
	BoxCollider2D::BoxCollider2D():Super()
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
		std::shared_ptr<Transform>trans = GetOwner()->GetComponent<Transform>();
		Vector2 pos = trans->GetWorldPosition();
		Vector2 offset = GetOffset();

		HPEN greenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		Rectangle(hdc,
			pos.x + offset.x,
			pos.y + offset.y,
			pos.x + offset.x + 100,
			pos.y + offset.y + 100);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);

		
		DeleteObject(greenPen);
	}
}