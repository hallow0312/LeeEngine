#pragma once
#include"SEntity.h"
#include"GameObject.h"
namespace Sichun 
{
	class Scene: public Entity
	{
	public:
		Scene();
		~Scene();
		void virtual Initialize();
		void virtual Update();
		void virtual LateUpdate();
		void virtual Render(HDC hdc);

		void AddGameObject(shared_ptr<GameObject>obj);
	private:
		vector<shared_ptr<GameObject>>_objs;
	
	};

}
