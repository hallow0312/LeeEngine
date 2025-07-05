#include "SScene.h"

namespace Sichun
{
	Scene::Scene()
	{
		_layers.resize(static_cast<UINT>(Enum::LayerType::Max));
		std::generate(_layers.begin(), _layers.end(), []()
			{
				return std::make_shared<Layer>();
			});
	}
	Scene::~Scene()
	{
	}
	void Scene::Initialize()
	{
		for (std::shared_ptr<Layer> element : _layers)
		{
			if (element == nullptr)continue;
			element->Initialize();
		}
	}
	void Scene::Update()
	{
		for (std::shared_ptr<Layer> element : _layers)
		{
			if (element == nullptr)continue;
			element->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (std::shared_ptr<Layer> element : _layers)
		{
			if (element == nullptr)continue;
			element->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (std::shared_ptr<Layer> element : _layers)
		{
			if (element == nullptr)continue;
			element->Render(hdc);
		}
	}
	void  Scene::AddGameObject( std::shared_ptr<GameObject> obj, const Enum::LayerType type)
	{
		_layers[static_cast<UINT>(type)]->AddGameObject(obj);
	}

	void Scene::OnEnter()
	{

	}
	void Scene::OnExit()
	{

	}
}
