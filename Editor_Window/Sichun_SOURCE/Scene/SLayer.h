#pragma once
#include"../Common/SEntity.h"
#include"../GameObject/GameObject.h"
namespace Sichun
{
	
	class Layer:public Entity
	{
	public:
		Layer();
		~Layer();
		 void Initialize();
		 void Update();
		 void LateUpdate();
		 void Render(HDC hdc);
		 void AddGameObject(std::shared_ptr<GameObject>obj);
	private:
		
		std::vector<std::shared_ptr<GameObject>>_objs;
	};
}

