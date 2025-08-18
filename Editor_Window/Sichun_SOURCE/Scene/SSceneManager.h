#pragma once
#include"SScene.h"

namespace Sichun
{
	class SceneManager
	{
	public :
		template<typename T>
		static std::shared_ptr<Scene> CreateScene(const std::wstring& sceneName)
		{
			static_assert(std::is_base_of<Scene, T>::value, "T must be derived from Scene");

			std::shared_ptr<T> scene = std::make_shared<T>();
			scene->SetName(sceneName);

			ActiveScene = scene;

			scene->Initialize();

			Scenes.insert({ sceneName, scene });
			return scene;
		}
		static std::shared_ptr<Scene>LoadScene(const std::wstring& name)
		{
			if (ActiveScene)
				ActiveScene->OnExit();

			std::map<std::wstring, std::shared_ptr<Scene>>::iterator iter = Scenes.find(name);
			 if (iter == Scenes.end()) return nullptr;

			 ActiveScene = iter->second;
			 if (ActiveScene)
			 ActiveScene->OnEnter();

			 return iter->second;
		}
		static std::shared_ptr<Scene>GetActiveScene(){return ActiveScene;}
		static std::shared_ptr<Scene>GetDontDestroyOnLoad() { return _DontDestroyOnLoad; }
		static std::vector<std::shared_ptr<GameObject>>GetGameObjects(Enum::LayerType type);

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Destroy();
	private:
		
		static std::shared_ptr<Scene> ActiveScene;
		static std::map<std::wstring, std::shared_ptr<Scene>>Scenes;
		static std::shared_ptr<Scene>_DontDestroyOnLoad;
	};

}
