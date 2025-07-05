#pragma once
#include"../Sichun_SOURCE/SScene.h"

namespace Sichun
{
	class Player;
	class PlayScene :public Scene
	{
		using Base = Scene;
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc)override;

		void OnEnter() override;
		void OnExit() override;
	private:
		std::shared_ptr<Player> _player;
	};
}

