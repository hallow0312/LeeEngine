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
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		const  std::vector<std::shared_ptr<GameObject>>GetGameObjects() { return _objs; }
		void AddGameObject(std::shared_ptr<GameObject>obj);
		bool IsElementDisabled(std::shared_ptr<GameObject>obj);
	private:
		
		std::vector<std::shared_ptr<GameObject>>_objs;
	};
	typedef std::vector<std::shared_ptr<GameObject>>::iterator  GameObjectIter;
}

