#pragma once
#include"SScene.h"

namespace Sichun
{
	class SceneManager
	{
	public :
		template<typename T>
		static shared_ptr<Scene> CreateScene(const std::wstring& sceneName)
		{
			static_assert(std::is_base_of<Scene, T>::value, "T must be derived from Scene");

			shared_ptr<T> scene = std::make_shared<T>();
			scene->SetName(sceneName);
			scene->Initialize();

			_scenes.insert({ sceneName, scene });
			return scene;
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
