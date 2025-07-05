#include "SLayer.h"

namespace  Sichun
{
	Layer::Layer()
		: _objs{}
	{

	}
	Layer::~Layer()
	{

	}
	void Layer::Initialize()
	{
		for (std::shared_ptr<GameObject> element : _objs)
		{
			if (element == nullptr)continue;
			element->Initialize();
		}
	}
	void Layer::Update()
	{
		for (std::shared_ptr<GameObject> element : _objs)
		{
			if (element == nullptr)continue;
			element->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (std::shared_ptr<GameObject> element : _objs)
		{
			if (element == nullptr)continue;
			element->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		for (std::shared_ptr<GameObject> element : _objs)
		{
			if (element == nullptr)continue;
			element->Render(hdc);
		}
	}
	void Layer::AddGameObject(std::shared_ptr<GameObject>obj)
	{
		if (obj == nullptr)return;
		_objs.push_back(obj);
	}
}