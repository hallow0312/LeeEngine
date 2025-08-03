#include "SCircleCollider2D.h"
#include"../STransform.h"
#include"../Sichun_SOURCE/GameObject/GameObject.h"
#include"Component/SCamera.h"
#include"Renderer/SRenderer.h"
namespace Sichun
{
	CircleCollider2D::CircleCollider2D():Super(ColliderType::Circle),_radius(0.0f)
	{
	}
	CircleCollider2D::~CircleCollider2D()
	{
	}
	void CircleCollider2D::Initialize()
	{
	}
	void CircleCollider2D::Update()
	{
	}
	void CircleCollider2D::LateUpdate()
	{
	}
	void CircleCollider2D::Render(HDC hdc)
	{
		std::shared_ptr<Transform> tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetWorldPosition();

		if (Renderer::_mainCamera)
			pos = Renderer::_mainCamera->CalculatePosition(pos);

		Vector2 offset = GetOffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

		Vector2 rightBottom;
		rightBottom.x = pos.x + offset.x + 100 * GetSize().x;
		rightBottom.y = pos.y + offset.y + 100 * GetSize().y;

		Ellipse(hdc, pos.x + offset.x
			, pos.y + offset.y
			, rightBottom.x
			, rightBottom.y);

		SelectObject(hdc, oldBrush);
		SelectObject(hdc, oldPen);
		DeleteObject(greenPen);
	}
}