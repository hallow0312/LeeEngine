#pragma once
#include"CommonInclude.h"
#include"GameObject.h"

namespace Sichun {
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND _hwnd);

		void Run();
		
		void Update();
		void LateUpdate(); 

		void Render();

		
	private :
		HWND _hwnd;
		HDC _hdc;
		
		
		GameObject _obj;

	};
}

