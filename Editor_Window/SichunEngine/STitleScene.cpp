#include "STitleScene.h"
#include"InputManager.h"
#include"SSceneManager.h"
namespace Sichun
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		Base::Initialize();
	}
	void TitleScene::Update()
	{
		Base::Update();
	}
	void TitleScene::LateUpdate()
	{
		Base::LateUpdate();
		if (InputManager::GetKeyDown(KeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Base::Render(hdc);
		wchar_t str[50] = L"Title Scene";

		int len = wcsnlen_s(str, 50);
		TextOut(hdc, 0, 0, str, len);
			
	}
}