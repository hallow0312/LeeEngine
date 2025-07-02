#include "S_Application.h"
#include"InputManager.h"
#include"STime.h"
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
		InputManager::Initialize();
		Time::Initialize();
	
	}
	void Application::Update()
	{
		InputManager::Update();
		Time::Update();
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
		Time::Render(_hdc);
		_obj.Render(_hdc);
	}

}