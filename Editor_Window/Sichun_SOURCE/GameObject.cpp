#include "GameObject.h"

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

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			_x -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			_x += 0.01f;

		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			_y -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			_y += 0.01f;
		}
		
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