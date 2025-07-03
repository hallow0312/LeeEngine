#include "SScene.h"

namespace Sichun
{
	Scene::Scene()
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
}
