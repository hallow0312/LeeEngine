#include "SToolScene.h"
#include"../SichunEngineHeader.h"
#include"../Sichun_SOURCE/GameObject/STileObject.h"
#include"../Sichun_SOURCE/Renderer/STileMapRenderer.h"
#include"../Camera/CameraController.h"
namespace Sichun
{
	ToolScene::ToolScene():_tiles{}
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

		if (InputManager::SaveKey())
			Save();
		
		if (InputManager::GetKeyDown(KeyCode::L))
			Load();
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

		
		
		for (size_t x = 0; x < 50; x ++)
		{
			Vector2  pos = Renderer::_mainCamera->CalculatePosition(
				Vector2(TileMapRenderer::GetTileSize().x*x,0.0f)
			);
			MoveToEx(hdc, pos.x, 0, NULL);
			LineTo(hdc, pos.x, height);
		}

		
		for (int y = 0; y < 50; y ++)
		{
			Vector2  pos = Renderer::_mainCamera->CalculatePosition(
				Vector2(0.0f, TileMapRenderer::GetTileSize().y * y)
			);
			MoveToEx(hdc, 0, pos.y, NULL);
			LineTo(hdc, width, pos.y);
		}

		SelectObject(hdc, oldPen);
		DeleteObject(hPen);
	}

	void ToolScene::CheckInputAndGetCoord()
	{
		if (InputManager::GetKeyDown(KeyCode::LBUTTON))
		{
			Vector2 pos = InputManager::GetMousePosition();
			pos = Renderer::_mainCamera->CalculateTilePosition(pos);
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

		_tiles.push_back(tile);
	}


	
	void ToolScene::CreateCamera()
	{
		std::shared_ptr<GameObject> camera = Object::Instantiate<GameObject>(Enum::LayerType::None);
		std::shared_ptr<Camera> cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraController>();
		Renderer::_mainCamera = cameraComp;
	}
	void ToolScene::GetTileResource()
	{
		std::shared_ptr<TileObject>tile = Object::Instantiate<TileObject>(Sichun::Enum::LayerType::Tile);
		std::shared_ptr<TileMapRenderer>tileRenderer = tile->AddComponent<TileMapRenderer>();

		std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"Floor");
		tileRenderer->SetTexture(texture);
		

		
	}
	void ToolScene::Save()
	{
		OPENFILENAME ofn = {};
		wchar_t szFilePath[256] = {};

		wchar_t exePath[MAX_PATH] = {};
		GetModuleFileName(nullptr, exePath, MAX_PATH);
		std::filesystem::path initialDir = std::filesystem::path(exePath).parent_path() / L"lee engine";

		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = sizeof(szFilePath) / sizeof(wchar_t);
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = initialDir.c_str();

		
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_OVERWRITEPROMPT;
		if (false == GetSaveFileName(&ofn))
			return;

		FILE* file = nullptr;
		_wfopen_s(&file, szFilePath, L"wb");

		for (auto & obj : _tiles)
		{
			
			std::shared_ptr<TileMapRenderer>renderer = obj->GetComponent<TileMapRenderer>();
			std::shared_ptr<Transform>tr = obj->GetComponent<Transform>();

			Vector2 index = renderer->GetIndex();
			Vector2 pos = tr->GetWorldPosition();

			int x = index.x;
			fwrite(&x, sizeof(int), 1, file);
			int y = index.y;
			fwrite(&y, sizeof(int), 1, file);

			x = pos.x;
			fwrite(&x, sizeof(int), 1, file);
			y = pos.y;
			fwrite(&y, sizeof(int), 1, file);
		}
		fclose(file);
	}
	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		
		FILE* file = nullptr;
		_wfopen_s(&file, szFilePath, L"rb"); 
		if (!file)
			return;

		_tiles.clear();

		while (true)
		{
			int ix, iy;
			int px, py;

			size_t readCount = fread(&ix, sizeof(int), 1, file);
			if (readCount != 1)
				break;

			fread(&iy, sizeof(int), 1, file);
			fread(&px, sizeof(int), 1, file);
			fread(&py, sizeof(int), 1, file);

			auto tile = Object::Instantiate<TileObject>(LayerType::Tile);
			auto renderer = tile->AddComponent<TileMapRenderer>();

			renderer->SetTexture(Resources::Find<Graphics::Texture>(L"Floor"));
			renderer->SetIndex(Vector2(ix, iy));

			tile->SetPosition(Vector2(px, py));

			_tiles.push_back(tile);
		}

		fclose(file);
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