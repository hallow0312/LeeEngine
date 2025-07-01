#include "S_Application.h"

namespace Sichun {

	Application::Application():_hwnd(nullptr),_hdc(nullptr),_speed(0),_x(0.0f),_y(0.0f)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd ) //copy X ADDRESS 0
	{
		_hwnd = hwnd;
		_hdc = GetDC(_hwnd);
	
	}
	void Application::Update()
	{
	
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
	
	void  Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		HBRUSH  brush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, brush);

		Rectangle(_hdc, 100+_x, 100+_y, 200+_x, 200+_y);
		SelectObject(_hdc, oldBrush);
		DeleteObject(brush);

	}

}