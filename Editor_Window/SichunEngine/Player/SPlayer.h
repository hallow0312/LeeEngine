#pragma once
#include"../Sichun_SOURCE/GameObject/GameObject.h"
namespace Sichun
{
	class Player:public GameObject
	{
	public:
		Player();
		~Player();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Init();
	private:
		std::shared_ptr<GameObject>_leftYinYang;
		std::shared_ptr<GameObject>_rightYinYang;

	};
}
