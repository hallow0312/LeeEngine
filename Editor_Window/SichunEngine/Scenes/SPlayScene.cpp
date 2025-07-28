#include "SPlayScene.h"
#include"../Player/SPlayer.h"
#include"GameObject/GameObject.h"
#include"GameObject/SObject.h"
#include"GameObject/InputManager.h"
#include"Component/STransform.h"
#include"Component/SSpriteRenderer.h"
#include"Component/STexture.h"
#include"Scene/SSceneManager.h"
#include"Resource/SResources.h"
#include"../Player/PlayerController.h"
#include"Component/SCamera.h"
#include"Renderer/SRenderer.h"
#include"GameObject/SObject.h"
#include"Component/SAnimator.h"
#include"../Player/PlayerAnimation.h"
#include"../Player/YinYang.h"
#include"../Sichun_SOURCE/Component/Collider/SBoxCollider2D.h"
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
		CreateMainCamera();
		
		CreateBackGround();
		CreatePlayer();
		Base::Initialize();
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
		
		
	}

	void PlayScene::OnEnter()
	{
		

	}

	void PlayScene::OnExit()
	{
		
	}



	
	void PlayScene::CreateAnimation()
	{
		std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"Reimu");
		std::shared_ptr<Animator>  animator = _player->AddComponent<Animator>();

		animator->CreateAnimation(L"ReimuIdleStart", texture,
			Vector2(0.f, 0.f), Vector2(32.0, 64.0f), Vector2::Zero, 2, 0.15f);
		animator->CreateAnimation(L"ReimuIdle", texture,
			Vector2(0, 64.0f), Vector2(32.0, 64.0f), Vector2::Zero, 4, 0.15f);
		animator->CreateAnimation(L"ReimuMoveStart", texture,
			Vector2(0.0f, 128.0f), Vector2(32.0, 64.0f), Vector2::Zero, 5, 0.15f);
		animator->CreateAnimation(L"ReimuMoveHorizontal", texture,
			Vector2(32.0f, 128.0f), Vector2(32.0, 64.0f), Vector2::Zero, 4, 0.15f);
		animator->CreateAnimationByFolder(L"ReimuIdle?", L"..\\Resources\\Reimu\\Idle\\Images", Vector2::Zero, 0.1f);
		animator->PlayAnimation(L"ReimuIdle", true);
		
	}

	void PlayScene::CreatePlayer()
	{
		_player = Object::Instantiate<Player>(Sichun::Enum::LayerType::Player, Vector2(150.0f,380.0f));
		_player->AddComponent<PlayerController>();
		_player->AddComponent<PlayerAnimation>();
		_player->AddComponent < BoxCollider2D>();
		_player->GetComponent<BoxCollider2D>()->SetOffset(Vector2(-50, -50));
		{
			std::shared_ptr<GameObject>yinYang = Object::Instantiate<GameObject>(Sichun::Enum::LayerType::Player);

			std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"YinYang");
			std::shared_ptr<SpriteRenderer> sprite = yinYang->AddComponent<SpriteRenderer>();
			sprite->SetTexture(texture);

			yinYang->AddComponent<YinYang>();
			yinYang->GetComponent<YinYang>()->Setting(_player->GetComponent<Transform>(), Vector2(-30.0f, -5.0f));
		}
		{
			std::shared_ptr<GameObject>yinYang = Object::Instantiate<GameObject>(Sichun::Enum::LayerType::Player);

			std::shared_ptr<Graphics::Texture>texture = Resources::Find<Graphics::Texture>(L"YinYang");
			std::shared_ptr<SpriteRenderer> sprite = yinYang->AddComponent<SpriteRenderer>();
			sprite->SetTexture(texture);

			yinYang->AddComponent<YinYang>();
			yinYang->GetComponent<YinYang>()->Setting(_player->GetComponent<Transform>(), Vector2(15.0f, -5.0f));
		}

		CreateAnimation();
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
