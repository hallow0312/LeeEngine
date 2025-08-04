#pragma once
#include "../Sichun_SOURCE/Scene/SSceneManager.h"

#include "SPlayScene.h"
#include"STitleScene.h"
#include"../Sichun_SOURCE/Scene/SToolScene.h"
namespace Sichun
{
	void LoadScenes()
	{
		/*SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");*/
		SceneManager::CreateScene<ToolScene>(L"ToolScene");
		SceneManager::LoadScene(L"ToolScene");
	}
}



