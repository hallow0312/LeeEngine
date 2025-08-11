#pragma once


#include"../Sichun_SOURCE/Scene/SScene.h"

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
		void DrawGrid(HDC hdc, int spacing, COLORREF color);
		void SetGridSpacing(int spacing);
		void CreateCamera();
		void GetTileResource();
	private:
		int _gridSize;
	};
}
