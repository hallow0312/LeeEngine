#include "S_Application.h"
#include"InputManager.h"
#include"STime.h"
namespace Sichun {

	Application::Application():
		_hwnd(nullptr),_hdc(nullptr),
		_width(0),_height(0),
		_backhdc(NULL),_backBuffer(NULL)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd,UINT width, UINT height) //copy X ADDRESS 0
	{
		_hwnd = hwnd;
		_hdc = GetDC(_hwnd);
		
		SettingWindow(_hwnd, width, height);
		CreateBackBuffer(_hwnd, width, height);

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
		Rectangle(_backhdc, 0, 0, 1600, 900);
		Time::Render(_backhdc);
		_obj.Render(_backhdc);

		BitBlt(_hdc,0,0,_width,_height,_backhdc,0,0,SRCCOPY);
	}

	void Application::SettingWindow(HWND hwnd, UINT width, UINT height)
	{
		RECT rect = { 0,0,width,height };

		_width = rect.right - rect.left;
		_height = rect.bottom - rect.top;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(_hwnd, nullptr, 100, 0,
			rect.right - rect.left, rect.bottom - rect.top,
			0);
		ShowWindow(_hwnd, false);
	}
	void Application::CreateBackBuffer(HWND hwnd, UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 backbuffer 생성 
		_backBuffer = CreateCompatibleBitmap(_hdc, width, height);
		//backbuffer 를 가르킬 DC생성
		_backhdc = CreateCompatibleDC(_hdc);
		HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(_backhdc, _backBuffer));
		DeleteObject(oldBitmap);
	}
}