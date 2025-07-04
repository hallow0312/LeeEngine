#include "SSceneManager.h"

namespace Sichun 
{
	std::shared_ptr<Scene> SceneManager::_activeScene = nullptr;
	std::map<std::wstring, std::shared_ptr<Scene>> SceneManager::_scenes;
	void SceneManager::Initialize()
	{
		
	}

	void SceneManager::Update()
	{	 
		if (_activeScene)
			_activeScene->Update();
	}	 
		 
	void SceneManager::LateUpdate()
	{	 
		if (_activeScene)
			_activeScene->LateUpdate();
	}	 
		 
	void SceneManager::Render(HDC hdc)
	{
		if (_activeScene)
			_activeScene->Render(hdc);
	}
}