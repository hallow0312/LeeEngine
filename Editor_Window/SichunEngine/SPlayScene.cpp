#include "SPlayScene.h"
#include"GameObject.h"
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
		shared_ptr<GameObject>obj = make_shared<GameObject>();
		AddGameObject(obj);
		 
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
