#include "SSceneManager.h"
#include"SDontDestroyOnLoad.h"
namespace Sichun 
{
	std::shared_ptr<Scene> SceneManager::ActiveScene = nullptr;
	std::shared_ptr<Scene> SceneManager::_DontDestroyOnLoad = nullptr;
	std::map<std::wstring, std::shared_ptr<Scene>> SceneManager::Scenes;

	std::vector<std::shared_ptr<GameObject>> SceneManager::GetGameObjects(Enum::LayerType type)
	{
	
		std::vector<std::shared_ptr<GameObject>>objs =
			ActiveScene->GetLayer(type)->GetGameObjects();
		std::vector<std::shared_ptr<GameObject>>dontDestroyObjs =
			_DontDestroyOnLoad->GetLayer(type)->GetGameObjects();

		objs.insert(objs.end(), dontDestroyObjs.begin(), dontDestroyObjs.end());

		return objs;
	}

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