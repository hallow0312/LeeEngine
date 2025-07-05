#pragma once
#include"SLayer.h"
#include"GameObject.h"
#include"SComponent.h"
#include"SScene.h"
#include"SSceneManager.h"
#include"STransform.h"

namespace Sichun::Object
{
	template<typename T>
	static std::shared_ptr<T>Instantiate(Sichun::Enum::LayerType type)
	{
		std::shared_ptr<T> obj = std::make_shared<T>();
		obj->AddComponent<Transform>();
		std::shared_ptr<Scene>activeScene = SceneManager::GetActiveScene();
		std::shared_ptr<Layer>layer = activeScene->GetLayer(type);
		layer->AddGameObject(obj);
		return obj;
	}
	template<typename T>
	static std::shared_ptr<T>Instantiate(Sichun::Enum::LayerType type, math::Vector2 pos)
	{
		std::shared_ptr<T> obj = std::make_shared<T>();
		obj->AddComponent<Transform>(); 
		std::shared_ptr<Scene> activeScene = SceneManager::GetActiveScene();
		std::shared_ptr<Layer> layer = activeScene->GetLayer(type);
		layer->AddGameObject(obj);
	  
	
		std::shared_ptr<Transform> transform = obj->GetComponent<Transform>();
		if (transform != nullptr)
			transform->SetPos(pos);

		return obj;
	}
}


