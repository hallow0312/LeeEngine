#pragma once
#include "../Sichun_SOURCE/Scene/SSceneManager.h"

#include "SPlayScene.h"
#include"STitleScene.h"
namespace Sichun
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::LoadScene(L"TitleScene");
	}
}



