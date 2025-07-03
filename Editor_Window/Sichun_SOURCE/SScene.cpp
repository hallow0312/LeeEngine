#include "SScene.h"

namespace Sichun
{
	Scene::Scene():_objs{}
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		
	}
	void Scene::Update()
	{
		for (shared_ptr<GameObject> element : _objs)
		{
			element->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (shared_ptr<GameObject> element : _objs)
		{
			element->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (shared_ptr<GameObject> element : _objs)
		{
			element->Render(hdc);
		}
	}
	void Scene::AddGameObject(shared_ptr<GameObject> obj)
	{
		_objs.push_back(obj);
	}
}
