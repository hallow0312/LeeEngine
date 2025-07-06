#pragma once
#include"..\\Sichun_SOURCE\Resource\SResources.h"
#include"..\\Sichun_SOURCE\Component\STexture.h"

namespace Sichun
{
	void LoadResources()
	{
		Resources::Load<Graphics::Texture>(L"Reimu", L"C:\\Users\\user\\Desktop\\2DGame\\LeeEngine\\Editor_Window\\Resources\\Reimu\\Idle\\Reimu_Idle.png");
		Resources::Load<Graphics::Texture>(L"BackGround", L"C:\\Users\\user\\Desktop\\2DGame\\LeeEngine\\Editor_Window\\Resources\\BackGround\\BackGround.png");
	}
}



