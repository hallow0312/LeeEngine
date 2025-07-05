#pragma once
#include"Scene/SLayer.h"
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


