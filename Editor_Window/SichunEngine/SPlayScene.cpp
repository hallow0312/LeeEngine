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
#include"PlayerMovement.h"
#include"Component/SCamera.h"
#include"Renderer/SRenderer.h"
#include"GameObject/SObject.h"
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
		Base::Initialize();
		CreateMainCamera();
		CreateBackGround();
		CreatePlayer();
	}
		
	
		
	void PlayScene::CreateMainCamera()
	{
		std::shared_ptr<GameObject> camera = Object::Instantiate<GameObject>(Enum::LayerType::None);
		std::shared_ptr<Camera> cameraComp =camera->AddComponent<Camera>();
		
		Renderer::_mainCamera = cameraComp;
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

	void PlayScene::CreatePlayer()
	{
		_player = Object::Instantiate<Player>(Sichun::Enum::LayerType::Player, Vector2(150,380 ));
		_player->AddComponent<PlayerMovement>();
		std::shared_ptr<SpriteRenderer> sprite = _player->AddComponent<SpriteRenderer>();
		sprite->SetName(L"Sprite");
		std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"Reimu");
		sprite->SetTexture(texture);
	}

	void PlayScene::CreateBackGround()
	{
		std::shared_ptr<GameObject>bg = Object::Instantiate<GameObject>(Sichun::Enum::LayerType::BackGround);
		std::shared_ptr<SpriteRenderer>sprite = bg->AddComponent<SpriteRenderer>();
		sprite->SetName(L"Sprite");
		std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"BackGround");
		sprite->SetTexture(texture);
		sprite->SetSize(Vector2(1.5f, 2.0f));
	}

	
}
