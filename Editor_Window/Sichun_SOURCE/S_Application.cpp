#include "S_Application.h"
#include"InputManager.h"
#include"STime.h"
#include"SSceneManager.h"
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
		SceneManager::Initialize();
	
	}
	void Application::Update()
	{
		InputManager::Update();
		Time::Update();
		SceneManager::Update();
	}
	
	void  Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::LateUpdate()
	{
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();
		Time::Render(_backhdc);
		SceneManager::Render(_backhdc);
		CopyRenderTarget(_backhdc,_hdc);
		
	}
	void Application::CopyRenderTarget(HDC sourceHdc, HDC destHdc)
	{
		BitBlt(destHdc, 0, 0, _width, _height, sourceHdc, 0, 0, SRCCOPY);
	}
	void Application::ClearRenderTarget()
	{
		Rectangle(_backhdc, -1, -1, 1601, 901);
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