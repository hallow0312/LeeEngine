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
		{
			shared_ptr<Player>p1 = make_shared<Player>();
			shared_ptr<Transform>transform = p1->AddComponent<Transform>();
			
			transform->SetPos(800, 450);

			transform->SetName(L"Transform");

			shared_ptr<SpriteRenderer>sprite = p1->AddComponent<SpriteRenderer>();
			sprite->SetName(L"sprite");
		
			AddGameObject(p1);

		}

		{
			shared_ptr<Player>p1 = make_shared<Player>();
			shared_ptr<Transform>transform = p1->AddComponent<Transform>();

			transform->SetPos(300, 450);

			transform->SetName(L"Transform");

			shared_ptr<SpriteRenderer>sprite = p1->AddComponent<SpriteRenderer>();
			sprite->SetName(L"sprite");

			AddGameObject(p1);
		}

		{
			shared_ptr<Player>p1 = make_shared<Player>();
			shared_ptr<Transform>transform = p1->AddComponent<Transform>();

			transform->SetPos(100, 650);

			transform->SetName(L"Transform");

			shared_ptr<SpriteRenderer>sprite = p1->AddComponent<SpriteRenderer>();
			sprite->SetName(L"sprite");

			AddGameObject(p1);
		}
		 
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
