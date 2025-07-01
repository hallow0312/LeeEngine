#pragma once
#include"CommonInclude.h"

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
		
		float _speed;
		float _x;
		float _y;

	};
}

