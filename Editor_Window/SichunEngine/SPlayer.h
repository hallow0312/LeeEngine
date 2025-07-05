#pragma once
#include"../Sichun_SOURCE/GameObject/GameObject.h"
namespace Sichun
{
	class Player:public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
