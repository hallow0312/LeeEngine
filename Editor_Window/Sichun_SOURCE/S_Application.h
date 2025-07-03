#pragma once
#include"CommonInclude.h"
#include"GameObject.h"

namespace Sichun {
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);

		void Run();
		
		void Update();
		void LateUpdate(); 

		void Render();

	private :
		HWND _hwnd;

		HDC _hdc;
		HDC  _backhdc;
		HBITMAP _backBuffer;

		UINT _width;
		UINT _height;
		
		GameObject _obj;

	private:
		void SettingWindow(HWND hwnd ,UINT width, UINT height);
		void CreateBackBuffer(HWND hwnd, UINT width, UINT height);
	};
}

