#include "SPlayScene.h"
#include"GameObject.h"
#include"SPlayer.h"
#include"STransform.h"
#include"SSpriteRenderer.h"
#include"InputManager.h"
#include"SSceneManager.h"
namespace Sichun
{

	PlayScene::PlayScene()
	{
	}

	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		_player = std::make_shared<Player>();
		std::shared_ptr<Transform>transform = _player->AddComponent<Transform>();
		std::shared_ptr<SpriteRenderer>sprite = _player->AddComponent<SpriteRenderer>();
		
		transform->SetPos(Vector2(0, 0));
		transform->SetName(L"Transform");

		sprite->SetName(L"Sprite");
		sprite->ImageLoad(L"C:\\Users\\user\\Desktop\\2DGame\\LeeEngine\\Editor_Window\\Resources\\Sichun.png");
		AddGameObject(_player,LayerType::Player);
		 
	}

	void PlayScene::Update()
	{
		Base::Update();
	}

	void PlayScene::LateUpdate()
	{
		Base::LateUpdate();
		if (InputManager::GetKeyDown(KeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Base::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		int len = wcsnlen_s(str, 50);
		TextOut(hdc, 0, 0, str, len);
		
	}

	void PlayScene::OnEnter()
	{
	}

	void PlayScene::OnExit()
	{
		_player->GetComponent<Transform>()->SetPos(Vector2(0, 0));
	}

}
