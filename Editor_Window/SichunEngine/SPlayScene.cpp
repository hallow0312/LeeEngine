#include "SPlayScene.h"
#include"GameObject.h"
#include"SPlayer.h"
#include"STransform.h"
#include"SSpriteRenderer.h"
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
		std::shared_ptr<Player>bg = std::make_shared<Player>();
		std::shared_ptr<Transform>transform = bg->AddComponent<Transform>();
		std::shared_ptr<SpriteRenderer>sprite = bg->AddComponent<SpriteRenderer>();
		
		transform->SetPos(Vector2(0, 0));
		transform->SetName(L"Transform");

		sprite->SetName(L"Sprite");
		sprite->ImageLoad(L"C:\\Users\\user\\Desktop\\2DGame\\LeeEngine\\Editor_Window\\Resources\\Sichun.png");
		AddGameObject(bg);
		 
	}

	void PlayScene::Update()
	{
		Base::Update();
	}

	void PlayScene::LateUpdate()
	{
		Base::LateUpdate();
	}

	void PlayScene::Render(HDC hdc)
	{
		Base::Render(hdc);
	}

}
