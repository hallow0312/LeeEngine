#pragma once
#include"Scene/Slayer.h"
#include"Scene/SScene.h"
#include"Scene/SSceneManager.h"
#include"GameObject/GameObject.h"
#include"Component/SComponent.h"
#include"Component/STransform.h"

namespace Sichun::Object
{
	template<typename T>
	static std::shared_ptr<T>Instantiate(Sichun::Enum::LayerType type)
	{
		std::shared_ptr<T> obj = std::make_shared<T>();
		obj->InitializeTransform();
		std::shared_ptr<Scene>activeScene = SceneManager::GetActiveScene();
		obj->SetLayerType(type);
		std::shared_ptr<Layer>layer = activeScene->GetLayer(type);
		layer->AddGameObject(obj);
		return obj;
	}
	template<typename T>
	static std::shared_ptr<T>Instantiate(Sichun::Enum::LayerType type, math::Vector2 pos)
	{
		std::shared_ptr<T> obj = std::make_shared<T>();
		obj->InitializeTransform();
		std::shared_ptr<Scene> activeScene = SceneManager::GetActiveScene();
		std::shared_ptr<Layer> layer = activeScene->GetLayer(type);
		obj->SetLayerType(type);
		layer->AddGameObject(obj);
	  
	
		std::shared_ptr<Transform> transform = obj->GetComponent<Transform>();
		if (transform != nullptr)
			transform->SetPosition(pos);

		return obj;
	}
	static void OnDestroy(std::shared_ptr<GameObject>obj)
	{
		obj->OnDestroy();
	}
	static void DontDestroyOnLoad(std::shared_ptr<GameObject>obj)
	{
		std::shared_ptr<Scene>activeScene = SceneManager::GetActiveScene();
		activeScene->DestroyGameObject(obj);

		std::shared_ptr<Scene>dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(obj, obj->GetLayerType());
	}
}


