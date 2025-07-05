#pragma once

#include"../Sichun_SOURCE/SScene.h"


namespace Sichun
{
class TitleScene:public Scene
{
	using Base = Scene;
public:
	TitleScene();
	~TitleScene();

	void Initialize() override;
	void Update() override;
	void LateUpdate() override;
	void Render(HDC hdc)override;

private:

};

}
