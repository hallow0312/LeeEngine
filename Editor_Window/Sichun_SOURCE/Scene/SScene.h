#pragma once
#include"../Common/SEntity.h"
#include"../GameObject/GameObject.h"
#include"SLayer.h"


namespace Sichun 
{
	class Scene: public Entity
	{
	public:
		Scene();
		~Scene();
		
		virtual	void  Initialize();
		virtual	void  Update();
		virtual	void  LateUpdate();
		virtual	void  Render(HDC hdc);
		virtual void  Destroy();
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

	private:
	
	};

}
