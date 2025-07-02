#include "S_Application.h"

namespace Sichun {

	Application::Application():_hwnd(nullptr),_hdc(nullptr)
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
		_obj.Update();
	
	}
	
	void  Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::LateUpdate()
	{
		_obj.LateUpdate();
	}

	void Application::Render()
	{
		_obj.Render(_hdc);

	}

}