#pragma once
#include"..\\Sichun_SOURCE\Resource\SResources.h"
#include"..\\Sichun_SOURCE\Component\STexture.h"

namespace Sichun
{
	void LoadResources()
	{
		Resources::Load<Graphics::Texture>(L"Reimu", L"..\\Resources\\Reimu\\Idle\\Reimu_Idle.png");
		Resources::Load<Graphics::Texture>(L"BackGround", L"..\\Resources\\BackGround\\BackGround.png");
	}
}



