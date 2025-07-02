#include "GameObject.h"
#include "InputManager.h"
namespace Sichun {
	GameObject::GameObject()
	{
		SetPosition(0, 0);
	}

	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{
		float x = GetPositionX();
		float y = GetPositionY();

		float moveSpeed = 0.01f;

		int horizontal = InputManager::GetAxis(AxisName::HORIZONTAL);
		int vertical = InputManager::GetAxis(AxisName::VERTICAL);

		_x += horizontal * moveSpeed;
		_y += vertical * moveSpeed;
		
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		HBRUSH  brush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		float x =GetPositionX();
		float y =GetPositionY();

		Rectangle(hdc, 100 + x, 100 + y, 200 + x, 200 + y);
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
}