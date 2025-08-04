#include "SSceneManager.h"
#include"SDontDestroyOnLoad.h"
namespace Sichun 
{
	std::shared_ptr<Scene> SceneManager::ActiveScene = nullptr;
	std::shared_ptr<Scene> SceneManager::_DontDestroyOnLoad = nullptr;
	std::map<std::wstring, std::shared_ptr<Scene>> SceneManager::Scenes;
	void SceneManager::Initialize()
	{
		if (ActiveScene)
			ActiveScene->Initialize();

		if (!_DontDestroyOnLoad)
		_DontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");

		if (_DontDestroyOnLoad)
		_DontDestroyOnLoad->Initialize();
	}

	void SceneManager::Update()
	{	 
		if (ActiveScene)
			ActiveScene->Update();
		if (_DontDestroyOnLoad)
		_DontDestroyOnLoad->Update();
	}	 
		 
	void SceneManager::LateUpdate()
	{	 
		if (ActiveScene)
			ActiveScene->LateUpdate();
		if (_DontDestroyOnLoad)
		_DontDestroyOnLoad->LateUpdate();
	}	 
		 
	void SceneManager::Render(HDC hdc)
	{
		if (ActiveScene)
			ActiveScene->Render(hdc);
		if (_DontDestroyOnLoad)
		_DontDestroyOnLoad->Render(hdc);
	}
	void SceneManager::Destroy()
	{
		if (ActiveScene)
			ActiveScene->Destroy();
		if (_DontDestroyOnLoad)
		_DontDestroyOnLoad->Destroy();
	}
}