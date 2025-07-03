#pragma once
#include "../Sichun_SOURCE/SSceneManager.h"
#include "SPlayScene.h"
namespace Sichun
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");



		SceneManager::LoadScene(L"PlayScene");
	}
}
