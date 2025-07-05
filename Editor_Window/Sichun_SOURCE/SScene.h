#pragma once
#include"SEntity.h"
#include"GameObject.h"
#include"SLayer.h"
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

		virtual void  OnEnter();
		virtual void OnExit();
		void  AddGameObject(std::shared_ptr<GameObject> obj, Enum::LayerType type);
		std::shared_ptr<Layer>GetLayer(const Enum::LayerType type) 
		{
			return  _layers[static_cast<UINT>(type)];
		}
	private:
		
		//std::vector<std::shared_ptr<GameObject>>_objs;
		std::vector<std::shared_ptr<Layer>>_layers;
	};

}
