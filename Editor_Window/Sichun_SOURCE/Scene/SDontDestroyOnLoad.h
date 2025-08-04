#pragma once
#include"SScene.h"

namespace Sichun
{
	class DontDestroyOnLoad :public Scene
	{
		using Super = Scene;
	public:
		DontDestroyOnLoad();
		~DontDestroyOnLoad();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc)override;

	private:
		
	};
}

