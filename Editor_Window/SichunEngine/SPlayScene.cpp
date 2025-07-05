#include "SPlayScene.h"
#include"SPlayer.h"
#include"GameObject/GameObject.h"
#include"GameObject/SObject.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Component/SSpriteRenderer.h"
#include"Component/STexture.h"
#include"Scene/SSceneManager.h"
#include"Resource/SResources.h"
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
		_player = Object::Instantiate<Player>(Sichun::Enum::LayerType::Player, Vector2(100, 0));

		std::shared_ptr<SpriteRenderer> sprite = _player->AddComponent<SpriteRenderer>();
		sprite->SetName(L"Sprite");
		std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"Sichun");
		sprite->SetTexture(texture);
		sprite->SetSize(math::Vector2(0.5f,0.5f));
		
	
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
		
	}

}
