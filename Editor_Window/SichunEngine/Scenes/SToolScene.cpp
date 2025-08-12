#include "SToolScene.h"
#include"../SichunEngineHeader.h"
#include"../Sichun_SOURCE/GameObject/STileObject.h"
#include"../Sichun_SOURCE/Renderer/STileMapRenderer.h"

namespace Sichun
{
	ToolScene::ToolScene()
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
	
		CheckInputAndGetCoord();
		
	}
	void ToolScene::Render(HDC hdc)
	{
		Super::Render(hdc);
		DrawGrid(hdc,TileMapRenderer::GetTileSize().x, RGB(150, 150, 150));
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

		// 가로줄
		for (int y = 0; y < height; y += spacing)
		{
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, width, y);
		}

		SelectObject(hdc, oldPen);
		DeleteObject(hPen);
	}

	void ToolScene::CheckInputAndGetCoord()
	{
		if (InputManager::GetKeyDown(KeyCode::LBUTTON))
		{
			Vector2 pos = InputManager::GetMousePosition();
			
			Vector2 coord;
			coord.x = (int)(pos.x / TileMapRenderer::GetTileSize().x);
			coord.y = (int)(pos.y / TileMapRenderer::GetTileSize().y);
			SettingTileToGrid(coord);
		
		}
	}

	void ToolScene::SettingTileToGrid(Vector2 coord)
	{
		std::shared_ptr<TileObject> tile = Object::Instantiate<TileObject>(LayerType::Tile);
		std::shared_ptr<TileMapRenderer> renderer = tile->AddComponent<TileMapRenderer>();
		renderer->SetTexture(Resources::Find<Graphics::Texture>(L"Floor"));
		int x = coord.x * TileMapRenderer::GetTileSize().x;
		int y = coord.y * TileMapRenderer::GetTileSize().y;
		tile->SetPosition(Vector2(x,y));
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
LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)//매 프레임마다 호출 
	{
	case WM_COMMAND:
	{
		//	int wmId = LOWORD(wParam);
		//	// 메뉴 선택을 구문 분석합니다:
		//	switch (wmId)
		//	{
		//	case IDM_ABOUT:
		//		DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		//		break;
		//	case IDM_EXIT:
		//		DestroyWindow(hWnd);
		//		break;
		//	default:
		//		return DefWindowProc(hWnd, message, wParam, lParam);
		//	}
		//
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		Gdiplus::Graphics graphics(hdc);
		auto texture = Sichun::Resources::Find<Sichun::Graphics::Texture>(L"Floor");

		if (texture && texture->GetImage())
		{
			graphics.DrawImage(
				texture->GetImage().get(),
				Gdiplus::Rect(
					0,
					0,
					texture->GetWidth(),
					texture->GetHeight()
				),
				0,
				0,
				texture->GetWidth(),
				texture->GetHeight(),
				Gdiplus::UnitPixel
			);
		}


		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY: //윈도우 종료시 호출 x버튼 누를때 겠지 ㅇㅇ

		PostQuitMessage(0);
		break;
		//WM_MOVE : 윈도우 창을 움직이는 경우 
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}