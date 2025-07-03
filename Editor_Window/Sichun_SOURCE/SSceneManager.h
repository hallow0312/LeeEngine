#pragma once
#include"SScene.h"

namespace Sichun
{
	class SceneManager
	{
	public :
		template<typename T>
		static shared_ptr<Scene> CreateScene(const wstring& sceneName)
		{
			static_assert(std::is_base_of<Scene, T>::value, "T must be derived from Scene");

			shared_ptr<T> scene = std::make_shared<T>();
			scene->SetName(sceneName);
			scene->Initialize();

			_scenes.insert({ sceneName, scene });
			return scene;
		}
		static shared_ptr<Scene>LoadScene(const wstring& name)
		{
			 map<wstring,shared_ptr<Scene>>::iterator iter = _scenes.find(name);
			 if (iter == _scenes.end()) return nullptr;
			 _activeScene = iter->second;
			 return iter->second;
		}
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		
	private:
		
		static shared_ptr<Scene> _activeScene;
		static map<wstring, shared_ptr<Scene>>_scenes;
	};

}
