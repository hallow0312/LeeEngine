#include "S_Application.h"
#include"InputManager.h"
#include"STime.h"
#include"SSceneManager.h"

namespace Sichun {

	Application::Application() :
		_hwnd(nullptr), _hdc(nullptr),
		_width(0), _height(0),
		_backhdc(NULL), _backBuffer(NULL)
	{
	}
	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		SettingWindow(hwnd, width, height);
		CreateBackBuffer(hwnd, width, height);
		Time::Initialize();
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
		CopyRenderTarget(_backhdc, _hdc);
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
		_hwnd = hwnd;
		_hdc = GetDC(_hwnd);

		RECT rect = { 0, 0, (LONG)width, (LONG)height };
		_width = rect.right - rect.left;
		_height = rect.bottom - rect.top;

		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, FALSE);
		int windowWidth = rect.right - rect.left;
		int windowHeight = rect.bottom - rect.top;

		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		int posX = (screenWidth - windowWidth) / 2;
		int posY = (screenHeight - windowHeight) / 2;

		SetWindowPos(_hwnd, nullptr, posX, posY, windowWidth, windowHeight, 0);
		ShowWindow(_hwnd, SW_SHOW);
	}
	void Application::CreateBackBuffer(HWND hwnd, UINT width, UINT height)
	{
		_backBuffer = CreateCompatibleBitmap(_hdc, width, height);
		_backhdc = CreateCompatibleDC(_hdc);
		HBITMAP oldBitmap = static_cast<HBITMAP>(SelectObject(_backhdc, _backBuffer));
		DeleteObject(oldBitmap);
	}
}