#include "SToolScene.h"
#include"../SichunEngineHeader.h"
#include"../Sichun_SOURCE/GameObject/STileObject.h"
#include"../Sichun_SOURCE/Renderer/STileMapRenderer.h"

namespace Sichun
{
	ToolScene::ToolScene():_gridSize(32)
	{
	}
	ToolScene::~ToolScene()
	{
	}
	void ToolScene::Initialize()
	{
		
		CreateCamera();
		GetTileResource();
		Super::Initialize();
		
	}
	void ToolScene::Update()
	{
		Super::Update();                        
	}
	void ToolScene::LateUpdate()
	{
		Super::LateUpdate();
	}
	void ToolScene::Render(HDC hdc)
	{
		Super::Render(hdc);
		DrawGrid(hdc, _gridSize, RGB(150,150,150));
	}
	void ToolScene::DrawGrid(HDC hdc, int spacing, COLORREF color)
	{
		if (spacing <= 0) return;

		HPEN hPen = CreatePen(PS_SOLID, 1, color);
		HGDIOBJ oldPen = SelectObject(hdc, hPen);

		RECT clientRect;
		GetClientRect(GetActiveWindow(), &clientRect);
		int width = clientRect.right - clientRect.left;
		int height = clientRect.bottom - clientRect.top;

		
		for (int x = 0; x < width; x += spacing)
		{
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, height);
		}

		// °¡·ÎÁÙ
		for (int y = 0; y < height; y += spacing)
		{
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, width, y);
		}

		SelectObject(hdc, oldPen);
		DeleteObject(hPen);
	}

	void ToolScene::SetGridSpacing(int spacing)
	{
		_gridSize = spacing;
	}
	
	void ToolScene::CreateCamera()
	{
		std::shared_ptr<GameObject> camera = Object::Instantiate<GameObject>(Enum::LayerType::None);
		std::shared_ptr<Camera> cameraComp = camera->AddComponent<Camera>();

		Renderer::_mainCamera = cameraComp;
	}
	void ToolScene::GetTileResource()
	{
		std::shared_ptr<TileObject>tile = Object::Instantiate<TileObject>(Sichun::Enum::LayerType::Tile);
		std::shared_ptr<TileMapRenderer>tileRenderer = tile->AddComponent<TileMapRenderer>();

		std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"Floor");
		tileRenderer->SetTexture(texture);
		

		
	}
}