#pragma once


#include"SScene.h"

namespace Sichun
{
	class ToolScene :public Scene
	{
		using Super = Scene;
	public:
		ToolScene();
		~ToolScene();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc)override;

	private:

	};
}
